INC = .
SRC = .
OBJ = .
BIN = .

CPP     := g++
CFLAGS  := -Wfatal-errors
CFLAGS  += -I$(INC)
CFLAGS  += -g -O2

# Main target
main: $(OBJ)/main.o\
      $(OBJ)/display.o\
      $(OBJ)/block.o\
      $(OBJ)/game_constants.o\
      $(OBJ)/input_handler.o\
      $(OBJ)/boundry_scanner.o\
      $(OBJ)/player.o\
      $(OBJ)/map.o\
      $(OBJ)/maplocation.o\
      $(OBJ)/world.o\
      $(OBJ)/ui.o
	$(CPP) $(CFLAGS) $^ -o $(OBJ)/$@ -lncurses

# Objects
main.o: $(SRC)/main.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

block.o: $(SRC)/block.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

boundry_scanner.o: $(SRC)/boundry_scanner.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

player.o: $(SRC)/player.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

map.o: $(SRC)/map.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

maplocation.o: $(SRC)/maplocation.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

world.o: $(SRC)/world.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

display.o: $(SRC)/display.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

input_handler.o: $(SRC)/input_handler.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

game_constants.o: $(SRC)/game_constants.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

ui.o: $(SRC)/ui.cpp
	$(CPP) $(CFLAGS) -c $< -o $(OBJ)/$@

.PHONY: clean
clean:
	rm -f *.o
	rm -f testworld
	rm -f main
