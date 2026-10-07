# Projects with C++

A collection of programming projects. The current repository contains a C++ console prototype for a bank account menu.

## Project files

The bank prototype is in `Cpp/`:

- `main.cpp` starts the program and displays the main menu.
- `DEFINE.h` implements the menu, account creation, and login routines.
- `prototype.h` declares the functions used by the project.
- `USER.h` defines the `USER` class and its account fields.

## Current behavior

The menu offers options to create an account, log in, recover a password, or open the admin menu. Account creation and the login flow have code in place. Password recovery and the admin action are currently placeholders; their calls are commented out.

The code reads and writes files under `DATA/` and reads an identifier from `IP/ALL_IP`, using paths relative to the program's working directory. These data files and directories are not included in the current repository, so the project needs them before the account flows can use persistent data.

## Build notes

The sources include `<unistd.h>` and also call `system("cls")`. These use different platform conventions, so the project may need small platform-specific adjustments to compile and run in a given environment. Build from the repository root with a C++ compiler after resolving those platform dependencies.
