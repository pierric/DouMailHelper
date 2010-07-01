#ifndef MAIL_H
#define MAIL_H

#include <stdbool.h>
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

LIBDOUSHARED_EXPORT char* get_inbox(pcontext, int start, int number);

LIBDOUSHARED_EXPORT char* get_unread(pcontext, int number);

LIBDOUSHARED_EXPORT enum error_no last_error(void);

#endif // MAIL_H
