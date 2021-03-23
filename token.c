#include "token.h"
#include "operator/unary_operator.h"
#include "operator/binary_operator.h"
#include <stdlib.h>

static bool is_operator(Token* self);
static int apply_as_operator(Token* self, OperandStack* operands);
static void delete(Token* self);

Token* new_token(char* value)
{
    Token* self = malloc(sizeof (Token));
    self->value = value;

    self->isOperator = &is_operator;
    self->applyAsOperator = &apply_as_operator;
    self->delete  = &delete;
    return self;
}

bool is_operator(Token* self)
{
    return token_is_operator(self->value[0]);
}

int apply_as_operator(Token* self, OperandStack* operands)
{
    Operator* operator = get_operator_from_sign(self->value[0]);
    if (operator->isUnary) {
        UnaryOperator* unary_operator = (UnaryOperator*) operator;
        return unary_operator->apply(unary_operator, operands->pop(operands));
    } else {
        BinaryOperator* binary_operator = (BinaryOperator*) operator;
        int right = operands->pop(operands);
        int left = operands->pop(operands);
        return binary_operator->apply(binary_operator, left, right);
    }
}

void delete(Token* self)
{
    free(self->value);
    free(self);
}
