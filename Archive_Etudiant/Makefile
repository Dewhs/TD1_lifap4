CC = g++
FLAGS = -g -Wall -c

all: main.o Image.o Pixel.o
	$(CC) main.o Image.o Pixel.o -o Prog.exe

test: mainTest.o Image.o
	$(CC) mainTest.o Image.o Pixel.o -o ProgTest.exe

mainTest.o : mainTest.cpp Image.o
	$(CC) $(FLAGS) mainTest.cpp

main.o: main.cpp Image.o
	$(CC) $(FLAGS) main.cpp

Image.o: Image.cpp Pixel.o 
	$(CC) $(FLAGS) Image.cpp

Pixel.o: Pixel.cpp
	$(CC) $(FLAGS) Pixel.cpp

clean:
	rm -rf *.o *.exe
