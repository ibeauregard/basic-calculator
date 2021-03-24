#include "parser.h"
#include "my_libc/_string.h"
#include "operator/signs.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define ASCII_SPACE 32

static TokenQueue* parse(Parser* self);

Parser create_parser(char* input)
{
    return (Parser) {
      .input = input,
      .token_start = 0,
      .token_end = 0,
      .previous_token = NULL,
      .status = EXIT_SUCCESS,
      .operator_stack = new_operator_stack(),
      .tokens = new_token_queue(),
      .parse = &parse
    };
}

static char* read_token(Parser* self);
static bool token_is_operand(char* token);
static void handle_operand(Parser* self, char* token);
static bool token_is_operator(char* token);
static char translate_operator_sign(Parser* self, char sign);
static void handle_operator(Parser* self, char sign);
static void handle_right_parenthesis(Parser* self);
static void empty_operator_stack(Parser* self);
static void clean(Parser* self);

TokenQueue* parse(Parser* self)
{
    char* token;
    while (!self->status && (token = read_token(self))) {
        if (token_is_operand(token)) {
            handle_operand(self, token);
        } else if (token_is_operator(token)) {
            handle_operator(self, translate_operator_sign(self, token[0]));
        } else if (token[0] == LEFT_PAREN) {
            self->operator_stack->push(self->operator_stack, get_operator_from_sign(LEFT_PAREN));
        } else { // token is a right parenthesis
            handle_right_parenthesis(self);
        }
        if (self->previous_token) free(self->previous_token);
        self->previous_token = token;
    }
    if (!self->status && token_is_operator(self->previous_token)) {
        dprintf(STDERR_FILENO, "Parse error: Operator %c missing right operand\n", self->previous_token[0]);
        self->status = EXIT_FAILURE;
    }
    if (!self->status) empty_operator_stack(self);
    clean(self);
    return self->tokens;
}

static void discard_one_char(Parser* self);
static bool char_is_digit(char c);
static char* generate_operand_token(Parser* self);
static char* generate_single_char_token(Parser* self);

char* read_token(Parser* self)
{
    if (!self->input[self->token_end]) return NULL;
    while (self->input[self->token_end] == ASCII_SPACE) {
        discard_one_char(self);
    }
    while (char_is_digit(self->input[self->token_end])) {
        self->token_end++;
    }
    if (self->token_start != self->token_end) {
        return generate_operand_token(self);
    } else {
        return generate_single_char_token(self);
    }
}

void discard_one_char(Parser* self)
{
    self->token_start++;
    self->token_end++;
}

inline bool char_is_digit(char c)
{
    return '0' <= c && c <= '9';
}

char* generate_operand_token(Parser* self)
{
    int length = self->token_end - self->token_start;
    char* operand = malloc(length + 1);
    _strncpy(operand, &self->input[self->token_start], length);
    operand[length] = 0;
    self->token_start = self->token_end;
    return operand;
}

static bool char_is_invalid(char c);

char* generate_single_char_token(Parser* self)
{
    char current = self->input[self->token_end];
    if (char_is_invalid(current)) {
        dprintf(STDERR_FILENO, "Parse error: Invalid token: %c <ascii %d>\n", current, current);
        self->status = EXIT_FAILURE;
        return NULL;
    }
    char* token = malloc(2);
    token[0] = current; token[1] = 0;
    self->token_start++;
    self->token_end++;
    return token;
}

static bool char_is_parenthesis(char c);

inline bool char_is_invalid(char c)
{
    return c == MINUS_SIGN || (!char_is_operator(c) && !char_is_parenthesis(c));
}

inline bool char_is_parenthesis(char c)
{
    return c == LEFT_PAREN || c == RIGHT_PAREN;
}

inline bool token_is_operand(char* token)
{
    return token && char_is_digit(token[0]);
}

void handle_operand(Parser* self, char* token)
{
    if (token_is_operand(self->previous_token)) {
        dprintf(STDERR_FILENO, "Parse error: Two consecutive operands: %s and %s\n", self->previous_token, token);
        self->status = EXIT_FAILURE;
        return;
    }
    self->tokens->enqueue(self->tokens, token);
}

inline bool token_is_operator(char* token)
{
    return token && char_is_operator(token[0]);
}

static bool token_is_closing_parenthesis(char* token);

char translate_operator_sign(Parser* self, char sign)
{
    if (sign != '-') return sign;
    if (token_is_operand(self->previous_token) || token_is_closing_parenthesis(self->previous_token)) {
        return SUB_SIGN;
    } else {
        return MINUS_SIGN;
    }
}

inline bool token_is_closing_parenthesis(char* token)
{
    return token && token[0] == RIGHT_PAREN;
}

static void pop_operator_stack_onto_output_queue(Parser* self);

void handle_operator(Parser* self, char sign)
{
    if (sign != MINUS_SIGN
            && !token_is_operand(self->previous_token)
            && !token_is_closing_parenthesis(self->previous_token)) {
        dprintf(STDERR_FILENO, "Parse error: Operator %c missing left operand\n", sign);
        self->status = EXIT_FAILURE;
        return;
    }
    Operator* current_operator = get_operator_from_sign(sign);
    if (current_operator->sign != MINUS_SIGN) {
        while (!self->operator_stack->isEmpty(self->operator_stack)
               && self->operator_stack->peek(self->operator_stack)->sign != LEFT_PAREN
               && self->operator_stack->peek(self->operator_stack)->precedence >= current_operator->precedence) {
            pop_operator_stack_onto_output_queue(self);
        }
    }
    self->operator_stack->push(self->operator_stack, current_operator);
}

inline void pop_operator_stack_onto_output_queue(Parser* self)
{
    self->tokens->enqueue(self->tokens, (char []) {self->operator_stack->pop(self->operator_stack)->sign, 0});
}

void handle_right_parenthesis(Parser* self)
{
    if (token_is_operator(self->previous_token)) {
        dprintf(STDERR_FILENO, "Parse error: Operator %c missing right operand\n", self->previous_token[0]);
        self->status = EXIT_FAILURE;
        return;
    }
    while (!self->operator_stack->isEmpty(self->operator_stack)
            && self->operator_stack->peek(self->operator_stack)->sign != LEFT_PAREN) {
        pop_operator_stack_onto_output_queue(self);
    }
    if (!self->operator_stack->isEmpty(self->operator_stack)) {
        self->operator_stack->pop(self->operator_stack);
    } else {
        dprintf(STDERR_FILENO, "%s\n", "Parse error: Mismatched closing parenthesis");
        self->status = EXIT_FAILURE;
    }
}

void empty_operator_stack(Parser* self)
{
    while (!self->operator_stack->isEmpty(self->operator_stack)) {
        if (self->operator_stack->peek(self->operator_stack)->sign == LEFT_PAREN) {
            dprintf(STDERR_FILENO, "%s\n", "Parse error: Mismatched opening parenthesis");
            self->status = EXIT_FAILURE;
            return;
        }
        pop_operator_stack_onto_output_queue(self);
    }
}

void clean(Parser* self)
{
    if (self->previous_token) free(self->previous_token);
    self->operator_stack->delete(self->operator_stack);
    if (self->status) {
        for (Token* token = self->tokens->dequeue(self->tokens); token; token = self->tokens->dequeue(self->tokens)) {
            token->delete(token);
        }
        self->tokens->delete(self->tokens);
    }
}
