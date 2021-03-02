using namespace std;

#include <string>
#include <deque>
#include "Symbole.h"
#include "Lexer.h"

class State;

class Automate {
	public:	Automate(Lexer l): lexer(l) {
		stateStack = *(new deque <State*>());
		symbolStack = *(new deque <Symbole*>());
	};
	virtual ~Automate();
	void print()const;
	void decalage(Symbole* s, State* e){
		symbolStack.push_back(s);
		stateStack.push_back(e);
		if (s->isTerminal()){
			lexer.Avancer();
		}
	};
	protected:
	Lexer lexer;
	deque <State*> stateStack;
	deque <Symbole*> symbolStack;
};
