#pragma once

#include <string>
#include "symbole.h"
using namespace std;

#ifndef ETAT_H
#define ETAT_H

class Automate; // Pré-déclaration de la classe Automate

class Etat {
public:
    Etat();
    Etat(string name); 
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate & automate, Symbole* s)=0; 
//La classe etat est une classe abstraite

protected:
    string name; // Déclaration du pointeur

};

#endif // ETAT_H

class Etat0 : public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };

class Etat1 : public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };

class Etat2 : public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };

class Etat3 : public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };

class Etat4 : public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };

class Etat5 : public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };

class Etat6 : public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };

class Etat7 : public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };

class Etat8: public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };

class Etat9 : public Etat {
    public:
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    };