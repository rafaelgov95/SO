//
// Created by rafael on 26/03/17.
//

#ifndef COZINHAMAGICA_CARDAPIO_H
#define COZINHAMAGICA_CARDAPIO_H

#include <string>
#include <queue>
#include <list>
#include "Comida.h"

using namespace std;

class Cardapio {
public:
    void addComida(const unsigned int id, const unsigned int tempo, const string &name);
    Comida *buscarComida(const unsigned int id);

private:
    vector<Comida> listC;
};


#endif //COZINHAMAGICA_CARDAPIO_H
