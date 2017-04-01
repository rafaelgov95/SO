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

static sem_t sem_fila;
static sem_t sem_pedido;
static ofstream escreve;
static pthread_mutex_t mutex;

Cozinheiro::Cozinheiro(int i) {
    id = i;
    sem_init(&sem_fila, 0, 1);
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        cout << "ERRO NA CRIACAO DA CHAVE" << endl;
    }
    sem_init(&sem_pedido, 0, 0);
    if (pthread_create(&thread, NULL, Semaforo, &id) != 0) {
        cout << "ERRO NA CRIACAO DO COZINHEIRO" << endl;
    }
}

Cozinheiro::~Cozinheiro() {
    sem_close(&sem_fila);
    sem_close(&sem_pedido);
    pthread_mutex_destroy(&mutex);
    if (pthread_detach(thread) != 0) {
        // throw an error
    }

}

void *Cozinheiro::Semaforo(void *v) {
    int id = +1 + *(int *) v;
    string buffer;
    while (1) {
        sem_wait(&sem_pedido);
        sem_wait(&sem_fila);

        pthread_mutex_lock(&mutex);
        Pedido p = Restaurante::RestauranteListaDePedidos();
        sem_post(&sem_fila);
        pthread_mutex_unlock(&mutex);

        p.setCozinhero(id);
        Trabalhar(p);


    }
}

void Cozinheiro::Trabalhar(const Pedido &p) {
    pthread_mutex_lock(&mutex);
    cout << bufferInicio(p) << endl;
    printFile(p, bufferInicio(p));
    pthread_mutex_unlock(&mutex);
    sleep(p.getComida().getTempo());
    pthread_mutex_lock(&mutex);
    printFile(p, bufferFinal(p));
    cout << bufferFinal(p) << endl;
    pthread_mutex_unlock(&mutex);

}

const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d/%m/%Y - %X", &tstruct);
    return buf;
}

void Cozinheiro::printFile(const Pedido &p, const string &buffer) {
    string fileNameFull;
    fileNameFull.append("../Log_Atendimento/ChefeCozinha_Relatorio_ALL");

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

    if (access(fileNameFull.c_str(), F_OK) != -1) {
        escreve.open(fileNameFull.c_str(), escreve.app | escreve.in);
        escreve << buffer.c_str() << endl;
    } else {
        escreve.open(fileNameFull.c_str(), escreve.app | escreve.in);
        escreve << "LOG DE TODOS CHEFES DE COZINHA: \n" << endl;
        escreve << buffer.c_str() << endl;
    }


    escreve.close();
}

string Cozinheiro::bufferInicio(const Pedido &pedido) {
    string buffer;
    buffer.append(currentDateTime()).append(":\t").append(
            "Preparando pedido da Mesa ").append(to_string(pedido.getMesa())).append(" ( ").append(
            to_string(pedido.getComida().getId())).append("  - ").append(
            pedido.getComida().getNome()).append(" )\t").append(
            "Tempo " + to_string(pedido.getComida().getTempo()) + " sec");
    return buffer;
}

string Cozinheiro::bufferFinal(const Pedido &pedido) {
    string buffer;
    buffer.append(currentDateTime()).append(":\t").append("Entregando pedido da Mesa ").append(
            to_string(pedido.getMesa())).append(
            " ( ").append(to_string(pedido.getComida().getId())).append("  - ").append(
            pedido.getComida().getNome()).append(" )");
    return buffer;
}

void *Cozinheiro::AvisaCozinheiro() {
    sem_post(&sem_pedido);
}