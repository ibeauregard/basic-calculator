#include "operator.h"
#include "binary_operator.h"
#include "unary_operator.h"
#include <stddef.h>

static int apply_unary_operator(UnaryOperator* operator, int operand);
static int apply_binary_operator(BinaryOperator* operator, int left, int right);

static BinaryOperator addition = {
        .symbol = '+',
        .precedence = 1,
        .func = &addition_func,
        .isUnary = false,
        .apply = &apply_binary_operator
};

static BinaryOperator subtraction = {
        .symbol = '-',
        .precedence = 1,
        .func = &subtraction_func,
        .isUnary = false,
        .apply = &apply_binary_operator
};

static BinaryOperator multiplication = {
        .symbol = '*',
        .precedence = 2,
        .func = &multiplication_func,
        .isUnary = false,
        .apply = &apply_binary_operator
};

static BinaryOperator division = {
        .symbol = '/',
        .precedence = 2,
        .func = &division_func,
        .isUnary = false,
        .apply = &apply_binary_operator
};

static BinaryOperator modulo = {
        .symbol = '%',
        .precedence = 2,
        .func = &modulo_func,
        .isUnary = false,
        .apply = &apply_binary_operator
};

static UnaryOperator minus = {
        .symbol = '&',
        .precedence = 3,
        .func = &minus_func,
        .isUnary = true,
        .apply = &apply_unary_operator
};

static Operator* operators[11] = {(Operator*) &modulo, // ascii 37
                                  (Operator*) &minus, // ascii 38
                                  NULL, // ...
                                  NULL,
                                  NULL,
                                  (Operator*) &multiplication,
                                  (Operator*) &addition,
                                  NULL,
                                  (Operator*) &subtraction,
                                  NULL,
                                  (Operator*) &division // ascii 47
};

static unsigned char get_operator_index(char symbol);

Operator* get_operator_from_symbol(char symbol)
{
    return operators[get_operator_index(symbol)];
}

inline unsigned char get_operator_index(char symbol)
{
    return symbol - '%';
}

int apply_unary_operator(UnaryOperator* operator, int operand)
{
    return operator->func(operand);
}

int apply_binary_operator(BinaryOperator* operator, int left, int right)
{
    return operator->func(left, right);
}
