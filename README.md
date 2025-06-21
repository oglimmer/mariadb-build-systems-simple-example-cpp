# maria-test

A C++ project demonstrating MariaDB connectivity using different build systems.

## Overview

This project contains four different implementations of the same MariaDB connection test, each using a different build system:

- **maria-test.cmake**: Uses CMake for building
- **maria-test.make**: Uses Make for building  
- **maria-test.gcc**: Uses direct GCC compilation
- **maria-test.clang**: Uses Clang compiler

Each implementation connects to a MariaDB database and lists all available databases.

## Prerequisites

- Docker and Docker Compose
- C++ compiler (GCC/Clang) (for local builds)
- MariaDB client libraries (for local builds)

## Individual Builds

### CMake Version
```bash
cd maria-test.cmake
docker compose up --build
```

### Make Version
```bash
cd maria-test.make
docker compose up --build
```

### GCC Version
```bash
cd maria-test.gcc
docker compose up --build
```

### Clang Version
```bash
cd maria-test.clang
docker compose up --build
```

## Database Configuration

Each implementation connects to MariaDB with:
- Host: `mariadb`
- Database: `test`
- Username: `test`
- Password: `test`

## What It Does

The program:
1. Initializes a MariaDB connection
2. Connects to the database server
3. Executes `SHOW DATABASES` query
4. Displays all available databases
5. Closes the connection

