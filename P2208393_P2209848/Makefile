CC = g++
FLAGS = -g -Wall -c
SRC = src/
OBJ = obj/
BIN = bin/

$(BIN)affichage: $(OBJ)mainAffichage.o $(OBJ)Image.o $(OBJ)Pixel.o
	$(CC) $(OBJ)mainAffichage.o $(OBJ)Image.o $(OBJ)Pixel.o -o $(BIN)affichage

$(BIN)exemple: $(OBJ)mainExemple.o $(OBJ)Image.o $(OBJ)Pixel.o
	$(CC) $(OBJ)mainExemple.o $(OBJ)Image.o $(OBJ)Pixel.o -o $(BIN)exemple

$(BIN)test: $(OBJ)mainTest.o $(OBJ)Image.o
	$(CC) $(OBJ)mainTest.o $(OBJ)Image.o $(OBJ)Pixel.o -o $(BIN)test
	
$(OBJ)mainAffichage.o : $(SRC)mainAffichage.cpp $(OBJ)Image.o
	$(CC) $(FLAGS) $(SRC)mainAffichage.cpp -o $(OBJ)mainAffichage.o

$(OBJ)mainTest.o : $(SRC)mainTest.cpp $(OBJ)Image.o
	$(CC) $(FLAGS) $(SRC)mainTest.cpp -o $(OBJ)mainTest.o

$(OBJ)mainExemple.o: $(SRC)mainExemple.cpp $(OBJ)Image.o
	$(CC) $(FLAGS) $(SRC)mainExemple.cpp -o $(OBJ)mainExemple.o

$(OBJ)Image.o: $(SRC)Image.cpp $(OBJ)Pixel.o 
	$(CC) $(FLAGS) $(SRC)Image.cpp -o $(OBJ)Image.o

$(OBJ)Pixel.o: $(SRC)Pixel.cpp
	$(CC) $(FLAGS) $(SRC)Pixel.cpp -o $(OBJ)Pixel.o

clean:
	rm -rf $(OBJ)*.o $(BIN)*

clean_all:
	rm -rf $(OBJ)*.o $(BIN)* data/*
