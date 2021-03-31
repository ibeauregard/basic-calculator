#include "evaluator.h"
#include "operand/operand_stack.h"
#include "my_libc/_atoi.h"

/***
 * @param tokens: A data structure holding the tokens in reverse-polish notation order
 *                  (see https://en.wikipedia.org/wiki/Reverse_Polish_notation)
 * @return The value of the expression represented by the input parameter
 */
int eval(TokenQueue* tokens, int* error)
{
    OperandStack* operands = new_operand_stack();
    int result;
    for (Token* token = tokens->dequeue(tokens); token; token = tokens->dequeue(tokens)) {
        if (token->isOperator(token)) {
            result = token->applyAsOperator(token, operands, error);
        } else {
            result = _atoi(token->value);
        }
        operands->push(operands, result);
        token->delete(token);
    }
    result = operands->pop(operands);
    operands->delete(operands);
    return result;
}
