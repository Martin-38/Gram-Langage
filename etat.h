#pragma once

#include <string>
#include "symbole.h"
using namespace std;

#ifndef ETAT_H
#define ETAT_H

class Automate; // Pré-déclaration de la classe Automate

class Etat {
public:
    Etat(string name); 
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate & automate, Symbole* s)=0; 
#La classe etat est une classe abstraite

protected:
    string name; // Déclaration du pointeur

};

#endif // ETAT_H

class Etat0 : protected Etat {
    public:
    Etat0(string name);
    ~Etat0();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }

class Etat1 : protected Etat {
    public:
    Etat1(string name);
    ~Etat1();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }

class Etat2 : protected Etat {
    public:
    Etat2(string name);
    ~Etat2();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }

class Etat3 : protected Etat {
    public:
    Etat3(string name);
    ~Etat3();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }

class Etat4 : protected Etat {
    public:
    Etat4(string name);
    ~Etat4();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }

class Etat5 : protected Etat {
    public:
    Etat5(string name);
    ~Etat5();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }

class Etat6 : protected Etat {
    public:
    Etat6(string name);
    ~Etat6();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }

class Etat7 : protected Etat {
    public:
    Etat7(string name);
    ~Etat7();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }

class Etat8: protected Etat {
    public:
    Etat8(string name);
    ~Etat8();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }

class Etat9 : protected Etat {
    public:
    Etat9(string name);
    ~Etat9();
    void print() const;
    bool transition(Automate & automate, Symbole* s);
    protected:
    }