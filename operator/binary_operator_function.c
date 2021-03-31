#include "binary_operator_function.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int addition_func(int left, int right, int* error)
{
    *error = EXIT_SUCCESS;
    return left + right;
}

int subtraction_func(int left, int right, int* error)
{
    *error = EXIT_SUCCESS;
    return left - right;
}

int multiplication_func(int left, int right, int* error)
{
    *error = EXIT_SUCCESS;
    return left * right;
}

int division_func(int left, int right, int* error)
{
    if (right == 0) {
        dprintf(STDERR_FILENO, "%s\n", "Runtime error: Divide by zero");
        *error = EXIT_FAILURE;
        return 0;
    }
    return left / right;
}

int modulo_func(int left, int right, int* error)
{
    if (right == 0) {
        dprintf(STDERR_FILENO, "%s\n", "Runtime error: Modulo by zero");
        *error = EXIT_FAILURE;
        return 0;
    }
    return left % right;
}
