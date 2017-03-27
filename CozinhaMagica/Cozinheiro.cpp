//
// Created by rafael on 25/03/17.
//


#include <iostream>
#include <unistd.h>
#include "Cozinheiro.h"
#include "Cardapio.h"
#include "Pedido.h"

using namespace std;


Cozinheiro::Cozinheiro() {
}

Cozinheiro::~Cozinheiro() {

}

void *Cozinheiro::Cozinhar(void *pedido) {
    Pedido p = *((Pedido *) pedido);
    cout << "Mesa: " << p.mesa << " Pediu: " << p.comida.nome ;
    cout << " Tempo de Preparo: " << p.comida.tempo << endl;
    sleep(p.comida.tempo);
    cout << p.comida.nome << " está pronto" << endl;
}

void Cozinheiro::EnviarPedido(Pedido &valor) {


    if (pthread_create(&thread, NULL, Cozinhar, &valor) != 0) {

    }
    AguardarPedido();
}

void Cozinheiro::AguardarPedido() {
    if (pthread_join(thread, NULL) != 0) {

    }
}

void Cozinheiro::CancelarPedido() {
    if (pthread_cancel(thread) != 0) {

    }
}

void Cozinheiro::Detach() {
    if (pthread_detach(thread) != 0) {

    }
}

pthread_t Cozinheiro::GetId() {
    return thread;
}