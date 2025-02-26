#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>
#include <map>

#include "symbole.h"

using namespace std;

class Expression : public Symbole {
    protected:
        int valeur;
  
    public:
        Expression(int valeur):Symbole(EXPR),valeur(valeur) {} 
        ~Expression() {}
        int eval();
};


#endif //GL_TD2_EXPR_H