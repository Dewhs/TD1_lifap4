CC = g++
FLAGS = -g -Wall -c
SRC = src/
OBJ = obj/
BIN = bin/
INCLUDE_DIR_SDL = -I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image

all: $(BIN)exemple $(BIN)affichage $(BIN)test

$(BIN)affichage: $(OBJ)mainAffichage.o $(OBJ)Image.o $(OBJ)Pixel.o
	$(CC) $(INCLUDE_DIR_SDL) $(SRC)mainAffichage.cpp $(SRC)Image.cpp $(SRC)Pixel.cpp -o $(BIN)affichage $(LIBS_SDL)

$(BIN)exemple: $(OBJ)mainExemple.o $(OBJ)Image.o $(OBJ)Pixel.o
	$(CC) $(INCLUDE_DIR_SDL) $(SRC)mainExemple.cpp $(SRC)Image.cpp $(SRC)Pixel.cpp -o $(BIN)exemple $(LIBS_SDL)

$(BIN)test: $(SRC)mainTest.cpp $(OBJ)Image.o $(SRC)Pixel.h $(SRC)Pixel.cpp $(SRC)Image.h $(SRC)Image.cpp
	$(CC) $(INCLUDE_DIR_SDL) $(SRC)mainTest.cpp $(SRC)Image.cpp $(SRC)Pixel.cpp -o $(BIN)test $(LIBS_SDL)
	
$(OBJ)mainAffichage.o: $(SRC)mainAffichage.cpp
	$(CC) $(FLAGS) $(SRC)mainAffichage.cpp -o $(OBJ)mainAffichage.o $(LIBS_SDL)

$(OBJ)mainTest.o: $(SRC)mainTest.cpp $(SRC)Image.h
	$(CC) $(FLAGS) $(SRC)mainTest.cpp -o $(OBJ)mainTest.o $(LIBS_SDL)

$(OBJ)mainExemple.o: $(SRC)mainExemple.cpp
	$(CC) $(FLAGS) $(SRC)mainExemple.cpp -o $(OBJ)mainExemple.o $(LIBS_SDL)

$(OBJ)Image.o: $(SRC)Image.cpp $(SRC)Image.h $(SRC)Pixel.h  
	$(CC) $(FLAGS) $(SRC)Image.cpp -o $(OBJ)Image.o $(LIBS_SDL)

$(OBJ)Pixel.o: $(SRC)Pixel.cpp $(SRC)Pixel.h
	$(CC) $(FLAGS) $(SRC)Pixel.cpp -o $(OBJ)Pixel.o $(LIBS_SDL)

clean:
	rm -rf $(OBJ)*.o $(BIN)*

clean_all:
	rm -rf $(OBJ)*.o $(BIN)* data/*
