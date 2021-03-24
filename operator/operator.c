#include "operator.h"
#include "binary_operator.h"
#include "unary_operator.h"
#include "signs.h"
#include <stddef.h>

static Operator addition = {
        .sign = ADD_SIGN,
        .precedence = 1,
        .apply = &addition_func,
        .isUnary = false
};

static Operator subtraction = {
        .sign = SUB_SIGN,
        .precedence = 1,
        .apply = &subtraction_func,
        .isUnary = false
};

static Operator multiplication = {
        .sign = MUL_SIGN,
        .precedence = 2,
        .apply = &multiplication_func,
        .isUnary = false
};

static Operator division = {
        .sign = DIV_SIGN,
        .precedence = 2,
        .apply = &division_func,
        .isUnary = false
};

static Operator modulo = {
        .sign = MOD_SIGN,
        .precedence = 2,
        .apply = &modulo_func,
        .isUnary = false
};

static Operator minus = {
        .sign = MINUS_SIGN,
        .precedence = 3,
        .apply = &minus_func,
        .isUnary = true
};

static Operator left_parenthesis = {
        .sign = LEFT_PAREN
};

static Operator right_parenthesis = {
        .sign = RIGHT_PAREN
};

static Operator* operators[] = {&modulo, // ascii 37
                                  &minus, // ascii 38
                                  NULL, // ...
                                  &left_parenthesis,
                                  &right_parenthesis,
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

inline bool char_is_operator(char c)
{
    return (c == ADD_SIGN
            || c == SUB_SIGN
            || c == MUL_SIGN
            || c == DIV_SIGN
            || c == MOD_SIGN
            || c == MINUS_SIGN);
}
