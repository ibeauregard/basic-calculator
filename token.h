#ifndef TOKEN_H
#define TOKEN_H

#include "operator/operator.h"
#include "operand/operand_stack.h"
#include <stdbool.h>

typedef struct s_token {
    char* value;
    struct s_token* next;

    bool (*isOperator)(struct s_token* self);
    int (*applyAsOperator)(struct s_token* self, OperandStack* operands);
    void (*delete)(struct s_token* self);
} Token;

#endif
