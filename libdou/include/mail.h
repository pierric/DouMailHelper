#ifndef MAIL_H
#define MAIL_H

#include <stdbool.h>
#include <libdou_global.h>
#include "service.h"

LIBDOUSHARED_EXPORT char* get_unread(pcontext, int start, int number);

LIBDOUSHARED_EXPORT char* get_inbox(pcontext, int start, int number);

LIBDOUSHARED_EXPORT char* get_outbox(pcontext, int start, int number);

LIBDOUSHARED_EXPORT char* get_mail(pcontext, int id);

LIBDOUSHARED_EXPORT bool put_mail(pcontext, const char *text, const char* captcha);

LIBDOUSHARED_EXPORT bool mark_read(pcontext, int id);

LIBDOUSHARED_EXPORT bool delete_mail(pcontext, int id);

LIBDOUSHARED_EXPORT bool mark_read_g(pcontext, int *ids, int number);

LIBDOUSHARED_EXPORT bool delete_mail_g(pcontext, int *ids, int number);

#endif // MAIL_H
