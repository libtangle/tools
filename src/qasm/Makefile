all: parser

clean:
	rm parser.cpp parser.hpp parser tokens.cpp

parser.cpp: parser.y
	bison -d -o $@ $^
    
parser.hpp: parser.cpp

tokens.cpp: tokens.l parser.hpp
	flex -o $@ $^

parser: parser.cpp main.cpp tokens.cpp
	g++ -o $@ *.cpp -std=c++11