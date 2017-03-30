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


static sem_t sem_pedido;
static ofstream escreve;

Cozinheiro::Cozinheiro(int i) {
    id = i;
    sem_init(&sem_pedido, 0, 0);
    if (pthread_create(&thread, NULL, Semaforo, &id) != 0) {
    }
}

Cozinheiro::~Cozinheiro() {

}

void *Cozinheiro::Semaforo(void *v) {
    int id = *(int *) v;
    while (1) {
        sem_wait(&sem_pedido);
        Pedido p = Restaurante::RestaurantePedidos();
        std::cout << "Pedido: " << p.comida.nome << "Mesa: " << p.mesa << " Cozinheiro: " << id << std::endl;
        sleep(p.comida.tempo);
        p.cozinhero = id;
        printFile(p);
        cout << "Pedido Entregue" << " Mesa: " << p.mesa << " Feita Pelo Cozinheiro: " << id << endl;
    }
}

void Cozinheiro::printFile(Pedido pedido) {
    string buffer;
    buffer.append("Mesa ").append(to_string(pedido.mesa)).append(":").append("\n").append("     - ").append(pedido.comida.nome);
    string fileName = "ChefeCozinha_" + to_string(pedido.cozinhero + 1);
    if (access(fileName.c_str(), F_OK) != -1) {
        escreve.open(fileName.c_str(), escreve.app | escreve.in);
        escreve << buffer.c_str() << endl;
    } else {
        escreve.open(fileName.c_str(), escreve.app | escreve.in);
        escreve << "ChefeCozinha_" + to_string(pedido.cozinhero + 1) << endl;
        escreve << buffer.c_str() << endl;
    }
    escreve.close();
}

void Cozinheiro::Cozinhar(Pedido pedido) {
    cout << "Vou cozinhar" << endl;
    sleep(3);
    cout << "ENVIANDO E DORMI DEPOIS" << endl;

}

void *Cozinheiro::AvisaCozinheiro() {
    sem_post(&sem_pedido);
}