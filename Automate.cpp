#include "State.h"
#include <iostream>

Automate::Automate(string s) : lexer(Lexer(s)) {
		this->stateStack = *(new deque <State*>());
		this->symbolStack = *(new deque <Symbole*>());

        State0* initState = new State0(); 
        stateStack.push_back(initState);
}

void Automate::lecture() {
    Symbole * s;
    bool isTransitionTrue = true;
    while(isTransitionTrue) {
        s = lexer.Consulter(); 
        s -> Affiche();
        cout << endl;
        if(*s == ERREUR) {
            cout << "Break: symbol error" << endl;
            break;
        }
        if(stateStack.size() <= 0) {
            cout << "Break: empty stack" << endl;
            break;
        }
        lexer.Avancer();
        isTransitionTrue = (stateStack.back())->transition(*this, s);
    }
}

void Automate::decalage(Symbole* s, State* e){
    symbolStack.push_back(s);
    stateStack.push_back(e);
}

void Automate::reduction(Symbole* s, int n) {

}
