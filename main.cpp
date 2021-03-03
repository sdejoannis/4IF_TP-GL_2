#include <iostream>
#include "Lexer.h"
#include "Automate.h"

int main(void) {
   string chaine("(1+34)*123");

   Automate* a = new Automate(chaine);
   cout << "Start lecture" << endl;
   a->lecture();
   cout << "End lecture" << endl;
   /*
   Lexer l(chaine);

   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }*/
   return 0;
}

