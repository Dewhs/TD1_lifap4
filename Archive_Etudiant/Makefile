
all: main.o Image.o Pixel.o
	g++ main.o Image.o Pixel.o -o Prog.o

main.o: main.cpp Image.o
	g++ -Wall -c main.cpp

Image.o: Image.h Pixel.o
	g++ -Wall -c Image.cpp

Pixel.o: Pixel.h
	g++ -Wall -c Pixel.cpp

clean:
	rm -rf *.o *.exe