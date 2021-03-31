#ifndef OPERATOR_H
#define OPERATOR_H

#include <stdbool.h>

typedef struct s_operator {
    char sign;
    unsigned char precedence;
    void* apply;
    bool isUnary;
} Operator;

Operator* get_operator_from_sign(char sign);
bool char_is_operator(char token);

#endif
