#include "operand.h"
#include <stdlib.h>

static void delete(Operand* self);

Operand* new_operand_node(int value)
{
    Operand* self = malloc(sizeof (Operand));
    self->value = value;
    self->next = NULL;

    self->delete = &delete;
    return self;
}

void delete(Operand* self)
{
    free(self);
}
