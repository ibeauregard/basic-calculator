#include "rpn_eval.h"
#include "operand/operand_stack.h"
#include "my_libc/_atoi.h"

int rpn_eval(TokenQueue* tokens)
{
    OperandStack* operands = new_operand_stack();
    int result;
    for (Token* token = tokens->head; token; token = token->next) {
        if (token->isOperator(token)) {
            result = token->applyAsOperator(token, operands);
        } else {
            result = _atoi(token->value);
        }
        operands->push(operands, result);
    }
    result = operands->pop(operands);
    operands->delete(operands);
    return result;
}
