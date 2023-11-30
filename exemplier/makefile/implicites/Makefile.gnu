CC = gcc
CPPFLAGS = -I.
CFLAGS = -Wall -Wextra -ansi -pedantic
LDFLAGS = -lm
OBJ = main.o hello.o
EXEC = hello

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) $< -c

clean:
	rm *o