#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "service.h"
extern "C" {
    #include <oauth.h>
}

struct context
{
    char *consumer_key;
    char *consumer_secret;
    char *request_key;
    char *request_secret;
    char *access_key;
    char *access_secret;
    int user_id;
};

static const char *request_token_uri = "http://www.douban.com/service/auth/request_token";
static const char *access_token_uri  = "http://www.douban.com/service/auth/access_token";
static enum error_no error = NoError;

static int parse_reply(const char *, char **, char **, int *uid);

pcontext initialize(const char *consumer_key, const char *consumer_secret)
{
    char *req_url, *reply;
    req_url = oauth_sign_url2(request_token_uri, NULL, OA_HMAC, NULL, consumer_key, consumer_secret, NULL, NULL);
    if(req_url)
    {
        reply = oauth_http_get(req_url, NULL);
        if(reply)
        {
            char *req_key, *req_sec;
            if (parse_reply(reply, &req_key, &req_sec, NULL))
            {
                free(reply);
                free(req_url);
                pcontext c = (struct context *)malloc(sizeof(struct context));
                c->consumer_key = strdup(consumer_key);
                c->consumer_secret = strdup(consumer_secret);
                c->request_key = req_key;
                c->request_secret = req_sec;
                c->access_key = c->access_secret = NULL;
                return c;
            }
            free(reply);
        }
        free(req_url);
    }
    error = Uninitialized;
    return NULL;
}

pcontext initialize2(const char *consumer_key, const char *consumer_secret,
                     const char *access_key, const char *access_secret,
                     int uid)
{
    pcontext c = (struct context *)malloc(sizeof(struct context));
    c->consumer_key = strdup(consumer_key);
    c->consumer_secret = strdup(consumer_secret);
    c->request_key = c->request_secret = NULL;
    c->access_key = strdup(access_key);
    c->access_secret = strdup(access_secret);
    c->user_id = uid;
    return c;
}

void cleanup(pcontext c)
{
    if(!c) return;
    if(c->consumer_key)    free(c->consumer_key);
    if(c->consumer_secret) free(c->consumer_secret);
    if(c->request_key)     free(c->request_key);
    if(c->request_secret)  free(c->request_secret);
    if(c->access_key)      free(c->access_key);
    if(c->access_secret)   free(c->access_secret);
    free(c);
}

char* get_authorize_uri(pcontext c, char* uri)
{
    if(!c)
    {
        error = Uninitialized;
        return NULL;
    }
    sprintf(uri, "http://www.douban.com/service/auth/authorize?oauth_token=%s", c->request_key);
    return uri;
}

const char* get_access_key(pcontext c)
{
    return c->access_key;
}

const char* get_access_secret(pcontext c)
{
    return c->access_secret;
}

bool authorize(pcontext c)
{
    if(!c)
    {
        error = Uninitialized;
        return false;
    }
    char *req_url, *reply;
    req_url = oauth_sign_url2(access_token_uri, NULL, OA_HMAC, NULL,
                              c->consumer_key, c->consumer_secret,
                              c->request_key,  c->request_secret);
    if(req_url)
    {
        reply = oauth_http_get(req_url, NULL);
        if(reply)
        {
            if(parse_reply(reply, &c->access_key, &c->access_secret, &c->user_id))
            {
                free(reply);
                free(req_url);
                return true;
            }
            free(reply);
        }
        free(req_url);
    }
    error = Unauthorized;
    return false;
}

int get_user_id(pcontext c)
{
    if(!c)
    {
        error = Uninitialized;
        return 0;
    }
    return c->user_id;
}

enum error_no last_error()
{
    return error;
}

char* service_request_get(pcontext c, const char* uri)
{
    char *req_url;
    req_url = oauth_sign_url2(uri, NULL, OA_HMAC, NULL,
                              c->consumer_key, c->consumer_secret,
                              c->access_key, c->access_secret);
    if(req_url)
    {
        char *reply = oauth_http_get(req_url, NULL);
        free(req_url);
        return reply;
    }
    return NULL;
}

void set_error(enum error_no err)
{
    error = err;
}

int parse_reply(const char *reply, char **token, char **secret, int *uid)
{
    int cnt, rc, ok=0;
    char **rv = NULL;
    rc = oauth_split_url_parameters(reply, &rv);
    for(cnt=0;cnt<rc;cnt++)
    {
        if(token  && !strncmp(rv[cnt], "oauth_token", 11))
        {
            *token  = strdup(&(rv[cnt][12]));
            ok++;
        }
        if(secret && !strncmp(rv[cnt], "oauth_token_secret=", 18))
        {
            *secret = strdup(&(rv[cnt][19]));
            ok++;
        }
        if(uid && !strncmp(rv[cnt], "douban_user_id", 14))
        {
            sscanf(&(rv[cnt][15]), "%d", uid);
        }
    }
    if(rv) free(rv);
    return ok;
}
