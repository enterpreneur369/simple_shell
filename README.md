# Project 0x15 - Simple_shell

simple_shell is a basic command interpreter that executes commands from the standard input or from a file.

## Installation
Clone the repository. Compile the ".c" files. Run executable.

```
$ git clone https://github.com/felipemontes/simple_shell.git
```

## Compile and start

To start simple_shell you just need to compile using gcc -Wall -Werror   -Wextra -pedantic *.c -o hsh.

## File Contents
This repository contains the following files:

|   **File**   |   **Description**   |
| -------------- | --------------------- |
| shell.c | the main function |
| shell.h | header file |
| tokens.c | convert into tokens |
| path.c | checks for the path |
| free.c | frees double pointer |
| functions.c | string functions |

### run

```
./hsh
```

## Usage (Interactive mode)

```
hsh$ /bin/ls
hsh$ ls -la
hsh$ pwd
```

## Builtins
```bash
env
```

## Authors
[Felipe Londoño](https://github.com/felipemontes)
[Julian Villegas](https://github.com/julianchok25)
