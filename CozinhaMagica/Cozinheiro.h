//
// Created by rafael on 25/03/17.
//

#ifndef COZINHAMAGICA_COZINHEIRO_H
#define COZINHAMAGICA_COZINHEIRO_H

#include <pthread.h>
#include "Comida.h"
#include "Pedido.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#include "semaphore.h"

using namespace std;

class Cozinheiro {
public:
    Cozinheiro();

    ~Cozinheiro();

    void AguardarPedido();

    void CancelarPedido();

    void Detach();

    pthread_t GetId();

    static void *AvisaCozinheiro(void *pthis);

private:
    pthread_t thread;

    static void *Cozinhar(void *pthis);

    static void Cozinha();


};

#endif //COZINHAMAGICA_COZINHEIRO_H
