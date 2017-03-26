//
// Created by rafael on 25/03/17.
//


#include <iostream>
#include <unistd.h>
#include "Cozinheiro.h"

using namespace std;

Cozinheiro::Cozinheiro() {
}

Cozinheiro::~Cozinheiro() {

}

void *Cozinheiro::Cozinhar(void *pedido) {
    string tid = *((string *) pedido);
    cout << "pedido enviado para a cozinha "<< endl;
    sleep(10);
}

void Cozinheiro::EnviarPedido(string pedido) {
    if (pthread_create(&m_threadId, NULL, Cozinhar,&pedido) != 0) {

    }
}

void Cozinheiro::AguardarPedido() {
    if (pthread_join(m_threadId, NULL) != 0) {
        // throw an error
    }
}

void Cozinheiro::CancelarPedido() {
    if (pthread_cancel(m_threadId) != 0) {
        // throw an error
    }
}

void Cozinheiro::Detach() {
    if (pthread_detach(m_threadId) != 0) {
        // throw an error
    }
}

pthread_t Cozinheiro::GetId() {
    return m_threadId;
}