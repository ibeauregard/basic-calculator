#include "operand_node.h"
#include <stdlib.h>

static void delete(OperandNode* self);

OperandNode* new_operand_node(int value)
{
    OperandNode* self = malloc(sizeof (OperandNode));
    self->value = value;
    self->next = NULL;

    self->delete = &delete;
    return self;
}

void delete(OperandNode* self)
{
    free(self);
}
