CC = gcc
CPPFLAGS = -I include
CFLAGS_TESTS = -Wall -Wextra -pedantic
CFLAGS = $(CFLAGS_TESTS) -ansi -fPIC -g
LDFLAGS = -L./lib -lf
BIN_DIR = bin
BIN_TESTS_DIR = $(BIN_DIR)/tests
SRC_DIR = src
SRC_LIB_DIR = $(SRC_DIR)/libf
SRC_TESTS_DIR = tests
INC_DIR = include
LIB_DIR = lib
DOC_DIR = doc
RM = rm
DOC = doxygen

.PHONY: all clean distclean tests staticlib dynamiclib doc
               
all: staticlib dynamiclib uselibf_s uselibf_d

# -------------------------------- EXECUTABLES --------------------------------

uselibf_s: $(SRC_DIR)/main.o $(LIB_DIR)/libf.a
	$(CC) $^ -o $(BIN_DIR)/$@

uselibf_d: $(SRC_DIR)/main.o $(LIB_DIR)/libf.so
	$(CC) $< -o $(BIN_DIR)/$@ $(LDFLAGS)

# ---------------------------------- TESTS ------------------------------------
tests: $(BIN_TESTS_DIR)/test_f1f2f3f4

$(BIN_TESTS_DIR)/test_f1f2f3f4: $(SRC_TESTS_DIR)/test_f1f2f3f4.o $(SRC_LIB_DIR)/f1.o $(SRC_LIB_DIR)/f2.o $(SRC_LIB_DIR)/f3.o $(SRC_LIB_DIR)/f4.o
	$(CC) $^ -o $@

$(SRC_TESTS_DIR)/test_f1f2f3f4.o: $(SRC_TESTS_DIR)/test_f1f2f3f4.c $(INC_DIR)/f.h
	$(CC) $(CPPFLAGS) $(CFLAGS_TESTS) $< -o $@ -c
	
# --------------------------------- LIBRARIES ---------------------------------

staticlib: $(LIB_DIR)/libf.a

$(LIB_DIR)/libf.a: $(SRC_LIB_DIR)/f1.o $(SRC_LIB_DIR)/f2.o $(SRC_LIB_DIR)/f3.o $(SRC_LIB_DIR)/f4.o
	ar crv $@ $^ 

dynamiclib: $(LIB_DIR)/libf.so

$(LIB_DIR)/libf.so: $(SRC_LIB_DIR)/f1.o $(SRC_LIB_DIR)/f2.o $(SRC_LIB_DIR)/f3.o $(SRC_LIB_DIR)/f4.o
	$(CC) -shared -o $@ $^ 

# ---------------------------------- OBJECTS ----------------------------------

$(SRC_LIB_DIR)/%.o: $(SRC_LIB_DIR)/%.c $(INC_DIR)/f.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c
 	
$(SRC_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/f.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ -c

# ------------------------------- DOCUMENTATION -------------------------------

doc:
	$(DOC) doc/Doxyfile

# ---------------------------------- CLEANING ---------------------------------

clean:
	$(RM) -f $(SRC_LIB_DIR)/*.o $(SRC_TESTS_DIR)/*.o $(SRC_DIR)/*.o

cleandoc:
	$(RM) -r doc/*

distclean: clean cleandoc
	$(RM) $(BIN_TESTS_DIR)/test_f1f2f3f4 $(BIN_DIR)/uselibf_s $(BIN_DIR)/uselibf_d $(LIB_DIR)/*.*

