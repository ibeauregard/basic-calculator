#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

#include "unary_operator_function.h"
#include <stdbool.h>

typedef struct s_unary_operator {
    char sign;
    unsigned char precedence;
    UnaryOperatorFunction* func;
    bool isUnary;

    int (*apply)(struct s_unary_operator* self, int operand);
} UnaryOperator;

#endif
