COMP=g++
CPFLAGS=-O3 -ansi -pedantic -Wall -Wextra -std=c++11
CPDBGFLAGS=-g -D MAP

exe: main.o Automate.o Lexer.o State.o Symbole.o
	g++ -o exe main.o Automate.o Lexer.o State.o Symbole.o

main.o: main.cpp 
	g++ -c main.cpp $(CPFLAGS) $(CPDBGFLAGS)

Automate.o: Automate.cpp Automate.h
	g++ -c Automate.cpp $(CPFLAGS) $(CPDBGFLAGS)

Lexer.o: Lexer.cpp Lexer.h
	g++ -c Lexer.cpp $(CPFLAGS) $(CPDBGFLAGS)

State.o: State.cpp State.h
	g++ -c State.cpp $(CPFLAGS) $(CPDBGFLAGS)

Symbole.o: Symbole.cpp Symbole.h
	g++ -c Symbole.cpp $(CPFLAGS) $(CPDBGFLAGS)