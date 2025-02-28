#include <iostream>
#include <string>
#include "etat.h"
#include "automate.h"
#include "symbole.h"
#include "expression.h"
#include <iostream>

using namespace std;

Etat::Etat(const string name) : name(name) {}
Etat::Etat() : name("Default") {}
Etat::~Etat() {}
void Etat::print() const{
    cout << this->name <<endl ;
}

Etat0::Etat0() : Etat("Etat 0") {}
Etat1::Etat1() : Etat("Etat 1") {}
Etat2::Etat2() : Etat("Etat 2") {}
Etat3::Etat3() : Etat("Etat 3") {}
Etat4::Etat4() : Etat("Etat 4") {}
Etat5::Etat5() : Etat("Etat 5") {}
Etat6::Etat6() : Etat("Etat 6") {}
Etat7::Etat7() : Etat("Etat 7") {}
Etat8::Etat8() : Etat("Etat 8") {}
Etat9::Etat9() : Etat("Etat 9") {}

bool Etat0::transition(Automate & automate, Symbole* s){
    switch(static_cast<int>(*s)){
        case INT:
            automate.decalage(s, new Etat3());
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2());
            break;
        case EXPR:
            automate.transitionSimple(s, new Etat1());
            break;
        default:
            cout<<"Erreur de syntaxe E0"<<endl;
            break;
    }
    return false;
}

bool Etat1::transition(Automate & automate, Symbole* s){
    switch(*s){
        case PLUS:
            automate.decalage(s, new Etat4());
            break;
        case MULT:
            automate.decalage(s, new Etat5());
            break;
        case FIN:
            return true;
        default:
            cout<<"Erreur de syntaxe E1"<<endl;
            break;
    }
    return false;
}

bool Etat2::transition(Automate & automate, Symbole* s){
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3());
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2());
            break;
        case EXPR:
            automate.transitionSimple(s, new Etat6());
            break;
        default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}


//PB ETAT 3 AVEC REDUCS
bool Etat3::transition(Automate & automate, Symbole* s){
    Entier* s1;
    Expression* s2 ;
    //cout << "Etat 3:";
    //s->Affiche();
    //cout << endl;
    switch(*s){
        case PLUS:
            s1 = (Entier*) automate.popSymbole();
            s2 = new Expression(s1->getValeur());
            automate.reduction(1, s2);
            break;
        case MULT:
            s1 = (Entier*) automate.popSymbole();
            s2 = new Expression(s1->getValeur());
            automate.reduction(1, s2);
            break;
        case CLOSEPAR:
            s1 = (Entier*) automate.popSymbole();
            s2 = new Expression(s1->getValeur());
            automate.reduction(1, s2);
            break;
        case FIN:
            s1 = (Entier*) automate.popSymbole();
            s2 = new Expression(s1->getValeur());
            automate.reduction(1, s2);
            break;
        default:
            cout<<"Erreur de syntaxe E3"<<endl;
            break;
    }
    return false;
}

bool Etat4::transition(Automate & automate, Symbole* s){
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.transitionSimple(s, new Etat7);
            break;
        default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}

bool Etat5::transition(Automate & automate, Symbole* s){
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case EXPR:
            automate.transitionSimple(s, new Etat8);
            break;
        default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}

bool Etat6::transition(Automate & automate, Symbole* s){
    switch(*s){
        case PLUS:
            automate.decalage(s, new Etat4);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new Etat9);
            break;
        default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}

//PB REDUCTION
bool Etat7::transition(Automate & automate, Symbole* s){
    Expression* s1;
    Expression* s2;
    switch(*s){
        case PLUS:
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur + s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case CLOSEPAR:
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur + s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case FIN:
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur + s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        default:
            cout<<"Erreur de syntaxe E7"<<endl;
            break;
    }
    return false;
}

//PB REDUCTION
bool Etat8::transition(Automate & automate, Symbole* s){
    switch(*s){
        Expression* s1;
        Expression* s2;
        case PLUS:
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur * s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case MULT:
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur * s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case CLOSEPAR:
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur * s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case FIN:
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur * s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        default:
            cout<<"Erreur de syntaxe E8"<<endl;
            break;
    }
    return false;
}

//PB REDUCTION
bool Etat9::transition(Automate & automate, Symbole* s){
    switch(*s){
        Expression* s1;
        case PLUS:
            automate.popAndDestroySymbole();
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, s1);
            break;
        case MULT:
            automate.popAndDestroySymbole();
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, s1);
            break;
        case CLOSEPAR:
            automate.popAndDestroySymbole();
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, s1);
            break;  
        case FIN:
            automate.popAndDestroySymbole();
            s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, s1);
            break;
        default:
            cout<<"Erreur de syntaxe E9"<<endl;
            break;
    }
    return false;
}