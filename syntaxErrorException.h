#ifndef SYNTAX_ERROR_EXCEPTION_H
#define SYNTAX_ERROR_EXCEPTION_H

#include <exception>
//Classe exception servant à gérer les erreurs de syntaxe
class SyntaxErrorException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur de syntaxe détectée";
    }
};

#endif // SYNTAX_ERROR_EXCEPTION_H
