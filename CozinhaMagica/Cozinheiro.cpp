//
// Created by rafael on 25/03/17.
//


#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include "Cozinheiro.h"
#include "Cardapio.h"
#include "Pedidos.h"

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#include "semaphore.h"
#include "Restaurante.h"

using namespace std;

static int id;
static sem_t sem_pedido;

Cozinheiro::Cozinheiro(int i) {
    int id = i;
    sem_init(&sem_pedido, 0, 0);
    if (pthread_create(&thread, NULL, Semaforo, NULL) != 0) {
        // erro
    }
}

Cozinheiro::~Cozinheiro() {

}

void *Cozinheiro::Semaforo(void *args) {
    id =+ 1;
    while (1) {
        sem_wait(&sem_pedido);
        Pedido p = Restaurante::RestaurantePedidos();
        std::cout << "Pedido: " << p.comida.nome << "Mesa: " << p.mesa << " ID: " << id << std::endl;
        sleep(p.comida.tempo);

    }
}

void Cozinheiro::Cozinhar(Pedido pedido) {
    cout << "Vou cozinhar" << endl;
    sleep(3);
    cout << "ENVIANDO E DORMI DEPOIS" << endl;

}

void *Cozinheiro::AvisaCozinheiro() {
    sem_post(&sem_pedido);
}