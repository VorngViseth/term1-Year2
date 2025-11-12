[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/ofN4OCs7)
# Week 4 - Postfix Expression Evaluation Using Stack

## Lab Objective:

By completing this lab, students will:

- Understand how stacks can be used to evaluate mathematical expressions.
- Practice implementing stack operations (`push`, `pop`, `peek`).
- Learn the concept of postfix (Reverse Polish) notation and how it differs from infix.

## 1. Background Theory

A stack follows the LIFO rule — Last In, First Out.
Postfix (or Reverse Polish Notation) is a mathematical notation where operators follow their operands.
Example:

| Infix         | Postfix     |
| ------------- | ----------- |
| `A + B`       | `A B +`     |
| `(A + B) * C` | `A B + C *` |



The advantage is that postfix expressions don’t need parentheses to define order.

## 2. Algorithm for Evaluating Postfix Expression

To evaluate a postfix expression:

1. Create an empty stack.

2. Scan the expression from left to right:

    - If the symbol is a number, push it onto the stack.
    - If the symbol is an operator (`+`, `-`, `*`, `/`, `^`):
        - Pop the top two operands.
        - Apply the operator.
        - Push the result back to the stack.

3. At the end, the only element left in the stack is the result.

## 3. Example Walkthrough

Expression
```
6 2 3 + - 3 8 2 / + * 2 ^
```

| Step | Symbol | Action                   | Stack        |
| ---- | ------ | ------------------------ | ------------ |
| 1    | 6      | Push                     | [6]          |
| 2    | 2      | Push                     | [6, 2]       |
| 3    | 3      | Push                     | [6, 2, 3]    |
| 4    | +      | Pop(2,3) → 2+3=5 → Push  | [6, 5]       |
| 5    | -      | Pop(6,5) → 6-5=1 → Push  | [1]          |
| 6    | 3      | Push                     | [1, 3]       |
| 7    | 8      | Push                     | [1, 3, 8]    |
| 8    | 2      | Push                     | [1, 3, 8, 2] |
| 9    | /      | Pop(8,2) → 8/2=4 → Push  | [1, 3, 4]    |
| 10   | +      | Pop(3,4) → 3+4=7 → Push  | [1, 7]       |
| 11   | *      | Pop(1,7) → 1*7=7 → Push  | [7]          |
| 12   | 2      | Push                     | [7, 2]       |
| 13   | ^      | Pop(7,2) → 7^2=49 → Push | [49]         |

Final answer is `49`.

## 4. Coding Task

### 4.1 Implementing Stack ADT

Navigate to [utils/stack.hpp](utils/stack.hpp) and complete the abstract data type for stack (`array`/`linked`) by implementing all its operations:
- `push(item)`
- `pop()`
- `peek()`
- `isEmpty()`

**NOTE**: Stack values/items must be `float` datatype!

### 4.2 Implementing Postfix Expression

In [utils/postfix_eval.hpp](utils/postfix_eval.hpp) complete the class `PostfixEval`.

- Predefined private methods:
    - `isOperator(char c)` to check for the supported operators.
    - `calculate(float op1, float op2, char op)` to calculate for 2 numbers by provided/supported operators.

- What to do: Complete the `evaluate()` logic to calculate the postfix expression and return the final result.

    - Use user defined `stack` from task 4.1
    - Use `stof` function to convert from string digits to float




### 4.3 Testing your Solution

In [main.cpp](main.cpp) try to evaluate your sulution in various scenarios to make sure it's working correctly as expected!

**NOTE**: Please do not use `cin` due to automate testing cann't handle user input operation!

# Happy coding!