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

## Persistence format and safety limits

Run the program from the same working directory each time: its relative paths determine which account files it reads. Create the `DATA/` and `IP/` directories before trying account creation; the code does not create them or report failed file writes.

| Path | Record format / use |
| --- | --- |
| `DATA/USER_INFO.txt` | One line per account: `first_name last_name phone_number age` |
| `DATA/USER_NAM_PASS.txt` | One line per account: `username password account_id` |
| `IP/ALL_IP` | Whitespace-separated integer identifiers; the last readable value is used to calculate the next identifier |

Account records and allocated identifiers are appended. `Set_Data` records each new identifier in `IP/ALL_IP`, so successive registrations continue from the last stored value. If that file is absent or empty, the first calculated identifier is 1. The `DATA/` and `IP/` directories must still exist before registration.

This is a learning prototype, not a secure banking system. Passwords are stored as plain text, input is whitespace-delimited, and the separate file writes are not transactional. Use only invented names and disposable test credentials, never real banking details or a password used elsewhere. Keep generated account files private.

## Build notes

The prototype rejects a registration only when all four identity fields (first name, last name, phone number, and age) match the same stored record. Reusing one field on its own does not make an account a duplicate.

The sources call `system("cls")`, which is Windows-specific. On other platforms the program still compiles, but clearing the console may print a shell error unless that call is adapted. Build from the repository root with a C++ compiler.
