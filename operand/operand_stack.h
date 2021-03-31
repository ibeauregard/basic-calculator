#ifndef OPERAND_STACK_H
#define OPERAND_STACK_H

#include "operand.h"

typedef struct s_operand_stack {
    Operand* top;

    void (*push)(struct s_operand_stack* self, int operand);
    int (*pop)(struct s_operand_stack* self);
    void (*delete)(struct s_operand_stack* self);
} OperandStack;

OperandStack* new_operand_stack();

#endif
