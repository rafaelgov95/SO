//
// Created by rafael on 26/03/17.
//

#include <iostream>
#include "Cardapio.h"

using namespace std;

void Cardapio::addComida(string nome, unsigned tempo) {
    Comida comida;
    comida.nome = nome;
    comida.tempo = tempo;
    Cardapio[size] = comida;
    size++;
}

Comida Cardapio::buscarComida(string nomeDaComida) {
    for (int i = 0; i <= size; ++i) {
        if (Cardapio[i].nome.compare(nomeDaComida) == 0) {
            return Cardapio[i];
        }
    }

}

