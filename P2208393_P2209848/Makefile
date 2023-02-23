CC = g++
FLAGS = -g -Wall -c
#SRC = src/
#OBJ = obj/
#BIN = bin/
INCLUDE_DIR_SDL = -I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image

all: bin/exemple bin/affichage bin/test

bin/affichage: obj/mainAffichage.o obj/Image.o obj/Pixel.o
	$(CC) $(INCLUDE_DIR_SDL) src/mainAffichage.cpp src/Image.cpp src/Pixel.cpp -o bin/affichage $(LIBS_SDL)

bin/exemple: obj/mainExemple.o obj/Image.o obj/Pixel.o 
	$(CC) $(INCLUDE_DIR_SDL) src/mainExemple.cpp src/Image.cpp src/Pixel.cpp -o bin/exemple $(LIBS_SDL)

bin/test: src/mainTest.cpp obj/Image.o src/Pixel.h src/Pixel.cpp src/Image.h src/Image.cpp
	$(CC) $(INCLUDE_DIR_SDL) src/mainTest.cpp src/Image.cpp src/Pixel.cpp -o bin/test $(LIBS_SDL)
	
obj/mainAffichage.o: src/mainAffichage.cpp
	$(CC) $(FLAGS) src/mainAffichage.cpp -o obj/mainAffichage.o $(LIBS_SDL)

obj/mainTest.o: src/mainTest.cpp src/Image.h
	$(CC) $(FLAGS) src/mainTest.cpp -o obj/mainTest.o $(LIBS_SDL)

obj/mainExemple.o: src/mainExemple.cpp
	$(CC) $(FLAGS) src/mainExemple.cpp -o obj/mainExemple.o $(LIBS_SDL)

obj/Image.o: src/Image.cpp src/Image.h src/Pixel.h  
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/Image.cpp -o obj/Image.o $(LIBS_SDL)

obj/Pixel.o: src/Pixel.cpp src/Pixel.h
	$(CC) $(FLAGS) src/Pixel.cpp -o obj/Pixel.o 

clean:
	rm -rf obj/*.o bin/*

clean_all:
	rm -rf obj/*.o bin/* data/*
