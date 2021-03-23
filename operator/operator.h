#ifndef OPERATOR_H
#define OPERATOR_H

#include <stdbool.h>

typedef struct s_operator {
    char sign;
    unsigned char precedence;
    void* func;
    bool isUnary;

    void* apply;
} Operator;

Operator* get_operator_from_sign(char sign);

#endif
