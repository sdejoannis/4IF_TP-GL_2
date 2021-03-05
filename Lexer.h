#pragma once

#include <string>
#include "Symbole.h"

class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { };
      ~Lexer() { };

      Symbole * Consulter();
      void Avancer();
      void setSymbole(Symbole* s);

   protected:
      string flux;
      int tete;
      Symbole * tampon;
};
