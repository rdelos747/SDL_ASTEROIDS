CXX = clang++
SDL = -I/usr/local/include -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL)
EXE = asteroids
OBJS = ship.o asteroid.o asteroidCreator.o
LIBRARY = ../SDL_LIBRARY/lib.a

all: $(EXE)

$(EXE): main.o $(OBJS)
	$(CXX) $(LDFLAGS) main.o $(LIBRARY) $(OBJS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

asteroid.o: ./classes/asteroid/asteroid.cpp ./classes/asteroid/asteroid.h
	$(CXX) $(CXXFLAGS) $< -o $@

asteroidCreator.o: ./classes/asteroid/asteroidCreator.cpp ./classes/asteroid/asteroidCreator.h
	$(CXX) $(CXXFLAGS) $< -o $@

ship.o: classes/ship/ship.cpp classes/ship/ship.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)