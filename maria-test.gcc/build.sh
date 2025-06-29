#!/bin/bash

set -e  # Exit on any error

# Get MariaDB/MySQL client library flags using pkg-config
MARIADB_CFLAGS=$(pkg-config --cflags mariadb 2>/dev/null)
MARIADB_LIBS=$(pkg-config --libs mariadb 2>/dev/null)

# Compile with C++23 standard
g++ -std=c++23 \
    $MARIADB_CFLAGS \
    -o maria_test \
    main.cpp \
    $MARIADB_LIBS
