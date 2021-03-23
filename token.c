#include "token.h"
#include <stdlib.h>

static Operator* operators[11] = {&modulo, // ascii 37
                                  NULL, // ascii 38
                                  NULL, // ...
                                  NULL,
                                  NULL,
                                  &multiplication,
                                  &addition,
                                  NULL,
                                  &subtraction,
                                  NULL,
                                  &division}; // ascii 47

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

static int get_operator_index(char symbol);

Operator* get_operator(Token* self)
{
    return operators[get_operator_index(self->value[0])];
}

inline int get_operator_index(char symbol)
{
    return symbol - '%';
}

void delete(Token* self)
{
    free(self->value);
    free(self);
}
