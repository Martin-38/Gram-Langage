#include "automate.h"
#include "etat.h"
#include "symbole.h"
#include "lexer.h"
#include <iostream>

using namespace std;

Automate::Automate(string flux) { //flux c est l expression : par exemple : 3+4*6 
  this->lexer = new Lexer(flux);
  Etat0 * depart = new Etat0();
  pileEtats.push(depart);
} 

void Automate::run() {
    bool prochainEtat = true;

    while (!prochainEtat) {
        Symbole * s = lexer->Consulter(); // Assign a value to 's'
        lexer->Avancer();
        prochainEtat = pileEtats.top()->transition(*this, s);
    }
    //JE N'AI PAS GERER LES TRUES
    if (*pileSymboles.top() != ERREUR) {
        // int resultat = pileSymboles.top()->getValue();
        // cout << "Syntaxe correct" << endl << "Résultat : " << resultat << endl;
        cout << "Syntaxe correct" << endl;
    } else {
        cout << "Syntaxe non reconnu : caractere invalide" << endl;
    }
    pileSymboles.top()->Affiche();
}

void Automate::decalage(Symbole * s, Etat * e) {
    pileSymboles.push(s);
    pileEtats.push(e);
    lexer->Avancer(); // A VERIFIER S'IL Y A VRMT BESOIN D'UN AVANCEMENT
}

void Automate::transitionSimple(Symbole * s, Etat * e) {
    pileSymboles.push(s);
    pileEtats.push(e);
}

void Automate::reduction(int n, Symbole * s) {
    for (int i = 0; i < n; i++) {
        delete pileEtats.top();
        pileEtats.pop();
    }
    pileSymboles.push(s);
    pileEtats.top()->transition(*this, s);
}

Symbole * Automate::popSymbole() {
    Symbole * s = pileSymboles.top();
    pileSymboles.pop();
    return s;
}

void Automate::popAndDestroySymbole() {
    delete pileSymboles.top();
    pileSymboles.pop();
}

