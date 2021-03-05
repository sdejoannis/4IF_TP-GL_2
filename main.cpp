#include <iostream>
#include "Automate.h"

int main(int argc, char *argv[]) {
   // Enter expression as parameter

   if( argc == 2) {
      std::string chaine(argv[1]);
      Automate* a = new Automate(chaine);
      a->lecture();
      a->afficherResultat();
   } else {
      cout << "Format: ./exe EXRESION " << endl;
      cout << "Mettre des guillemets autour de EXPRESSION" << endl;
   }
   
  
   return 0;
}

