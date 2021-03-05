#include <iostream>
#include "Automate.h"

int main(int argc, char *argv[]) {
   // Enter expression as parameter
   std::string chaine(argv[1]);
   Automate* a = new Automate(chaine);
   a->lecture();
   a->afficherResultat();
  
   return 0;
}

