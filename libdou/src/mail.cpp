#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern "C" {
    #include <oauth.h>
}
#include "mail.h"

static const char *request_token_uri = "http://www.douban.com/service/auth/request_token";
static const char *access_token_uri  = "http://www.douban.com/service/auth/access_token";
static enum error_no error = NoError;

static int parse_reply(const char *, char **, char **);

struct context
{
    char *consumer_key;
    char *consumer_secret;
    char *request_key;
    char *request_secret;
    char *access_key;
    char *access_secret;
};

pcontext initialize(const char *consumer_key, const char *consumer_secret)
{
    char *req_url, *reply;
    req_url = oauth_sign_url2(request_token_uri, NULL, OA_HMAC, NULL, consumer_key, consumer_secret, NULL, NULL);
    if(req_url)
    {
        reply = oauth_http_get(req_url, NULL);
        if(reply)
        {
            fprintf(stderr, "parse reply:%s\n", reply);
	    char *req_key, *req_sec;
            if (parse_reply(reply, &req_key, &req_sec))
            {
                free(reply);
                free(req_url);
		pcontext c = (struct context *)malloc(sizeof(struct context));
		c->consumer_key = strdup(consumer_key);
		c->consumer_secret = strdup(consumer_secret);
		c->request_key = req_key;
		c->request_secret = req_sec;
                return c;
            }
            free(reply);
        }
        free(req_url);
    }
    error = Uninitialized;
    return NULL;
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
            if(parse_reply(reply, &c->access_key, &c->access_secret))
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

char* get_inbox(pcontext c, int start, int number)
{
    if(!c)
    {
        error = Uninitialized;
        return NULL;
    }
    char *req_url;
    const char *inbox_uri = "http://api.douban.com/doumail/inbox?start-index=1&max-results=10";
    req_url = oauth_sign_url2(inbox_uri, NULL, OA_HMAC, NULL,
                              c->consumer_key, c->consumer_secret,
                              c->access_key, c->access_secret);
    return oauth_http_get(req_url, NULL);
}

enum error_no last_error()
{
    return error;
}

int parse_reply(const char *reply, char **token, char **secret)
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
    }
    if(rv) free(rv);
    return ok;
}
