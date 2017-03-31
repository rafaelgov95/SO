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

private:

    static void *Semaforo(void *args);

    static string bufferInicio(Pedido p);

    static string bufferFinal(Pedido p);

    static void printFile(Pedido &p,string buff);

    int id;
    pthread_t thread;
};

#endif //COZINHAMAGICA_COZINHEIRO_H
