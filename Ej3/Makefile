# Makefile para Ej3 - Simulación de Batalla

CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Wpedantic -Werror \
           -Wshadow -Wnull-dereference -I../Ej1 -I../Ej2


SRC = batalla.cpp \
      ../Ej1/ItemsCombate.cpp \
      ../Ej1/ItemsMagicos.cpp \
      ../Ej1/PersonajesGuerrero.cpp \
      ../Ej1/PersonajesMagicos.cpp \
      ../Ej2/PersonajeFactory.cpp

OBJ = $(SRC:.cpp=.o)
EXEC = Ej3.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJ)

.PHONY: all clean valgrind
