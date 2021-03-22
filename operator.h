#ifndef OPERATOR_H
#define OPERATOR_H

typedef int Operator(int left_operand, int right_operand);

int addition(int left, int right);
int subtraction(int left, int right);
int multiplication(int left, int right);
int division(int left, int right);
int modulo(int left, int right);

#endif
