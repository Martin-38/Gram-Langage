#pragma once

#include <string>
using namespace std;

#ifndef ETAT_H
#define ETAT_H

class Automate; // Pré-déclaration de la classe Automate

class Etat {
public:
    Etat(Automate* automate); // Utilisation d'un pointeur vers Automate
    void transition();

private:
    Automate* automate_; // Déclaration du pointeur
};

#endif // ETAT_H
