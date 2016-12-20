//
// Created by rafael on 20/12/16.
//

#include "Cozinheiro.h"

using namespace std;

Cozinheiro::Cozinheiro() {

}

int Cozinheiro::getNumeroMesa() {
    return numero_da_mesa;
}

void Cozinheiro::setNumeroMesa(int n) {
    this->numero_da_mesa = n;
}