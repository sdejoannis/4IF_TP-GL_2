using namespace std;

#include <string>
#include <deque>
#include <iostream>
#include "Symbole.h"
#include "Lexer.h"

class State;

class Automate {
	public:	
	Automate(string s);
	virtual ~Automate(){};
	void print()const;
	void lecture();
	void decalage(Symbole* s, State* e);

	protected:
	Lexer lexer;
	deque <State*> stateStack;
	deque <Symbole*> symbolStack;
};
