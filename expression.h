#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>
#include <map>

#include "symbole.h"

using namespace std;

class Expression : public Symbole {
    protected:
    //Pour stocker la valeur de l'expression
    int valeur;
  
    public:  
    Expression(int valeur):Symbole(EXPR),valeur(valeur) {} 
    ~Expression() {}
    int eval();
    void set_valeur(int val);
};


#endif 