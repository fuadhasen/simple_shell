# Simple Shell

A lightweight Unix shell implemented in **C** as a systems programming project. The project focuses on understanding how command-line interpreters work internally, including process creation, command execution, PATH resolution, environment handling, and basic input parsing.

## Overview

Simple Shell provides an interactive command-line interface where users can enter and execute Unix commands.

The project was built to explore low-level Linux concepts and understand what happens behind the scenes when a shell executes a command.

```text
$ ./hsh
$ ls
$ pwd
$ whoami
$ echo "Hello, World!"
```

## Features

- Interactive command-line interface
- Execution of common Unix commands
- Support for commands with arguments
- Absolute and PATH-based command resolution
- Environment variable access
- `env` command support
- `exit` command
- Process creation using `fork()`
- Program execution using `execve()`
- Parent/child process synchronization using `wait()`
- Basic command and argument parsing
- Custom string utility functions
- Custom formatted output implementation

## How It Works

The shell continuously reads commands from standard input and determines how they should be executed.

```text
User Input
    │
    ▼
Read Command
    │
    ▼
Parse Command & Arguments
    │
    ▼
Resolve Executable
    │
    ├── Absolute Path
    │
    └── Search PATH
    │
    ▼
Create Child Process
    │
    ▼
Execute with execve()
    │
    ▼
Wait for Child Process
    │
    ▼
Display Prompt Again
```

### Process Execution

When a command needs to be executed, the shell creates a child process using `fork()`.

The child process executes the requested program using `execve()`, while the parent process waits for the child to finish using `wait()`.

This demonstrates the fundamental relationship between a Unix shell and the operating system's process-management mechanisms.

## PATH Resolution

For commands that are not provided as absolute paths, the shell searches the directories listed in the `PATH` environment variable.

For example:

```text
$ ls
```

The shell searches the directories in `PATH` until it finds the executable, such as:

```text
/usr/bin/ls
```

It can then execute the resolved program using `execve()`.

## Environment Handling

The shell has access to the process environment through `environ` and provides basic environment-related functionality.

For example:

```text
$ env
```

Environment information is also passed to executed programs so applications that depend on variables such as `PATH`, `HOME`, or `TERM` can operate correctly.

## Supported Commands

The shell supports common Unix commands available on the system, including commands such as:

```text
pwd
ls
ls -l
ls -la
whoami
date
uname
echo "Hello, World!"
cat <file>
env
clear
exit
```

The exact commands available depend on the executables installed on the host operating system.

## Project Structure

```text
simple_shell/
├── main.c
├── main.h
├── shell.c
├── input.c
├── command.c
├── path.c
├── exls.c
├── excut.c
├── excut0.c
├── env.c
├── getenv.c
├── exit.c
│
├── _printf.c
├── _handl.c
├── _putchar.c
│
├── _strlen.c
├── _strcmp.c
├── _strncmp.c
├── _strcpy.c
├── _strcat.c
├── _strchr.c
├── _strdup.c
│
└── README.md
```

## Compilation

Compile the project using GCC:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Running the Shell

After compilation:

```bash
./hsh
```

You should see:

```text
$
```

You can then enter commands interactively:

```text
$ pwd
$ ls
$ ls -la
$ whoami
$ echo "Hello, World!"
$ env
$ exit
```

## Technologies

- **C**
- **Linux / Unix**
- **GCC**
- **POSIX system calls**
- **Process management**
- **Environment variables**
- **Standard C library**

## Key System Calls & Concepts

| Concept     | Purpose                                  |
| ----------- | ---------------------------------------- |
| `fork()`    | Creates a new child process              |
| `execve()`  | Executes a program                       |
| `wait()`    | Waits for a child process to finish      |
| `access()`  | Checks whether an executable exists      |
| `getline()` | Reads user input                         |
| `strtok()`  | Splits commands into tokens              |
| `environ`   | Provides access to environment variables |

## What I Learned

This project provided practical experience with:

- How Unix shells execute programs
- Parent and child process relationships
- Process creation and synchronization
- The purpose of `fork()` and `execve()`
- How the `PATH` variable is used to locate commands
- Passing environment variables to child processes
- Parsing user input and command arguments
- Working with system calls in C
- Building reusable low-level utility functions
- Debugging and compiling C programs with strict compiler flags

## Project Background

Simple Shell was developed as a **pair-programming systems project** focused on building a functional command-line interpreter from the ground up.

Rather than relying on an existing shell implementation, the project required understanding and implementing the fundamental mechanisms involved in command execution and process management.

## Author

**Fuad Hassen**

- GitHub: [@fuadhasen](https://github.com/fuadhasen)
