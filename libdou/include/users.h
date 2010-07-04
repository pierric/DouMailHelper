#ifndef USERS_H
#define USERS_H

#include "libdou_global.h"
#include "service.h"

LIBDOUSHARED_EXPORT char* get_my_info(pcontext);

LIBDOUSHARED_EXPORT char* get_user_info(pcontext, int uid);

LIBDOUSHARED_EXPORT char* get_friends(pcontext, int uid);

LIBDOUSHARED_EXPORT char* get_contacts(pcontext, int uid);

LIBDOUSHARED_EXPORT char* search_users(pcontext, const char *query_word, int index, int number);

#endif // USERS_H
