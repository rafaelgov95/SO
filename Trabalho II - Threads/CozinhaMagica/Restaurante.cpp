//
// Created by rafael on 26/03/17.
//

#include "Restaurante.h"


static queue<Pedido> pedidos;
bool Restaurante::fechar = true;


Restaurante::Restaurante(int cozinheiros, int mesas, Cardapio &cardapio) {
    this->cardapio = cardapio;
    this->coz = new Cozinheiro *[cozinheiros];
    for (int i = 0; i < cozinheiros; i++) {
        this->coz[i] = new Cozinheiro(i);
    }
}

Restaurante::~Restaurante() {
    delete &coz;
}

Comida *Restaurante::BuscarComida(const unsigned int id) {
    return cardapio.buscarComida(id);
}


void Restaurante::EnviarPedido(Pedido p) {
    pedidos.push(p);

    Cozinheiro::AvisaCozinheiro();

}

bool Restaurante::AguardarThreads(int qtd) {

    Cozinheiro::AvisaCozinheiro();

    for (int i = 0; i < qtd; i++) {
        coz[i]->Aguardar();

    }
    cout << "Fechamos a Cozinha" << endl;
    return false;
}

Pedido Restaurante::RestauranteListaDePedidos() {
    Pedido p = pedidos.front();
    pedidos.pop();

    return p;
}

