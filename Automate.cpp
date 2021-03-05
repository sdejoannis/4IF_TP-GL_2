#include "State.h"
#include <iostream>
#include <list>

Automate::Automate(string s) : isAccepted(false),lexer(Lexer(s)), chaine(s) {
		this->stateStack = *(new deque <State*>());
		this->symbolStack = *(new deque <Symbole*>());

        State0* initState = new State0(); 
        stateStack.push_front(initState);
}

void Automate::lecture() {
    Symbole * s;
    int cpt = 0;
    bool isTransitionTrue = true;
    while(isTransitionTrue) {
        cout << endl;
        cpt++;
        cout << " -- Start Curseur " << cpt << " ";
        s = lexer.Consulter();
        s->Affiche();
        cout << endl; 
        isTransitionTrue = (stateStack.front())->transition(*this, s);
        cout << " -- End Curseur " << cpt << endl;
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
}

void Automate::reduction(Symbole* s, int n) {
    
    bool isAddition = false;
    int nbExpr = 0;
    int val = -2;
    int valExpr1 = -2;
    int valExpr2 = -2;

    for(int i=1 ; i <= n ; ++i) {
         cout << "EXPRE 1: " << symbolStack.front()->getValue() << endl;
        if(*(symbolStack.front())==EXPR) 
        {
            nbExpr++;

            if (n<=2)
            valExpr1 = symbolStack.front()->getValue();

            if (n==3)
            valExpr2 = symbolStack.front()->getValue();
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

   symbolStack.push_front(new Symbole(EXPR));

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
   cout << "value " << value << endl;
    Expression * newExpression = new Expression(value);
    stateStack.front()->transition(*this, newExpression);
}

void Automate::afficherResultat() {
    cout << "L'expression "<< chaine;

   if(this->isAccepted == true) {
        cout << " a été analysée avec succès. " << endl;
        cout << chaine << " = " << symbolStack.front()->getValue() <<endl;
    } else {
        cout << " n'est pas valide pour cette grammaire. " << endl;
    }
}