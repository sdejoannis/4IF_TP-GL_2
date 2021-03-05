#include "Symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}
bool Symbole::isTerminal(){
	if (ident!=7){
		return true;
	}
	return false;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expression::Affiche() {
   Symbole::Affiche();
   cout<<"("<<value<<")";
}

int Symbole::getValue(){ 
   return -1; 
}

int Expression::getValue(){
   return value; 
}

int Entier::getValue(){
   return valeur; 
}

void Expression::setValue(int v) {
   value = v;
};
