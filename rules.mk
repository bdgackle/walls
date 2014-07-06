################################################################################
# RULES
################################################################################
# Dependency files
-include $(OBJECTS:.o=.d)

# Turn off implicit rules to avoid conflict
.SUFFIXES:

# Compilation
.DEFAULT_GOAL :=
.PHONY: all
all: $(OUTPUT_BIN)
	@echo Done

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CPP) -c $(CFLAGS) -o $@ $<
	$(CPP) -MM -MT $@ $(CFLAGS) $< > $(OBJ)/$*.d
	@echo Compiling: $@

$(OUTPUT_BIN): $(OBJECTS)
	$(CPP) -o $@ $^ $(LDFLAGS)
	@echo Linking: $@

.PHONY: clean
clean::
	rm -f $(OBJ)/*.o
	@echo REMOVING: $(OBJ)/*.o
	rm -f $(OBJ)/*.d
	@echo REMOVING: $(OBJ)/*.d
	rm -f $(BIN)/*.a
	@echo REMOVING: $(BIN)/*.a
	rm -f $(OUTPUT_BIN)
	@echo REMOVING: $(OUTPUT_BIN)
	@echo Done.
