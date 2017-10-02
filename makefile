SRC = src
INC = include
OBJ = obj
BIN = bin
# LIB = lib

all: $(BIN)/crearMatriz $(BIN)/main

$(BIN)/crearMatriz: $(SRC)/crearMatriz.cpp
	g++ -std=c++11 $(SRC)/crearMatriz.cpp -o $(BIN)/crearMatriz

$(OBJ)/incendioforestal.o: $(SRC)/incendioforestal.cpp $(INC)/incendioforestal.h
	g++ -c $(SRC)/incendioforestal.cpp -std=c++11 -o $(OBJ)/incendioforestal.o -I$(INC)

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/incendioforestal.h
	g++ -c $(SRC)/main.cpp -std=c++11 -o $(OBJ)/main.o -I$(INC)

$(BIN)/main: $(OBJ)/incendioforestal.o $(OBJ)/main.o
	g++ -o $(BIN)/main $(OBJ)/main.o $(OBJ)/incendioforestal.o -I$(INC)


clean:
	rm bin/* obj/*
