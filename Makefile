INC = .
SRC = .
OBJ = .
BIN = .

CPP     := g++
CFLAGS  := -Wfatal-errors
CFLAGS  += -I$(INC)

# Objects
square.o: $(SRC)/square.cpp\
          $(INC)/square.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

wall_map.o: $(SRC)/wall_map.cpp\
            $(INC)/wall_map.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

display.o: $(SRC)/display.cpp\
           $(INC)/display.h\
           $(INC)/wall_map.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

board.o: $(SRC)/board.cpp\
         $(INC)/board.h\
         $(INC)/wall_map.h\
         $(INC)/square.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

ut.o: $(SRC)/ut.cpp\
      $(INC)/ut.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

testsquare.o: $(SRC)/testsquare.cpp\
              $(INC)/square.h\
              $(INC)/ut.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

testwall_map.o: $(SRC)/testwall_map.cpp\
                $(INC)/wall_map.h\
                $(INC)/ut.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

testdisplay.o: $(SRC)/testdisplay.cpp\
               $(INC)/wall_map.h\
               $(INC)/ut.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

testboard.o: $(SRC)/testboard.cpp\
             $(INC)/board.h\
             $(INC)/ut.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

# Individual unit tests            
testsquare: $(OBJ)/testsquare.o\
            $(OBJ)/ut.o\
            $(OBJ)/square.o
	$(CPP) $(CFLAGS) $^ -o $(BIN)/$@

testwall_map: $(OBJ)/testwall_map.o\
              $(OBJ)/ut.o\
              $(OBJ)/wall_map.o
	$(CPP) $(CFLAGS) $^ -o $(BIN)/$@

testdisplay: $(OBJ)/testdisplay.o\
             $(OBJ)/display.o\
             $(OBJ)/ut.o\
             $(OBJ)/wall_map.o
	$(CPP) $(CFLAGS) $^ -o $(BIN)/$@

testboard: $(OBJ)/testboard.o\
           $(OBJ)/board.o\
           $(OBJ)/display.o\
           $(OBJ)/square.o\
           $(OBJ)/ut.o\
           $(OBJ)/wall_map.o
	$(CPP) $(CFLAGS) $^ -o $(BIN)/$@

# Run all tests
.PHONY: test
test: $(BIN)/testsquare\
      $(BIN)/testwall_map\
      $(BIN)/testdisplay\
      $(BIN)/testboard
	$(BIN)/testsquare
	$(BIN)/testwall_map
	$(BIN)/testdisplay
	$(BIN)/testboard

.PHONY: clean
clean:
	rm -f *.o
	rm -f testsquare
	rm -f testwall_map
	rm -f testdisplay
	rm -f testboard
