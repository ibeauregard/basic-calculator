#ifndef OPERAND_STACK_H
#define OPERAND_STACK_H

typedef struct s_operand_stack {
    int* top;

    void (*push)(struct s_operand_stack* self, int operand);
    int (*pop)(struct s_operand_stack* self);
    void (*delete)(struct s_operand_stack* self);
} OperandStack;

OperandStack* new_operand_stack();

#endif
