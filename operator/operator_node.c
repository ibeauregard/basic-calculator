#include "operator_node.h"
#include <stdlib.h>

static void delete(OperatorNode* self);

OperatorNode* new_operator_node(Operator* op)
{
    OperatorNode* self = malloc(sizeof (OperatorNode));
    self->op = op;
    self->next = NULL;

    self->delete = &delete;
    return self;
}

void delete(OperatorNode* self)
{
    free(self);
}
