# Makefile for maria_test

CC = g++
CXXFLAGS = -std=c++23
TARGET = maria_test
SOURCE = main.cpp

# Get MariaDB/MySQL client library flags using pkg-config
MARIADB_CFLAGS = $(shell pkg-config --cflags mariadb 2>/dev/null || pkg-config --cflags mysqlclient)
MARIADB_LIBS = $(shell pkg-config --libs mariadb 2>/dev/null || pkg-config --libs mysqlclient)

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SOURCE)
	$(CC) $(CXXFLAGS) $(MARIADB_CFLAGS) -o $(TARGET) $(SOURCE) $(MARIADB_LIBS)

# Clean target
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean