#ifndef PARSER_H
#define PARSER_H

#include "token_queue.h"
#include "operator/operator_stack.h"

typedef struct s_parser {
    char* input;
    int token_start;
    int token_end;
    char* previous_token;
    int status;
    OperatorStack* operator_stack;
    TokenQueue* tokens;

    TokenQueue* (*parse)(struct s_parser* self);
} Parser;

Parser create_parser(char* input);

#endif
