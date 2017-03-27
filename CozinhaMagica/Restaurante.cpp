//
// Created by rafael on 26/03/17.
//

#include "Restaurante.h"

Restaurante::Restaurante() {
    for (int i = 0; i < 10; ++i) {
        AdicionarCozinheiroDisponivel(i);
    }
}

int Restaurante::BuscarCozinheiroDisponivel() {
    if (!cozDisp.empty()) {
        int index = cozDisp.front();
        cozDisp.pop();
        return index;
    }
    return -1;
}

void Restaurante::AdicionarCozinheiroDisponivel(int coz) {
    cozDisp.push(coz);
}

void Restaurante::EnviarPedido(Comida comida) {
    int index = BuscarCozinheiroDisponivel();
    cout << "Cozinhero Nº " << index << endl;
    cozz[index].EnviarPedido(comida);


}
