# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Isrc
TARGET = advanced_shell
OBJ = src/main.o src/io/parser.o src/command/executor.o
HEADERS = src/io/parser.h src/command/executor.h

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Rule to build main.o
main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c

# Rule to build input_parser.o
parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

# Rule to build command_executor.o
executor.o: executor.c executor.h
	$(CC) $(CFLAGS) -c executor.c

# Rule to clean the build
clean:
	rm -f $(OBJ) $(TARGET)
