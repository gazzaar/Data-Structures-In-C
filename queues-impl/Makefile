# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target executable name
TARGET = main

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): main.o queue.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o queue.o

# Compile main.c
main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c

# Compile queue.c
queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

# Clean up
clean:
	rm -f *.o $(TARGET)

# Phony targets
.PHONY: all clean
