#include "rpn_eval.h"
#include "operand_stack.h"
#include "my_libc/_atoi.h"

int rpn_eval(TokenArray* tokens)
{
    OperandStack* operands = new_operand_stack();
    int left, right;
    for (size_t i = 0; i < tokens->size; i++) {
        if (tokens->array[i]->isOperator(tokens->array[i])) {
            right = operands->pop(operands);
            left = operands->pop(operands);
            operands->push(operands, tokens->array[i]->getOperator(tokens->array[i])(left, right));
        } else {
            operands->push(operands, _atoi(tokens->array[i]->value));
        }
    }
    int result = operands->pop(operands);
    operands->delete(operands);
    return result;
}
