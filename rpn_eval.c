#include "rpn_eval.h"
#include "operand_stack.h"
#include "my_libc/my_atoi.h"
#include <stdio.h>

void rpn_eval(TokenArray* tokens)
{
    OperandStack* operands = new_operand_stack();
    int left, right;
    for (size_t i = 0; i < tokens->size; i++) {
        if (tokens->array[i]->isOperator(tokens->array[i])) {
            right = operands->pop(operands);
            left = operands->pop(operands);
            operands->push(operands, tokens->array[i]->getOperator(tokens->array[i])(left, right));
        } else {
            int operand = atoi(tokens->array[i]->value);
            operands->push(operands, operand);
        }
    }
    printf("%d\n", operands->pop(operands));
    operands->delete(operands);
}
