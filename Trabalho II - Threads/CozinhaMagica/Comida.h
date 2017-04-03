//
// Created by rafael on 26/03/17.
//

#ifndef COZINHAMAGICA_COMIDA_H
#define COZINHAMAGICA_COMIDA_H

#include <iostream>

using namespace std;

class Comida {
private:
    unsigned int id;
    string nome;
    unsigned int tempo;

public:

    Comida(const unsigned int id, const unsigned int tempo, const string &nome)
            : id(id), tempo(tempo), nome(nome) {
    };
    Comida(const Comida& orig) : id(orig.id),tempo(orig.tempo),nome(orig.nome) {
    }
    unsigned int getId() const {
        return id;
    }

    const string &getNome() const {
        return nome;
    }

    unsigned int getTempo() const {
        return tempo;
    }

};
#endif //COZINHAMAGICA_COMIDA_H
