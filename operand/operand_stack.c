#include "operand_stack.h"
#include <stdlib.h>

static void push(OperandStack* self, int operand);
static int pop(OperandStack* self);
static void delete(OperandStack* self);

OperandStack* new_operand_stack()
{
    OperandStack* self = malloc(sizeof (OperandStack));
    self->top = NULL;

    self->push = &push;
    self->pop = &pop;
    self->delete = &delete;
    return self;
}

void push(OperandStack* self, int operand)
{
    Operand* operand_node = new_operand_node(operand);
    operand_node->next = self->top;
    self->top = operand_node;
}

int pop(OperandStack* self)
{
    int popped = self->top->value;
    Operand* new_top = self->top->next;
    self->top->delete(self->top);
    self->top = new_top;
    return popped;
}

void delete(OperandStack* self)
{
    while (self->top) {
        Operand* next = self->top->next;
        self->top->delete(self->top);
        self->top = next;
    }
    free(self);
}
