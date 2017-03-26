//
// Created by rafael on 25/03/17.
//

#ifndef COZINHAMAGICA_COZINHEIRO_H
#define COZINHAMAGICA_COZINHEIRO_H

#include <pthread.h>
using namespace std;
class Cozinheiro {
public:
    Cozinheiro();

    ~Cozinheiro();

    void EnviarPedido(string pedido);

    void AguardarPedido();

    void CancelarPedido();

    void Detach();

    pthread_t GetId();




private:
    static void *Cozinhar(void *pthis);
    pthread_t thread;
};

#endif //COZINHAMAGICA_COZINHEIRO_H