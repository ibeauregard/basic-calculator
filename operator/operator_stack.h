#ifndef OPERATOR_STACK_H
#define OPERATOR_STACK_H

#include "operator_node.h"

typedef struct s_operator_stack {
    OperatorNode* top;

    void (*push)(struct s_operator_stack* self, Operator* op);
    Operator* (*pop)(struct s_operator_stack* self);
    Operator* (*peek)(struct s_operator_stack* self);
    bool (*isEmpty)(struct s_operator_stack* self);
    void (*delete)(struct s_operator_stack* self);
} OperatorStack;

OperatorStack* new_operator_stack();

#endif
