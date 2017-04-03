//
// Created by rafael on 25/03/17.
//

#ifndef COZINHAMAGICA_COZINHEIRO_H
#define COZINHAMAGICA_COZINHEIRO_H

#include <pthread.h>
#include <queue>
#include <fstream>
#include "Comida.h"
#include "Pedidos.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#include "semaphore.h"

using namespace std;

class Cozinheiro {
public:
    Cozinheiro(int id);

    ~Cozinheiro();

    static void *AvisaCozinheiro();

    void Aguardar();

    pthread_t thread;
private:
    int id;

    static void *Semaforo(void *args);

    static void Trabalhar(const Pedido &p);

    static string bufferInicio(const Pedido &p);

    static string bufferFinal(const Pedido &p);

    static void printFile(const Pedido &p, const string &buff);


};

#endif //COZINHAMAGICA_COZINHEIRO_H
