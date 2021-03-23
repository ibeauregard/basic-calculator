#include "operator.h"
#include "binary_operator.h"
#include "unary_operator.h"
#include "signs.h"
#include <stddef.h>

static int apply_unary_operator(UnaryOperator* operator, int operand);
static int apply_binary_operator(BinaryOperator* operator, int left, int right);

static Operator addition = {
        .sign = ADD_SIGN,
        .precedence = 1,
        .func = (void*) &addition_func,
        .isUnary = false,
        .apply = (void*) &apply_binary_operator
};

static Operator subtraction = {
        .sign = MINUS_SIGN,
        .precedence = 1,
        .func = (void*) &subtraction_func,
        .isUnary = false,
        .apply = (void*) &apply_binary_operator
};

static Operator multiplication = {
        .sign = MUL_SIGN,
        .precedence = 2,
        .func = (void*) &multiplication_func,
        .isUnary = false,
        .apply = (void*) &apply_binary_operator
};

static Operator division = {
        .sign = DIV_SIGN,
        .precedence = 2,
        .func = (void*) &division_func,
        .isUnary = false,
        .apply = (void*) &apply_binary_operator
};

static Operator modulo = {
        .sign = MOD_SIGN,
        .precedence = 2,
        .func = (void*) &modulo_func,
        .isUnary = false,
        .apply = (void*) &apply_binary_operator
};

static Operator minus = {
        .sign = MINUS_SIGN,
        .precedence = 3,
        .func = (void*) &minus_func,
        .isUnary = true,
        .apply = (void*) &apply_unary_operator
};

static Operator* operators[] = {&modulo, // ascii 37
                                  &minus, // ascii 38
                                  NULL, // ...
                                  NULL,
                                  NULL,
                                  &multiplication,
                                  &addition,
                                  NULL,
                                  &subtraction,
                                  NULL,
                                  &division // ascii 47
};

static unsigned char get_operator_index(char sign);

Operator* get_operator_from_sign(char sign)
{
    return operators[get_operator_index(sign)];
}

inline unsigned char get_operator_index(char sign)
{
    return sign - MOD_SIGN;
}

int apply_unary_operator(UnaryOperator* operator, int operand)
{
    return operator->func(operand);
}

int apply_binary_operator(BinaryOperator* operator, int left, int right)
{
    return operator->func(left, right);
}

bool token_is_operator(char token)
{
    return (token == ADD_SIGN
            || token == SUB_SIGN
            || token == MUL_SIGN
            || token == DIV_SIGN
            || token == MOD_SIGN
            || token == MINUS_SIGN);
}
