# Data Structures in C

This repository contains various data structures implemented in C programming language. Each folder in this repository represents a different data structure, and you can find the source code and usage examples for each data structure within their respective folders.

## Table of Contents

- [List of Data Structures](#list-of-data-structures)
- [How to Use](#how-to-use)
- [Contributing](#contributing)
- [Running Tests with Docker](#running-tests-with-docker)
<!-- - [License](#license) -->

## List of Data Structures

1. [Linked List](./linked_list): Implementation of a linked list.
2. [Doubly Linked List](./doubly_linked_list): Implementation of a doubly linked list.
3. [Circular Linked List](./circular_linked_list): Implementation of a circular linked list.
4. [Doubly Circular Linked List](./doubly_circular_linked_list): Implementation of a doubly circular linked list.
5. [Queue](./queue): Implementation of a queue.
5. [Stack](./stack): Implementation of a stack.

Each folder contains detailed explanations, source code, and usage examples for the respective data structure.

## How to Use

To use any of the data structures provided in this repository, follow these general steps:

1. Navigate to the folder of the data structure you want to use.

2. Review the README and source code to understand how the data structure is implemented.

3. Incorporate the data structure into your C project by including the necessary header files and source files.

4. Refer to the usage examples provided in the folder to see how to use the data structure in your code.

## Contributing

If you'd like to contribute to this repository, feel free to open an issue or submit a pull request.

To add a new data structure, you need to follow a set of rules.

1. Define the name of the data structure, without spaces and separated by underscores, for example, `linked_list`.

2. Create a folder with the chosen name.

3. Inside the folder, you should create an .h file with the same name as the folder, responsible for documenting the functions.

4. Inside the folder, you should also create a .c file with the same name as the folder, responsible for implementing the functions described in the .h file.

5. Inside the folder, create a subfolder named test.

6. Inside the test subfolder, create a .c file with the name chosen in step 2, appending _test to the end of the filename.

For example, if you choose `linked_list` in step 2, you will create the `linked_list/` folder. Inside `linked_list/`, you will have two files, `linked_list.h` and `linked_list.c.` In addition to these files, there is a `test/` folder. Inside `test/`, you will find `linked_list_test.c.`

Diagram of the example above:

```
/data_structures
└── linked_list/
    ├── linked_list.h
    ├── linked_list.c
    └── test/
        └── linked_list_test.c
```

## Running Tests with Docker

To simplify our development process, we will use `Docker` to run tests locally on your machine. You need to have `Docker` installed.

After making changes or adding code to this project, you can rerun the tests. It is recommended not to modify the `Dockerfile`, and using the `docker-compose.yml` is advised to streamline the process.

Please note that the `-d` flag hides the output of ctest, so do not use it when running `Docker` commands in the terminal.

When you make code changes, follow these steps:

```bash
$docker compose up --build
```
If you have already run the previous command and haven't made further code changes, you can run:

```bash
$docker compose up
```
If, for some reason, you don't see the output of ctest after running the first command, you can check the information with:

```bash
$docker logs data-structures
```