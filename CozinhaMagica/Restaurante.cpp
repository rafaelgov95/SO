//
// Created by rafael on 26/03/17.
//

#include "Restaurante.h"
#include "Pedidos.h"

static Pedido mesa[10];
static queue<int> pedidos;

Restaurante::Restaurante() {
//    coz = new Cozinheiro[tamanho];
    for (int i = 0; i < 2; ++i) {
//        coz[i].Cozinheiro(i);
    }
//    pedidos = new queue<int>;

}

//int Restaurante::BuscarCozinheiroDisponivel() {
//    if (!cozDisp.empty()) {
//        int index = cozDisp.front();
//        cozDisp.pop();
//        return index;
//    }
//    return -1;
//}

//void Restaurante::AdicionarCozinheiroDisponivel(int coz) {
//    cozDisp.push(coz);
//}

void Restaurante::EnviarPedido(Comida comida, int m) {
    // cout <<"Entro aqui"<<endl;
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
//bool Restaurante::CheckMesaDisponivel(int n) {
//    if (mesa[n] == 0) {
//        mesa[n] = 1;
//        return true;
//    }
//    return false;
//}
