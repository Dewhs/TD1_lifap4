CC = g++
FLAGS = -g -Wall -c
SRC = src/
OBJ = obj/
BIN = bin/

all: $(BIN)exemple $(BIN)affichage $(BIN)test

$(BIN)affichage: $(OBJ)mainAffichage.o $(OBJ)Image.o $(OBJ)Pixel.o
	$(CC) $(SRC)mainAffichage.cpp $(SRC)Image.cpp $(SRC)Pixel.cpp -o $(BIN)affichage

$(BIN)exemple: $(OBJ)mainExemple.o $(OBJ)Image.o $(OBJ)Pixel.o
	$(CC) $(SRC)mainExemple.cpp $(SRC)Image.cpp $(SRC)Pixel.cpp -o $(BIN)exemple

$(BIN)test: $(SRC)mainTest.cpp $(OBJ)Image.o $(SRC)Pixel.h $(SRC)Pixel.cpp $(SRC)Image.h $(SRC)Image.cpp
	$(CC) $(SRC)mainTest.cpp $(SRC)Image.cpp $(SRC)Pixel.cpp -o $(BIN)test
	
$(OBJ)mainAffichage.o: $(SRC)mainAffichage.cpp
	$(CC) $(FLAGS) $(SRC)mainAffichage.cpp -o $(OBJ)mainAffichage.o

$(OBJ)mainTest.o: $(SRC)mainTest.cpp $(SRC)Image.h
	$(CC) $(FLAGS) $(SRC)mainTest.cpp -o $(OBJ)mainTest.o

$(OBJ)mainExemple.o: $(SRC)mainExemple.cpp
	$(CC) $(FLAGS) $(SRC)mainExemple.cpp -o $(OBJ)mainExemple.o

$(OBJ)Image.o: $(SRC)Image.cpp $(SRC)Image.h $(SRC)Pixel.h  
	$(CC) $(FLAGS) $(SRC)Image.cpp -o $(OBJ)Image.o

$(OBJ)Pixel.o: $(SRC)Pixel.cpp $(SRC)Pixel.h
	$(CC) $(FLAGS) $(SRC)Pixel.cpp -o $(OBJ)Pixel.o

clean:
	rm -rf $(OBJ)*.o $(BIN)*

clean_all:
	rm -rf $(OBJ)*.o $(BIN)* data/*
