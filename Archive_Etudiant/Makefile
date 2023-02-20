CC = g++
FLAGS = -g -Wall -c

all: main.o Image.o Pixel.o
	$(CC) main.o Image.o Pixel.o -o Prog.exe

main.o: main.cpp Image.o
	$(CC) $(FLAGS) main.cpp

Image.o: Image.cpp Pixel.o 
	$(CC) $(FLAGS) Image.cpp

Pixel.o: Pixel.cpp
	$(CC) $(FLAGS) Pixel.cpp

clean:
	rm -rf *.o *.exe
