//classe dans laquelle sera l'expression non terminale
#include "expression.h"


int Expression::eval() {
  return this->valeur;
}

void Expression::set_valeur(int val){
    this->valeur = val;
}