#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include "binary_operator_function.h"
#include <stdbool.h>

typedef struct s_binary_operator {
    char sign;
    unsigned char precedence;
    BinaryOperatorFunction* apply;
    bool isUnary;
} BinaryOperator;

#endif
