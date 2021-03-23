#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

#include "unary_operator_function.h"
#include <stdbool.h>

typedef struct s_unary_operator {
    char sign;
    unsigned char precedence;
    UnaryOperatorFunction* apply;
    bool isUnary;
} UnaryOperator;

#endif
