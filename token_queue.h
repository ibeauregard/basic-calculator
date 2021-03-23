#ifndef TOKEN_QUEUE_H
#define TOKEN_QUEUE_H

#include "token.h"
#include <stddef.h>

typedef struct s_token_queue {
    Token* head;
    Token* tail;
} TokenQueue;

#endif
