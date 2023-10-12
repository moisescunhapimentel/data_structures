# Stack in C

This is a simple implementation of a stack in C. It provides basic operations to create and manipulate the stack.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

This C program implements a stack with the following components:

- `TStack`: A structure representing the stack itself.
- `TNode`: A structure representing a node in the stack.
- Various functions to perform operations on the stack.

## Usage

To use this implementation of a stack in your C program, follow these steps:

1. Include the `stack.h` header file in your C source code.

2. Create a stack using the `create_stack()` function:

   ```c
   TStack *stack = create_stack();

Use the provided functions to perform operations on the stack, such as inserting, removing, and printing elements.

3. Clear the stack and free any allocated memory when you're done using it:

   ```c
   clear(stack);
   ```

For more details on available functions and how to use them, refer to the comments in the `stack.h` file.

## Contributing
Contributions are welcome! If you have any improvements, bug fixes, or feature additions, feel free to open an issue or submit a pull request.
