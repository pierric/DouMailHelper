#ifndef HTTP_H
#define HTTP_H

#include <libdou_global.h>

struct context;
typedef struct context *pcontext;

enum error_no
{
    NoError,
    Uninitialized,
    Unauthorized,
    NetworkFailure,
};

LIBDOUSHARED_EXPORT pcontext initialize(const char* consumer_key, const char* consumer_secret);

LIBDOUSHARED_EXPORT char* get_authorize_uri(pcontext, char*);

LIBDOUSHARED_EXPORT bool authorize(pcontext);

LIBDOUSHARED_EXPORT void cleanup(pcontext);

LIBDOUSHARED_EXPORT int get_user_id(pcontext);

LIBDOUSHARED_EXPORT enum error_no last_error(void);

char* service_request_get(pcontext, const char *uri);
void set_error(enum error_no err);

#endif // HTTP_H
