#ifndef TOKEN_ARRAY_H
#define TOKEN_ARRAY_H

#include "token.h"
#include <stddef.h>

typedef struct s_token_array {
    Token** array;
    size_t size;
} TokenArray;

#endif
