#ifndef OPERAND_NODE_H
#define OPERAND_NODE_H

typedef struct s_operand {
    int value;
    struct s_operand* next;

    void (*delete)(struct s_operand* self);
} OperandNode;

OperandNode* new_operand_node(int value);

#endif
