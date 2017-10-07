CXX = g++
CXXFLAGS = -Wall

proj2: MyPokemon.o Pokemon.o
        $(CXX) $(CXXFLAGS) MyPokemon.o Pokemon.o proj2.cpp -o proj2

MyPokemon.o: MyPokemon.cpp MyPokemon.h
        $(CXX) $(CXXFLAGS) -c MyPokemon.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
        $(CXX) $(CXXFLAGS) -c Pokemon.cpp

clean:
        rm *.o
        rm *~

run:
        ./proj2

