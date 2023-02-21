CC = g++
FLAGS = -g -Wall -c
SRC = src/
OBJ = obj/

all: $(OBJ)mainExemple.o $(OBJ)Image.o $(OBJ)Pixel.o
	$(CC) $(OBJ)mainExemple.o $(OBJ)Image.o $(OBJ)Pixel.o -o Prog.exe

test: $(OBJ)mainTest.o $(OBJ)Image.o
	$(CC) $(OBJ)mainTest.o $(OBJ)Image.o $(OBJ)Pixel.o -o ProgTest.exe

$(OBJ)mainTest.o : $(SRC)mainTest.cpp $(OBJ)Image.o
	$(CC) $(FLAGS) $(SRC)mainTest.cpp

$(OBJ)mainExemple.o: $(SRC)mainExemple.cpp $(OBJ)Image.o
	$(CC) $(FLAGS) $(SRC)mainExemple.cpp

$(OBJ)Image.o: $(SRC)Image.cpp $(OBJ)Pixel.o 
	$(CC) $(FLAGS) $(SRC)Image.cpp

$(OBJ)Pixel.o: $(SRC)Pixel.cpp
	$(CC) $(FLAGS) $(SRC)Pixel.cpp

clean:
	rm -rf $(OBJ)*.o *.exe
