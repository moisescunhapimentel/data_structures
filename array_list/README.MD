# Array List in C

This is a simple implementation of a array list in C. It provides basic operations to create, and manipulate list.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

This C program implements a array list with the following components:

- `TArrayList`: A structure representing the array list itself.
- Various functions to perform operations on the array list.

## Usage

To use this implementation of a array list in your C program, follow these steps:

1. Include the `array_list.h` header file in your C source code.

2. Create a array list using the `create_array_list(x)` function:

   ```c
   TArrayList *array_list = create_array_list(0);
   ```

Use the provided functions to perform operations on the list, such as inserting, removing, and printing elements.

3. Clear the list and free any allocated memory when you're done using it:

   ```c
   clear(array_list);
   ```

For more details on available functions and how to use them, refer to the comments in the `array_list.h` file.

## Contributing
Contributions are welcome! If you have any improvements, bug fixes, or feature additions, feel free to open an issue or submit a pull request.
