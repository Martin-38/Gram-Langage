#pragma once

#include <stack>
#include <string>
#include "etat.h"
#include "symbole.h"
#include "expression.h"
#include "lexer.h"



using namespace std;

class Automate {

   public:
      Automate(string flux);
      ~Automate();
      void decalage(Symbole *s, Etat *e);
      void transitionSimple(Symbole *s, Etat *e);
      void reduction(int n, Symbole *s);
      void run();
      void AffichePileEtats();
      void AffichePileSymboles();
      Entier * popSymbole();
      void popAndDestroySymbole();

   protected:
      std::stack<Etat*> pileEtats;
      std::stack<Symbole*> pileSymboles;
      Lexer * lexer;   
};