#ifndef OPERAND_H
#define OPERAND_H

typedef struct s_operand {
    int value;
    struct s_operand* next;

    void (*delete)(struct s_operand* self);
} Operand;

Operand* new_operand(int value);

#endif
