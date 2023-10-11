# Queue in C

This is a simple implementation of a queue in C. It provides basic operations to create, and manipulate the queue.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

This C program implements a queue with the following components:

- `TQueue`: A structure representing the queue itself.
- `TNode`: A structure representing a node in the queue.
- Various functions to perform operations on the queue.

## Usage

To use this implementation of a queue in your C program, follow these steps:

1. Include the `queue.h` header file in your C source code.

2. Create a queue using the `create_queue()` function:

   ```c
   TQueue *queue = create_queue();

3. Clear the queue and free any allocated memory when you're done using it:

   ```c
   clear(queue);
   ```

For more details on available functions and how to use them, refer to the comments in the `queue.h` file.

## Contributing
Contributions are welcome! If you have any improvements, bug fixes, or feature additions, feel free to open an issue or submit a pull request.
