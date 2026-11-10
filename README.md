# Projects with C++

A collection of programming projects. The current repository contains a C++ console prototype for a bank account menu.

## Project files

The bank prototype is in `Cpp/`:

- `main.cpp` starts the program and displays the main menu.
- `DEFINE.h` implements the menu, account creation, and login routines.
- `prototype.h` declares the functions used by the project.
- `USER.h` defines the `USER` class and its account fields.

## Current behavior

The menu offers options to create an account, log in, recover a password, or open the admin menu. Account creation and the login flow have code in place. Password recovery and the admin action are currently placeholders; their calls are commented out. Non-numeric and out-of-range menu choices are rejected and the same menu is shown again without growing the call stack.

The code reads and writes files under `DATA/` and reads an identifier from `IP/ALL_IP`, using paths relative to the program's working directory. The program creates the `DATA/` and `IP/` directories when saving an account; the data files are then created on first use.

## Persistence format and safety limits

Run the program from the same working directory each time: its relative paths determine which account files it reads. Account creation reports an error instead of claiming success when the directories or data files cannot be opened or written.

| Path | Record format / use |
| --- | --- |
| `DATA/USER_INFO.txt` | One line per account: `first_name last_name phone_number age` |
| `DATA/USER_NAM_PASS.txt` | One line per account: `username password account_id` |
| `IP/ALL_IP` | Whitespace-separated integer identifiers; the last readable value is used to calculate the next identifier |

Account records and allocated identifiers are appended. `Set_Data` records each new identifier in `IP/ALL_IP`, so successive registrations continue from the last stored value. If that file is absent or empty, the first calculated identifier is 1. Before writing, the program creates `DATA/` and `IP/` if needed and verifies that all three output files opened successfully.

This is a learning prototype, not a secure banking system. Passwords are stored as plain text, input is whitespace-delimited, and the separate file writes are not transactional. Use only invented names and disposable test credentials, never real banking details or a password used elsewhere. Keep generated account files private.

## Build notes

The prototype rejects a registration only when all four identity fields (first name, last name, phone number, and age) match the same stored record. Reusing one field on its own does not make an account a duplicate.

The sources call `system("cls")`, which is Windows-specific. On other platforms the program still compiles, but clearing the console may print a shell error unless that call is adapted. The persistence code uses `std::filesystem`, so compile as C++17 or newer from the repository root:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Cpp/main.cpp -o bank-prototype
```


## Run and smoke test

Run the executable from the repository root so its relative `DATA/` and `IP/` paths resolve consistently:

| Platform | Command |
| --- | --- |
| Windows PowerShell | `.\bank-prototype.exe` |
| Linux or macOS | `./bank-prototype` |

For a minimal persistence check, use invented, whitespace-free values:

1. Choose `0`, enter a new identity, and confirm it with `1`.
2. Enter the same new username twice and the same disposable password twice.
3. After the success message, choose `1` and log in with those credentials.
4. Exit, start the program again from the same directory, choose `1`, and confirm that the login still succeeds.

A successful registration appends one line to each of these generated files:

- `DATA/USER_INFO.txt` for the identity fields;
- `DATA/USER_NAM_PASS.txt` for the username, plain-text password, and account identifier;
- `IP/ALL_IP` for the allocated identifier.

The generated `DATA/` and `IP/` directories are excluded by `.gitignore`. Back them up together if you need to preserve a test dataset, because the three append-only files represent one logical account store. To reset a disposable test run, remove or rename both generated directories only after the program has stopped; never do this with data you need to keep.
