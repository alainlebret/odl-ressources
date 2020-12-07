
# Add "@" in front of the command to prevent display
$(MATRIX_PATH)/matrix.o : $(MATRIX_PATH)/matrix.c $(INC_PATH)/matrix.h
	@echo "The path to include files is: $(INC_PATH)"
	@echo
	$(CC) $(CFLAGS) -c -I $(INC_PATH)/ $(MATRIX_PATH)/matrix.c -o $@