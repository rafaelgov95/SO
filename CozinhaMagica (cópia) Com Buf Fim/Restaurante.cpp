//
// Created by rafael on 26/03/17.
//

#include "Restaurante.h"


static queue<Pedido> pedidos;

Restaurante::Restaurante(int cozinheiros, int mesas, Cardapio &cardapio) {
    this->cardapio = cardapio;
    this->coz = new Cozinheiro *[cozinheiros];
    for (int i = 0; i < cozinheiros; i++) {
        this->coz[i] = new Cozinheiro(i);
    }
}

bool Restaurante::fecho = false;

Restaurante::~Restaurante() {
    delete &coz;
}

Comida *Restaurante::BuscarComida(const unsigned int id) {
    return cardapio.buscarComida(id);
}

bool Restaurante::ValorFila() {
    if (pedidos.empty()) {
        return true;
    }
    return false;
}

void Restaurante::EnviarPedido(Pedido p) {
    pedidos.push(p);

    Cozinheiro::AvisaCozinheiro();

}

bool Restaurante::AvisaFechamento() {
    return fecho;

}

unsigned int Restaurante::EsperandoCozinheiro() {


}

Pedido Restaurante::RestauranteListaDePedidos() {
    Pedido p = pedidos.front();
    pedidos.pop();

    return p;
}

