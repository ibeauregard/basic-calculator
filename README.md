# my_bc

## Synopsis

`my_bc "<mathematical expression>"`

Example: `my_bc "1 + 2 * (3 - 42) % 5"`

## Description

A valid expression:

- must only contain the operators `+`, `-`, `*`, `/`, and `%`
- must only have integer values
- can contain parentheses, but each group must be properly closed
- can contain spaces

This program uses whole number arithmetic: divisions are euclidean, keeping only the quotient, while the remainder can be obtained with a modulo operation.

## Implementation notes

The program first parses the expression using the [shunting-yard algorithm](https://en.wikipedia.org/wiki/Shunting-yard_algorithm), outputting a data structure containing the tokens of the expression in [reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) order. 

Syntax errors are caught during parsing. If there are any, the program produces no output.

Once the parsing is completed, the expression in evaluated from its reverse-polish notation form.
