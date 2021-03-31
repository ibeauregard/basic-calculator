#ifndef TOKEN_QUEUE_H
#define TOKEN_QUEUE_H

#include "token_node.h"
#include <stddef.h>

typedef struct s_token_queue {
    TokenNode* head;
    TokenNode* tail;

    void (*enqueue)(struct s_token_queue* self, char* token);
    Token* (*dequeue)(struct s_token_queue* self);
    bool (*isEmpty)(struct s_token_queue* self);
    void (*delete)(struct s_token_queue* self);
} TokenQueue;

TokenQueue* new_token_queue();

#endif
