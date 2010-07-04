#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "service.h"

char* get_my_info(pcontext c)
{
    return service_request_get(c, "http://api.douban.com/people/@me");
}

char* get_user_info(pcontext c, int uid)
{
    char uri[512];
    sprintf(uri, "http://api.douban.com/people/%d", uid);
    return service_request_get(c, uri);
}

char* get_friends(pcontext c, int uid)
{
    char uri[512];
    sprintf(uri, "http://api.douban.com/people/%d/friends", uid);
    return service_request_get(c, uri);
}

char* get_contacts(pcontext c, int uid)
{
    char uri[512];
    sprintf(uri, "http://api.douban.com/people/%d/contacts", uid);
    return service_request_get(c, uri);
}

char* search_users(pcontext c, const char *query_word, int index, int number)
{
    char *uri = (char*)malloc(strlen(query_word)+320);
    if(uri)
    {
        index = index > 0 ? index : 1;
        number = number > 0 ? number : 10;
        sprintf(uri, "http://api.douban.com/people?q=%s&start-index=%d&max-results=%d", query_word, index, number);
        char *reply = service_request_get(c, uri);
        free(uri);
        return reply;
    }
    return NULL;
}
