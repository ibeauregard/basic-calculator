#include "operator_stack.h"
#include <stdlib.h>

static void push(OperatorStack* self, Operator* op);
static Operator* pop(OperatorStack* self);
static Operator* peek(OperatorStack* self);
static bool is_empty(OperatorStack * self);
static void delete(OperatorStack* self);

OperatorStack* new_operator_stack()
{
    OperatorStack* self = malloc(sizeof (OperatorStack));
    self->top = NULL;

    self->push = &push;
    self->pop = &pop;
    self->peek = &peek;
    self->isEmpty = &is_empty;
    self->delete = &delete;
    return self;
}

void push(OperatorStack* self, Operator* op)
{
    OperatorNode* operator_node = new_operator_node(op);
    operator_node->next = self->top;
    self->top = operator_node;
}

Operator* pop(OperatorStack* self)
{
    Operator* popped = self->top->op;
    OperatorNode* new_top = self->top->next;
    self->top->delete(self->top);
    self->top = new_top;
    return popped;
}

inline Operator* peek(OperatorStack* self)
{
    return self->top->op;
}

bool is_empty(OperatorStack * self)
{
    return self->top == NULL;
}

void delete(OperatorStack* self)
{
    while (self->top) {
        OperatorNode* next = self->top->next;
        self->top->delete(self->top);
        self->top = next;
    }
    free(self);
}
