.PHONY: test_matrix

test_matrix: $(MATRIX_TEST_DIR)/test_matrix.o $(MATRIX_DIR)/matrix.o
	$(CC) $^ -o $(BIN_DIR)/test/$@

$(MATRIX_TEST_DIR)/test_matrix.o: $(MATRIX_TEST_DIR)/test_matrix.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(MATRIX_DIR))/matrix.o: $(MATRIX_DIR)/matrix.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@
