//
// Created by rafael on 25/03/17.
//


#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include "Cozinheiro.h"
#include "Cardapio.h"
#include "Restaurante.h"

using namespace std;


static sem_t sem_pedido;
static ofstream escreve;
static queue<int> FilaDePedidos;

Cozinheiro::Cozinheiro(int i) {
    id = i;
    sem_init(&sem_pedido, 0, 0);
    if (pthread_create(&thread, NULL, Semaforo, &id) != 0) {
    }
}

Cozinheiro::~Cozinheiro() {

}

void *Cozinheiro::Semaforo(void *v) {
    int id = +1 + *(int *) v;
    string buffer;
    while (1) {
        sem_wait(&sem_pedido);
        Pedido p = Restaurante::RestauranteListaDePedidos();
        p.setCozinhero(id);
        cout << bufferInicio(p)<<endl;
        printFile(p, bufferInicio(p));
        sleep(p.getComida().getTempo());
        printFile(p, bufferFinal(p));
        cout << bufferFinal(p)<<endl;
        if (!FilaDePedidos.empty()) {
            FilaDePedidos.pop();
         //obs so um por vem podem entra aqui porem posso increntar o sem pedido antes.
            sem_post(&sem_pedido);
        }
    }
}

const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d/%m/%Y - %X", &tstruct);
    return buf;
}

void Cozinheiro::printFile(Pedido &p, string buffer) {
    string fileName;
    fileName.append("../Log_Atendimento/ChefeCozinha_").append(to_string(p.getCozinhero()));

    if (access(fileName.c_str(), F_OK) != -1) {
        escreve.open(fileName.c_str(), escreve.app | escreve.in);
        escreve << buffer.c_str() << endl;
    } else {
        escreve.open(fileName.c_str(), escreve.app | escreve.in);
        escreve << "ChefeCozinha_" + to_string(p.getCozinhero()).append("\n") << endl;
        escreve << buffer.c_str() << endl;
    }
    escreve.close();
}

string Cozinheiro::bufferInicio(Pedido pedido) {
    string buffer;
    time_t t = time(0);

    buffer.append(currentDateTime()).append(":\t").append(
            "Cozinhando pedido da Mesa ").append(to_string(pedido.getMesa())).append(" ( ").append(
            to_string(pedido.getComida().getId())).append(" - ").append(
            pedido.getComida().getNome()).append(" )\t").append(
            "Tempo " + to_string(pedido.getComida().getTempo()) + " sec");
    return buffer;
}

string Cozinheiro::bufferFinal(Pedido pedido) {
    string buffer;
    buffer.append(currentDateTime()).append(":\t").append("Entregando pedido da Mesa ").append(
            to_string(pedido.getMesa())).append(
            " ( ").append(to_string(pedido.getComida().getId())).append(" - ").append(
            pedido.getComida().getNome()).append(" )");
    return buffer;
}

void *Cozinheiro::AvisaCozinheiro() {
    int index = *(int *) &sem_pedido;
    if (index > 0) {
        FilaDePedidos.push(1);
    } else {
        sem_post(&sem_pedido);
    }

}