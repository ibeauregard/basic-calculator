#ifndef BINARY_OPERATOR_FUNCTION_H
#define BINARY_OPERATOR_FUNCTION_H

typedef int BinaryOperatorFunction(int left, int right);

int addition_func(int left, int right);
int subtraction_func(int left, int right);
int multiplication_func(int left, int right);
int division_func(int left, int right);
int modulo_func(int left, int right);

#endif
