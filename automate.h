#pragma once

#include <stack>
#include <string>
#include "etat.h"
#include "symbole.h"
#include "lexer.h"



using namespace std;

class Automate {

   public:
      Automate(string flux);
      void decalage(Symbole *s, Etat *e);
      void transitionSimple(Symbole *s, Etat *e);
      void reduction(int n, Symbole *s);
      void run();
      Symbole * popSymbole();
      void popAndDestroySymbole();
      // Il faut que je rajoute une transition simple ? 

   protected:
      std::stack<Etat*> pileEtats;
      std::stack<Symbole*> pileSymboles;
      Lexer * lexer;   
};