# Makefile para Ej2 sin carpeta obj

# Compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -I../Ej1 -I.

# Carpetas
SRC_EJ2 = .
SRC_EJ1 = ../Ej1
BIN = .

# Archivos fuente
SRCS = \
	$(SRC_EJ2)/main.cpp \
	$(SRC_EJ2)/PersonajeFactory.cpp \
	$(SRC_EJ1)/PersonajesMagicos.cpp \
	$(SRC_EJ1)/PersonajesGuerrero.cpp \
	$(SRC_EJ1)/ItemsMagicos.cpp \
	$(SRC_EJ1)/ItemsCombate.cpp

# Archivos objeto (misma carpeta que los cpp)
OBJS = $(SRCS:.cpp=.o)

# Ejecutable
EXEC = $(BIN)/main.exe

# Regla principal
all: $(EXEC)

# Linkeo final
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilación de cada archivo .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f *.o ../Ej1/*.o $(EXEC)

.PHONY: all clean
