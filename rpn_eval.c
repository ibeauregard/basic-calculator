#include "rpn_eval.h"
#include "operand/operand_stack.h"
#include "my_libc/_atoi.h"

int rpn_eval(TokenArray* tokens)
{
    OperandStack* operands = new_operand_stack();
    int result;
    for (size_t i = 0; i < tokens->size; i++) {
        if (tokens->array[i]->isOperator(tokens->array[i])) {
            result = tokens->array[i]->applyAsOperator(tokens->array[i], operands);
        } else {
            result = _atoi(tokens->array[i]->value);
        }
        operands->push(operands, result);
    }
    result = operands->pop(operands);
    operands->delete(operands);
    return result;
}
