CC = gcc
CPPFLAGS = -I ./include
CFLAGS_MINUNIT = -Wall -Wextra -pedantic -g
CFLAGS = $(CFLAGS_MINUNIT) -ansi
LDFLAGS = 

# Specific spam files on operating system
ifeq ($(OS),Windows_NT)
	# Bla bla bla
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		# Bla bla bla
	endif
	ifeq ($(UNAME_S),Darwin)
		SPAM_FILES = ".DS_Store"
	endif
endif

.PHONY: all clean distclean check_folder_tree_structure

all: check_folder_tree_structure bin/tests/test_util bin/tests/test_factorial # ...

check_folder_tree_structure:
	mkdir -p bin/tests
	mkdir -p doc

bin/tests/test_util: tests/test_util.o src/util.o
	$(CC) -o $@ $^ $(LDFLAGS)

tests/test_util.o: tests/test_util.c include/util.h
	$(CC) $(CPPFLAGS) $(CFLAGS_MINUNIT) -o $@ $< -c

src/util.o: src/util.c include/util.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -ansi -o $@ $< -c

bin/tests/test_factorial: tests/test_factorial.o src/factorial.o
	$(CC) -o $@ $^ $(LDFLAGS)

tests/test_factorial.o: tests/test_factorial.c include/factorial.h
	$(CC) $(CPPFLAGS) $(CFLAGS_MINUNIT) -o $@ $< -c

src/factorial.o: src/factorial.c include/factorial.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -ansi -o $@ $< -c

clean:
	rm -f tests/*.o src/*.o doc/*

distclean: clean
	rm -fr bin/tests/* bin/*
	find . -name $(SPAM_FILES) -type f -delete
	rmdir bin
	rmdir doc
