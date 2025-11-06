CC = gcc
CFLAGS = -Wall -g -std=c99 

# Source and header files
SRCS := $(wildcard *.c)
HDRS := $(wildcard *.h)
OBJS := $(SRCS:.c=.o)

# Default target
all: test

# Link object files into executable
test: $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)

# Compile C files into object files
%.o: %.c $(HDRS)
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean generated files
clean:
	rm -f $(OBJS) test