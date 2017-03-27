//
// Created by rafael on 25/03/17.
//


#include <iostream>
#include <unistd.h>
#include "Cozinheiro.h"
#include "Cardapio.h"

using namespace std;


Cozinheiro::Cozinheiro() {
}

Cozinheiro::~Cozinheiro() {

}

void *Cozinheiro::Cozinhar(void *pedido) {
    Comida p = *((Comida *) pedido);
    cout << "pedido enviado para a cozinha " << p.nome << endl;
    cout << "Tempo de Preparo: " << p.tempo << endl;
    sleep(p.tempo);
    cout << p.nome << " está pronto" << endl;
}

void Cozinheiro::EnviarPedido(Comida &valor) {

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