CC = gcc
CPPFLAGS = -I.
CFLAGS = -Wall -Wextra -ansi -pedantic
LDFLAGS = -lm
OBJ = main.o hello.o
EXEC = hello

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

.c .o:
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -c

clean:
	rm *o $(EXEC)
