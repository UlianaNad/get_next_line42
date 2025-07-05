📖 get_next_line
get_next_line is a C function that reads a file, or any file descriptor, line by line. Each call to the function returns the next line from the file, handling memory management carefully and reading efficiently in chunks defined by BUFFER_SIZE.

📌 Function Prototype

char *get_next_line(int fd);

Parameters:
fd — the file descriptor to read from.


Returns:

 - The next line read from the file (including the newline character \n if present).

 - NULL when there’s nothing else to read or in case of an error.


📌 Features:
 - Reads files in chunks using a buffer size defined by BUFFER_SIZE.

 - Uses a static variable to store leftover data between function calls.

 - Manages memory carefully to avoid leaks.

 - Can read from any valid file descriptor (including stdin).


📁 Project Files:
 - get_next_line.c — contains the main function implementation.

 - get_next_line_utils.c — helper functions for string operations and memory handling.

 - get_next_line.h — header file with function prototypes.

 - Makefile — for building the project.

📦 Compilation
bash
make

To test the program, you can use a file or standard input:
bash

./a.out < testfile.txt


📑 Notes
This project is part of the 42 school curriculum and aims to help students understand file descriptors, buffer management, and dynamic memory handling in C.
