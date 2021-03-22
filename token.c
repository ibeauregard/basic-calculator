#include "token.h"
#include <stdlib.h>


static bool is_operator(Token* self);
static Operator* get_operator(Token* self);
static void delete(Token* self);

Token* new_token(char* value)
{
    Token* self = malloc(sizeof (Token));
    self->value = value;

    self->isOperator = &is_operator;
    self->getOperator = &get_operator;
    self->delete  = &delete;
    return self;
}


bool is_operator(Token* self)
{
    return (self->value[0] == '+'
            || self->value[0] == '-'
            || self->value[0] == '*'
            || self->value[0] == '/'
            || self->value[0] == '%');
}

Operator* get_operator(Token* self)
{
    if (self->value[0] == '+') {
        return &addition;
    } else if (self->value[0] == '-') {
        return &subtraction;
    } else if (self->value[0] == '*') {
        return &multiplication;
    } else if (self->value[0] == '/') {
        return &division;
    } else { // the token represents the modulo operator
        return &modulo;
    }
}

void delete(Token* self)
{
    free(self->value);
    free(self);
}
