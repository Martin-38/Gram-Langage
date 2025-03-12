#include "automate.h"
#include "etat.h"
#include "symbole.h"
#include "lexer.h"
#include "expression.h"
#include <iostream>
#include <chrono>  // Pour std::chrono::seconds
#include <thread>  // Pour std::this_thread::sleep_for


using namespace std;

Automate::Automate(string flux) { 
  this->lexer = new Lexer(flux);
  Etat0 * depart = new Etat0();
  depart->print();
  pileEtats.push(depart);
} 

Automate::~Automate() {
    // Suppression des états dans la pile
    while (!pileEtats.empty()) {
        delete pileEtats.top();
        pileEtats.pop();
    }

    // Suppression des symboles dans la pile
    while (!pileSymboles.empty()) {
        delete pileSymboles.top();
        pileSymboles.pop();
    }

    // Suppression du lexer
    delete lexer;
}



void Automate::run() {
    bool prochainEtat = false;
    while (!prochainEtat) {
        this->AffichePileEtats();
        this->AffichePileSymboles();
        Symbole * s = lexer->Consulter(); // Assign a value to 's'
        s->Affiche();
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause de 1 seconde
        //lexer->Avancer();
        prochainEtat = pileEtats.top()->transition(*this, s);
    }
    //JE N'AI PAS GERER LES TRUES
    if (*pileSymboles.top() != ERREUR) {
        // int resultat = pileSymboles.top()->getValue();
        // cout << "Syntaxe correct" << endl << "Résultat : " << resultat << endl;
        cout << "\nSyntaxe correcte" << endl;
        Expression* finale = (Expression*) pileSymboles.top();
        cout << "Le résultat de votre calcul est : ";
        cout << finale->eval() << endl;
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
    //pileSymboles.push(s);
    pileEtats.push(e);
}

void Automate::reduction(int n, Symbole * s) {
    cout << "DEBUT REDUCTION" << endl;
    this->AffichePileEtats();
    this->AffichePileSymboles();
    for (int i = 0; i < n; i++) {
        delete pileEtats.top();
        pileEtats.pop();
    }
    pileSymboles.push(s);
    cout << "MI REDUCTION" << endl;
    this->AffichePileEtats();
    this->AffichePileSymboles();
    pileEtats.top()->transition(*this, s);
    cout << "FIN REDUCTION" << endl;
    this->AffichePileEtats();
    this->AffichePileSymboles();
}

Entier * Automate::popSymbole() {
    Entier * s = (Entier*) pileSymboles.top();
    pileSymboles.pop();
    return s;
}

void Automate::popAndDestroySymbole() {
    delete pileSymboles.top();
    pileSymboles.pop();
}

void Automate::AffichePileEtats() {
    std::cout << "Pile des états : ";
    std::stack<Etat*> temp = pileEtats;
    while (!temp.empty()) {
        temp.top()->print();
        temp.pop();
    }
    std::cout << std::endl;
}

void Automate::AffichePileSymboles() {
    std::cout << "Pile des symboles : ";
    std::stack<Symbole*> temp = pileSymboles;
    while (!temp.empty()) {
        temp.top()->Affiche();
        cout<<endl;
        temp.pop();
    }
    std::cout << std::endl;
}

