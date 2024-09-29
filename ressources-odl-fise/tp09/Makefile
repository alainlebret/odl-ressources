# Tools
CC              =gcc
DOXYGEN	        =doxygen
RM              =rm -f
# Macros for directories
SRC_DIR         =./src
TEST_DIR        =./tests
MATRIX_TEST_DIR =$(TEST_DIR)/matrix
C4_TEST_DIR     =$(TEST_DIR)/connect4
MATRIX_DIR      =$(SRC_DIR)/matrix
C4_DIR 	        =$(SRC_DIR)/connect4
BIN_DIR	        =./bin
INC_DIR	        =./include
LIB_DIR	        =./lib
DOC_DIR	        =./doc
DOXYFILEPATHC4  =$(DOC_DIR)/Doxyfile_connect4
# Compilation flags
CPPFLAGS        =-I$(INC_DIR)
CFLAGS	        =-Wall -Wextra -O2
LDFLAGS	        =-L$(LIB_DIR) -lmatrix

.PHONY: all tests clean distclean doc docclean

all: staticlib dynamiclib connect4

tests: test_matrix test_connect4

include $(MATRIX_TEST_DIR)/Makefile
include $(C4_TEST_DIR)/Makefile
include $(MATRIX_DIR)/Makefile
include $(C4_DIR)/Makefile

clean:
	-@$(RM) $(MATRIX_TEST_DIR)/*.o
	-@$(RM) $(C4_TEST_DIR)/*.o
	-@$(RM) $(MATRIX_DIR)/*.o
	-@$(RM) $(C4_DIR)/*.o

distclean: clean docclean
	-@$(RM) $(BIN_DIR)/connect4
	-@$(RM) $(BIN_DIR)/test/test_matrix $(BIN_DIR)/test/test_connect4
	-@$(RM) $(LIB_DIR)/libmatrix.a $(LIB_DIR)/libmatrix.so

doc:
	$(DOXYGEN) $(DOXYFILEPATHC4)

docclean:
	$(RM) -r $(DOC_DIR)/connect4
