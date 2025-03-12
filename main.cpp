#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "syntaxErrorException.h"
#include <string>


int main(int argc, char* argv[]) {
   string chaine;
    if (argc > 1) {
        chaine = argv[1]; // Utilisation de l'argument passé par l'utilisateur
    } else {
        chaine = "1+3*2+22"; // Valeur par défaut si aucun argument n'est fourni
    }
   Automate* automate = new Automate(chaine);
   try{
      automate->run();
   } catch (const SyntaxErrorException& e){} //Utilisation des exceptions pour une sortie propre du programme
   delete automate;
   return 0;
}

