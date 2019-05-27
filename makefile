CXX = clang++
SDL = -I/usr/local/include -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL)
EXE = asteroids
OBJS = ship.o
LIBRARY = ../SDL_LIBRARY/lib.a

all: $(EXE)

$(EXE): main.o $(OBJS)
	$(CXX) $(LDFLAGS) main.o $(LIBRARY) $(OBJS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

ship.o: classes/ship/ship.cpp classes/ship/ship.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)