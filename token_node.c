#include "token_node.h"
#include <stdlib.h>

Token* new_token(char* value);
static void delete(TokenNode* self);

TokenNode* new_token_node(char* token)
{
    TokenNode* self = malloc(sizeof (TokenNode));
    self->token = new_token(token);
    self->next = NULL;

    self->delete = &delete;
    return self;
}

void delete(TokenNode* self)
{
    free(self);
}
