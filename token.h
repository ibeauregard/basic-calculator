#ifndef TOKEN_H
#define TOKEN_H

#include "operator.h"
#include <stdbool.h>

typedef struct s_token {
    char* value;

    bool (*isOperator)(struct s_token* self);
    Operator* (*getOperator)(struct s_token* self);
    void (*delete)(struct s_token* self);
} Token;

Token* new_token(char* value);

#endif
