//
// Created by rafael on 26/03/17.
//

#include "Restaurante.h"
#include "Pedido.h"

Restaurante::Restaurante() {
    for (int i = 0; i < 10; ++i) {
        AdicionarCozinheiroDisponivel(i);
    }
    for (int j = 0; j < 20; ++j) {
        mesa[j] = 0;
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

void Restaurante::EnviarPedido(Comida comida, int mesa) {
    Pedido p;
    p.mesa = mesa;
    p.comida = comida;
    int index = BuscarCozinheiroDisponivel();
    if (index > -1) {
        p.cozinhero=index;
        cozz[index].EnviarPedido(p);
    }else{
        cout <<"Não tem Cozinheiro Disponivel"<<endl;
    }

}

bool Restaurante::CheckMesaDisponivel(int n) {
    if (mesa[n] == 0) {
        mesa[n] = 1;
        return true;
    }
    return false;
}
