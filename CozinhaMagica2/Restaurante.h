//
// Created by rafael on 29/03/17.
//

#ifndef COZINHAMAGICA2_RESTAURANTE_H
#define COZINHAMAGICA2_RESTAURANTE_H


#include <sys/types.h>

#define n_client 15 //Quantidade Maxima de Cliente
#define n_cozinheiros 3 //Quantidade de Mestres Cucas
#define  n_mesas 10 // Mesas que poderam estar sendo atendidas

class Restaurante {

private:

public:
    pthread_t thr_clientes[n_client], thr_cozinheiros[n_cozinheiros];

    Restaurante();

    static void *f_cozinheiro(void *v);

    static void *f_cliente(void *v);

//    Restaurante();
    void IniciaAtendimento();


};


#endif //COZINHAMAGICA2_RESTAURANTE_H
