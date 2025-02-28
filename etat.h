#pragma once

#include <string>
#include "symbole.h"
#include <string>
using namespace std;

#ifndef ETAT_H
#define ETAT_H

class Automate; // Pré-déclaration de la classe Automate

class Etat {
public:
    Etat();
    Etat(string name); 
    virtual ~Etat();
    virtual void print() const;
    virtual bool transition(Automate & automate, Symbole* s)=0; 
//La classe etat est une classe abstraite

protected:
    string name; // Déclaration du pointeur

};

#endif // ETAT_H

class Etat0 : public Etat {
    public:
    Etat0();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };

class Etat1 : public Etat {
    public:
    Etat1();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };

class Etat2 : public Etat {
    public:
    Etat2();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };

class Etat3 : public Etat {
    public:
    Etat3();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };

class Etat4 : public Etat {
    public:
    Etat4();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };

class Etat5 : public Etat {
    public:
    Etat5();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };

class Etat6 : public Etat {
    public:
    Etat6();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };

class Etat7 : public Etat {
    public:
    Etat7();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };

class Etat8: public Etat {
    public:
    Etat8();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };

class Etat9 : public Etat {
    public:
    Etat9();
    bool transition(Automate & automate, Symbole* s);
    protected:
    string name;
    };