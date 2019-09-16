CC = @g++

LINK_FLAGS  = -fopenmp
CFLAGS = -ffast-math -O3 -Ofast -march=native -D_GLIBCXX_PARALLEL  -std=c++11

EXE = main
SRC = main.cpp

LIB_FILES = apply_gate.cpp gates.cpp state_vector.cpp

all: 
	$(CC) $(SRC) $(LIB_FILES) -o $(EXE) $(CFLAGS) $(LINK_FLAGS)

clean: 
	rm main