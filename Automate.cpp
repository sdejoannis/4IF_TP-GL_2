#include "State.h"
#include <iostream>
#include <list>

Automate::Automate(string s) : isAccepted(false),chaine(s), lexer(Lexer(s)) {
		this->stateStack = *(new deque <State*>());
		this->symbolStack = *(new deque <Symbole*>());

        State0* initState = new State0(); 
        stateStack.push_front(initState);
}

void Automate::lecture() {
    Symbole * s;
    bool isTransitionTrue = true;
    while(isTransitionTrue) {
        cout << endl;
        cout << "-- Symbole pointé: ";
        s = lexer.Consulter();
        s->Affiche();
        cout << endl; 
        isTransitionTrue = (stateStack.front())->transition(*this, s);
        if(*(symbolStack.front()) != EXPR) {
            lexer.Avancer();
        }
        if(*s == ERREUR) {
            cout << "Break: symbol error" << endl;
            break;
        }
        if(stateStack.size() <= 0) {
            cout << "Break: empty stack" << endl;
            break;
        }
    }
}

void Automate::decalage(Symbole* s, State* e){
        symbolStack.push_front(s);
        stateStack.push_front(e);
        cout<< "     décalage" << endl;
}

void Automate::reduction(Symbole* s, int n) {
    
    //identification ofthe rule
    bool isAddition = false;
    int nbExpr = 0;
    int val = -2;
    int valExpr1 = -2;
    int valExpr2 = -2;

    for(int i=1 ; i <= n ; ++i) {
        if(*(symbolStack.front())==EXPR) 
        {
            nbExpr++;

            if (i<=2) {
                 valExpr1 = symbolStack.front()->getValue();
            }

            if (i==3) {
                valExpr2 = symbolStack.front()->getValue();
            }
        } 
        else if(*(symbolStack.front())==INT)
        {
            val = symbolStack.front()->getValue();
        }
        else if (*(symbolStack.front())==PLUS) 
        {
            isAddition = true;
        }
        stateStack.pop_front();
        symbolStack.pop_front();
    }
    /*
    cout << "val: " << val << endl;
    cout << "valExpr1: " << valExpr1 << endl;
    cout << "valExpr2: " << valExpr2 << endl;
    */

   //stay with lexer set on same Symbol in main loop 
   lexer.setSymbole(s);

   //calculate value of EXPR
   int value = 0;
   if ( n == 1 ) {
       value = val;
   } 
   else 
   {
       if (nbExpr == 1) 
       {
           value = valExpr1;
       } 
       else if( isAddition == true)
       {
            value = valExpr1 +  valExpr2;
       }
       else 
       {
            value = valExpr1 *  valExpr2;
       }
   }


    Expression * newExpression = new Expression(value);
    symbolStack.push_front(newExpression);
    stateStack.front()->transition(*this, newExpression);
    cout<< "     reduction" << endl;
}

void Automate::afficherResultat() {
    cout << endl << "L'expression "<< chaine;

    if(this->isAccepted == true) {
        cout << " a été analysée avec succès. " << endl << endl;
        cout << chaine << " : " << "nous n'avons malheureusement pas pu terminer l'implémentation du calcul." << endl;//symbolStack.front()->getValue() <<endl;
    } 
    else {
        cout << " n'est pas valide pour cette grammaire. " << endl;
    }
}