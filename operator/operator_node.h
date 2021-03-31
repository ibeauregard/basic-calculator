#ifndef OPERATOR_NODE_H
#define OPERATOR_NODE_H

#include "operator.h"

typedef struct s_operator_node {
    Operator* op;
    struct s_operator_node* next;

    void (*delete)(struct s_operator_node* self);
} OperatorNode;

OperatorNode* new_operator_node(Operator* op);

#endif
