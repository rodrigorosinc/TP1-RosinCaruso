CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g
SRC = ItemsCombate.cpp ItemsMagicos.cpp PersonajesGuerrero.cpp PersonajesMagicos.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXE = Ej1.exe

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

valgrind: $(EXE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXE)

clean:
	rm -f $(OBJ) $(EXE)
