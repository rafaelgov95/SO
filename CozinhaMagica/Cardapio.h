//
// Created by rafael on 26/03/17.
//

#ifndef COZINHAMAGICA_CARDAPIO_H
#define COZINHAMAGICA_CARDAPIO_H

#include <string>
#include <queue>
#include "Comida.h"

using namespace std;

class Cardapio {
public:
    void addComida(unsigned int id, unsigned int tempo, string name);
    Comida buscarComida(unsigned int id);

private:

    Comida Cardapio[100];
    unsigned int size = 0;
};


#endif //COZINHAMAGICA_CARDAPIO_H
