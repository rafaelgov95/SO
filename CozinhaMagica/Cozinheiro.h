//
// Created by rafael on 25/03/17.
//

#ifndef COZINHAMAGICA_COZINHEIRO_H
#define COZINHAMAGICA_COZINHEIRO_H

#include <pthread.h>
#include <queue>
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
//    static int id;
    pthread_t thread;

    static void *Semaforo(void *args);

    void Cozinhar(Pedido pedido);


};

#endif //COZINHAMAGICA_COZINHEIRO_H
