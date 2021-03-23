#include "token_node.h"
#include <stdlib.h>

static void delete(TokenNode* self);

TokenNode* new_token_node(Token* token)
{
    TokenNode* self = malloc(sizeof (TokenNode));
    self->token = token;
    self->next = NULL;

    self->delete = &delete;
    return self;
}

void delete(TokenNode* self)
{
    free(self);
}
