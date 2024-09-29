.PHONY: test_connect4

test_connect4: $(C4_TEST_DIR)/test_connect4.o $(C4_DIR)/connect4.o $(MATRIX_DIR)/matrix.o
	$(CC) $^ -o $(BIN_DIR)/test/$@

$(C4_TEST_DIR)/test_connect4.o: $(C4_TEST_DIR)/test_connect4.c
	$(CC) -c $< $(CFLAGS) -o $@ $(CPPFLAGS)

$(C4_DIR)/connect4.o: $(C4_DIR)/connect4.c
	$(CC) -c $^ $(CFLAGS) -o $@ $(CPPFLAGS)
