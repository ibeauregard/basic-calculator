#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include "binary_operator_function.h"
#include <stdbool.h>

typedef struct s_binary_operator {
    char symbol;
    unsigned char precedence;
    BinaryOperatorFunction* func;
    bool isUnary;

    int (*apply)(struct s_binary_operator* self, int left_operand, int right_operand);
} BinaryOperator;

#endif
