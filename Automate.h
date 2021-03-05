
#include <string>
#include <deque>
#include <iostream>
#include "Symbole.h"
#include "Lexer.h"

class State;

using namespace std;

class Automate {
	public:	
	Automate(string s);
	virtual ~Automate(){};
	void print()const;
	void lecture();
	void decalage(Symbole* s, State* e);
	void reduction(Symbole* s, int n);
	
	protected:
	Lexer lexer;
	deque <State*> stateStack;
	deque <Symbole*> symbolStack;
};
