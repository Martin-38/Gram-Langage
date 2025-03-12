#include "automate.h"
#include "etat.h"
#include "symbole.h"
#include "lexer.h"
#include "expression.h"
#include"syntaxErrorException.h"
#include <iostream>


using namespace std;

Automate::Automate(string flux) { 
  this->lexer = new Lexer(flux);
  Etat0 * depart = new Etat0();
  pileEtats.push(depart);
  compteur = 1;
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
    try{
        bool prochainEtat = false;
        while (!prochainEtat) {
            Symbole * s = lexer->Consulter(); // Le symbole suivant est consulté grace au lexeur
            prochainEtat = pileEtats.top()->transition(*this, s);
        }
        if (*pileSymboles.top() != ERREUR) { //Le dernier symbole restant est soit une erreur soit l'expression finale
            cout << "\nSyntaxe correcte" << endl;
            Expression* finale = (Expression*) pileSymboles.top();
            cout << "Le résultat de votre calcul est : ";
            cout << finale->eval() << endl;
        } else {
            cout << "Syntaxe non reconnu : caractère invalide" << endl;
        }
    } catch(const SyntaxErrorException& e) {}
}

void Automate::decalage(Symbole * s, Etat * e) {
    pileSymboles.push(s); //En cas de décalage, on prend le symbole suivant
    augmenterDeUnCompteur(); // On augmente le compteur pour savoir à quelle position de la chaîne on est.
    pileEtats.push(e);
    lexer->Avancer(); 
}

void Automate::transitionSimple(Symbole * s, Etat * e) {
// Transition simple : après une réduction, on fait une transition simple vers le prochain etat sans consommer un nouveau symbole
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

Entier * Automate::popSymbole() {
    //Le symbole n'est pas delete car il sera réutilisé plus tard.
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
} // Pour l'affichage de la pile des etats.

void Automate::AffichePileSymboles() {
    std::cout << "Pile des symboles : ";
    std::stack<Symbole*> temp = pileSymboles;
    while (!temp.empty()) {
        temp.top()->Affiche();
        cout<<endl;
        temp.pop();
    }
    std::cout << std::endl;
} //Pour l'affichage de la pile des symboles.

int Automate::getCompteur(){
    return compteur;
}

void Automate::augmenterDeUnCompteur(){
    compteur++;
} // Ce compteur représente la position du caractère étudié dans la chaîne initiale. Il permet de signaler plus précisément les erreurs.


