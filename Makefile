INC = .
SRC = .
OBJ = .
BIN = .

CPP     := g++
CFLAGS  := -Wfatal-errors
CFLAGS  += -I$(INC)
CFLAGS  += -g

# Main target
main: $(OBJ)/main.o\
      $(OBJ)/world.o\
      $(OBJ)/ui.o\
      $(OBJ)/block.o
	$(CPP) $(CFLAGS) $^ -o $(OBJ)/$@ -lncurses

# Objects
main.o: $(SRC)/main.cpp\
        $(INC)/ui.h\
        $(INC)/world.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

block.o: $(SRC)/block.cpp\
         $(INC)/block.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

world.o: $(SRC)/world.cpp\
         $(INC)/world.h\
         $(INC)/block.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

ui.o: $(SRC)/ui.cpp\
      $(INC)/ui.h\
      $(INC)/world.h
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

.PHONY: clean
clean:
	rm -f *.o
	rm -f testworld
	rm -f main
