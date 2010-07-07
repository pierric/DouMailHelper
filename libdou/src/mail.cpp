#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mail.h"

static inline char* get_mail_list(pcontext c, const char* uri, int start, int number)
{
    if(!c)
    {
        set_error(Uninitialized);
        return NULL;
    }
    char qurl[128];
    sprintf(qurl, "%s?start-index=%d&max-results=%d",
            uri,
            start > 0 ? start : 1,
            number > 0 ? number : 10);
    return service_request_get(c, qurl);
}

char* get_unread(pcontext c, int start, int number)
{
    return get_mail_list(c, "http://api.douban.com/doumail/inbox/unread", start, number);
}

char* get_inbox(pcontext c, int start, int number)
{
    return get_mail_list(c, "http://api.douban.com/doumail/inbox", start, number );
}

char* get_outbox(pcontext c, int start, int number)
{
    return get_mail_list(c, "http://api.douban.com/doumail/outbox", start, number);
}
