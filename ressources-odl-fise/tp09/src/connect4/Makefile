.PHONY: connect4

connect4 : $(C4_DIR)/connect4.o $(C4_DIR)/main.o
	$(CC) $^ -o $(BIN_DIR)/connect4 $(LDFLAGS) -Wl,-rpath,"$(LIB_DIR)"

$(C4_DIR)/main.o : $(C4_DIR)/main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $< -c