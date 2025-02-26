#include "etat.h"
#include "automate.h"
#include "symbole.h"
#include "expression.h"
#include <iostream>

Etat::Etat(const string name) : name(name) {}
~Etat::Etat();

bool Etat0::transition(Automate & automate, Symbole* s){
    switch(*s){
        case INT:
            automate.decalage(s, new Etat3());
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2());
            break;
        case EXPR:
            automate.transitionSimple(s, new Etat1());
            break;
        case default:
            cout<<"Erreur de syntaxe"<<endl;
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
        case default:
            cout<<"Erreur de syntaxe"<<endl;
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
            automate.transitionSimple(s, new Etat6())
        case default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}


//PB ETAT 3 AVEC REDUCS
bool Etat3::transition(Automate & automate, Symbole* s){
    switch(*s){
        case PLUS:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.reduction(1, s1);
            break;
        case MULT:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.reduction(1, s1);
            break;
        case CLOSEPAR:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.reduction(1, s1);
            break;
        case FIN:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.reduction(1, s1);
            break;
        case default:
            cout<<"Erreur de syntaxe"<<endl;
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
        case default:
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
        case default:
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
        case default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}

//PB REDUCTION
bool Etat7::transition(Automate & automate, Symbole* s){
    switch(*s){
        case PLUS:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            Expression* s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur + s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case CLOSEPAR:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            Expression* s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur + s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case FIN:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            Expression* s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur + s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}

//PB REDUCTION
bool Etat8::transition(Automate & automate, Symbole* s){
    switch(*s){
        case PLUS:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            Expression* s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur * s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case MULT:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            Expression* s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur * s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case CLOSEPAR:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            Expression* s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur * s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case FIN:
            Expression* s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            Expression* s2 = (Expression*) automate.popSymbole();
            s1->valeur = s1->valeur * s2->valeur;
            delete(s2);
            automate.reduction(3, s1);
            break;
        case default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}

//PB REDUCTION
bool Etat9::transition(Automate & automate, Symbole* s){
    switch(*s){
        case PLUS:
            automate.popAndDestroySymbole();
            Expression * s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, s1);
            break;
        case MULT:
            automate.popAndDestroySymbole();
            Expression * s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, s1);
            break;
        case CLOSEPAR:
            automate.popAndDestroySymbole();
            Expression * s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, s1);
            break;  
        case FIN:
            automate.popAndDestroySymbole();
            Expression * s1 = (Expression*) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, s1);
            break;
        case default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}