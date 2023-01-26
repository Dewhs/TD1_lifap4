

all: bin/simple_sdl_imgui bin/demo


bin/simple_sdl_imgui: src/simple_SDL_IMGUI.cpp
	mkdir -p bin; g++ -o bin/simple_sdl_imgui src/simple_SDL_IMGUI.cpp src/imgui/*.cpp -Isrc/imgui -I/usr/include/SDL2 -lSDL2 -lSDL2_image -lSDL2_ttf -ldl -lGL -lGLEW

bin/demo: src/demo.cpp
	mkdir -p bin ; g++ -o bin/demo src/demo.cpp src/imgui/*.cpp -Isrc/imgui -I/usr/include/SDL2 -lSDL2 -lSDL2_image -lSDL2_ttf -ldl -lGL

clean:
	rm -rf bin/*
