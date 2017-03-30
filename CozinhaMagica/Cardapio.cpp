//
// Created by rafael on 26/03/17.
//

#include <iostream>
#include "Cardapio.h"

using namespace std;

void Cardapio::addComida(unsigned int id, unsigned int tempo, string nome) {
    Comida comida;
    comida.id;
    comida.tempo = tempo;
    comida.nome = nome;
    Cardapio[size] = comida;
    size++;
}

Comida Cardapio::buscarComida( unsigned int id) {
    for (int i = 0; i <= size; ++i) {
        if (Cardapio[i].id == id) {
            return Cardapio[i];
        }
    }
    return nullptr;

}

