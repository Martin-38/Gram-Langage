#pragma once

#include <string>
#include "etat.h"


using namespace std;

class Automate {

   public:
      Automate(string flux);
      void decalage(Symbole *s, Etat *e);
      void reduction(int n, Symbole *s);
      void run();
      Symbole * popSymbole();
      void popAndDestroySymbole();
      // Il faut que je rajoute une transition simple ? 

   protected:
      stack<Etat*> pileEtats;
      stack<Symbole*> pileSymboles;
      Lexer * lexer;   
};