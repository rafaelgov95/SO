//
// Created by rafael on 26/03/17.
//

#include "Restaurante.h"


static Pedido mesa[10];
static queue<int> pedidos;

Restaurante::Restaurante(int cozinheiros, int mesas) {

    for (int i = 0; i < cozinheiros; i++) {
        coz[i] = new Cozinheiro(i);
    }


}

void Restaurante::EnviarPedido(Comida comida, int m) {
    Pedido p;
    p.mesa = m;
    p.comida = comida;
    mesa[m] = p;
    pedidos.push(m);
    Cozinheiro::AvisaCozinheiro();

}

Pedido Restaurante::RestaurantePedidos() {
    int index = pedidos.front();
    pedidos.pop();
    return mesa[index];
}

