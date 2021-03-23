#ifndef TOKEN_NODE_H
#define TOKEN_NODE_H

#include "token.h"

typedef struct s_token_node {
    Token* token;
    struct s_token_node* next;

    void (*delete)(struct s_token_node* self);
} TokenNode;

TokenNode* new_token_node(Token* token);

#endif
