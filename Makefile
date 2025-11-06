CC = gcc
CFLAGS = -Wall -ansi -pedantic -g

SRCS := $(wildcard *.c)
HDRS := $(wildcard *.h)
OBJS := $(SRCS:.c=.o)

# Default target (if you just type `make`)
all: test

# Generic target: allows "make name" to build "name"
%: $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)

%.o: %.c $(HDRS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS) test