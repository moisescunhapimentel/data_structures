# Circular Linked List in C

This is a simple implementation of a circular linked list in C. It provides basic operations to create, manipulate, and print the list.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

This C program implements a circular linked list with the following components:

- `TList`: A structure representing the circular linked list itself.
- `TNode`: A structure representing a node in the circular linked list.
- Various functions to perform operations on the circular linked list.

## Usage

To use this implementation of a circular linked list in your C program, follow these steps:

1. Include the `circular_linked_list.h` header file in your C source code.

2. Create a circular linked list using the `create_list()` function:

   ```c
   TList *list = create_list();
Use the provided functions to perform operations on the list, such as inserting, removing, and printing elements.

3. Clear the list and free any allocated memory when you're done using it:

   ```c
   clear(list);
   ```

For more details on available functions and how to use them, refer to the comments in the `circular_linked_list.h` file.

## Contributing
Contributions are welcome! If you have any improvements, bug fixes, or feature additions, feel free to open an issue or submit a pull request.
