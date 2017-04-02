//
// Created by rafael on 26/03/17.
//

#include <iostream>
#include "Cardapio.h"

using namespace std;

void Cardapio::addComida(const unsigned int id, const unsigned int tempo, const string &nome) {
    Comida comida(id,tempo,nome);

    listC.push_back(comida);
}

Comida *Cardapio::buscarComida(const unsigned int id) {
    for (int i = 0; i < listC.size(); ++i) {
        if (listC[i].getId() == id) {
            return  &listC[i];
        }
    }
    return nullptr;

}

