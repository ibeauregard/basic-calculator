#ifndef BINARY_OPERATOR_FUNCTION_H
#define BINARY_OPERATOR_FUNCTION_H

typedef int BinaryOperatorFunction(int left, int right, int* error);

int addition_func(int left, int right, int* error);
int subtraction_func(int left, int right, int* error);
int multiplication_func(int left, int right, int* error);
int division_func(int left, int right, int* error);
int modulo_func(int left, int right, int* error);

#endif
