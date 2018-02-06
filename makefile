#compiler
CXX = clang++
#compiler flags
CXXFLAGS = -Wall -c -std=c++11
#linked frameworks
LDFLAGS = -framework SDL2 -framework SDL2_image
#name of executable
EXE = ASTEROIDS
#list of objects
OBJS = ship.o bullet.o asteroidcreator.o asteroid.o
LIBRARY = ../SDL_LIBRARY/functions.o ../SDL_LIBRARY/sprite.o ../SDL_LIBRARY/object.o

all: $(EXE)

$(EXE): main.o $(LIBRARY) $(OBJS)
	$(CXX) $(LDFLAGS) main.o $(LIBRARY) $(OBJS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

ship.o: CLASSES/ship.cpp CLASSES/ship.h
	$(CXX) $(CXXFLAGS) $< -o $@

bullet.o: CLASSES/bullet.cpp CLASSES/bullet.h
	$(CXX) $(CXXFLAGS) $< -o $@

asteroidcreator.o: CLASSES/asteroidCreator.cpp CLASSES/asteroidCreator.h
	$(CXX) $(CXXFLAGS) $< -o $@

asteroid.o: CLASSES/asteroid.cpp CLASSES/asteroid.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)

#library: $(OBJS)
#
#../SDL_LIBRARY/functions.o: ./../SDL_LIBRARY/FUNCTIONS/functions.cpp ./../SDL_LIBRARY/FUNCTIONS/functions.h
#	$(CXX) $(CXXFLAGS) $< -o $@
#
#../SDL_LIBRARY/sprite.o: ./../SDL_LIBRARY/FUNCTIONS/sprite.cpp ./../SDL_LIBRARY/FUNCTIONS/sprite.h
#	$(CXX) $(CXXFLAGS) $< -o $@
#
#../SDL_LIBRARY/object.o : ./../SDL_LIBRARY/FUNCTIONS/object.cpp ./../SDL_LIBRARY/FUNCTIONS/object.h
#	$(CXX) $(CXXFLAGS) $< -o $@