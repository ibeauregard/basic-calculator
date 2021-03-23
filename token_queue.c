#include "token_queue.h"
#include <stdlib.h>

static void enqueue(TokenQueue* self, char* token);
static Token* dequeue(TokenQueue* self);
static void delete(TokenQueue* self);

TokenQueue* new_token_queue()
{
    TokenQueue* self = malloc(sizeof (TokenQueue));
    self->head = self->tail = NULL;

    self->enqueue = &enqueue;
    self->dequeue = &dequeue;
    self->delete = &delete;
    return self;
}

static bool is_empty(TokenQueue* self);

void enqueue(TokenQueue* self, char* token)
{
    TokenNode* node = new_token_node(new_token(token));
    if (is_empty(self)) {
        self->head = self->tail = node;
    } else {
        self->tail = self->tail->next = node;
    }
}

Token* dequeue(TokenQueue* self)
{
    TokenNode* dequeued = self->head;
    if (!dequeued) return NULL;
    self->head = self->head->next;
    if (dequeued == self->tail) {
        self->tail = NULL;
    }
    Token* token = dequeued->token;
    dequeued->delete(dequeued);
    return token;
}

bool is_empty(TokenQueue* self)
{
    return !self->head;
}

void delete(TokenQueue* self)
{
    TokenNode* next;
    for (TokenNode* node = self->head; node; node = next) {
        next = node->next;
        node->delete(node);
    }
    free(self);
}
