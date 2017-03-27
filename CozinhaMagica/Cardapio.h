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
    void addComida(string name, unsigned int tempo);

    Comida buscarComida(string nomeDaComida);

private:

    Comida Cardapio[100];
    unsigned int size=0;
};


#endif //COZINHAMAGICA_CARDAPIO_H
