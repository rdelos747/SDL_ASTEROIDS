CXX = clang++
SDL = -I/usr/local/include -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL)
EXE = asteroids
OBJS = main.o
LIBRARY = ../SDL_LIBRARY/lib.a

all: $(EXE)

$(EXE): main.o
	$(CXX) main.o $(LIBRARY) $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)