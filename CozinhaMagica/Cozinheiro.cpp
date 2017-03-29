//
// Created by rafael on 25/03/17.
//


#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include "Cozinheiro.h"
#include "Cardapio.h"
#include "Pedido.h"

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#include "semaphore.h"

using namespace std;


sem_t customers;                /* número de cliente à espera de atendimento */
sem_t barbers;                  /* número de barbeiros à espera de clientes */
sem_t mutex;
int waiting = 0;

void* barber(void *arg);
void* customer(void *arg);
void cut_hair();
void customer_arrived();
void get_haircut();
void giveup_haircut();

Cozinheiro::Cozinheiro() {
    if (pthread_create(&thread, NULL, AvisaCozinheiro, NULL) != 0) {

    }
}

Cozinheiro::~Cozinheiro() {

}

//void *Cozinheiro::Cozinhar(*pedido) {
//    Pedido p = *((Pedido *) pedido);
//    cout << "Sou o Cozinhero Nº: " << p.cozinhero << " Mesa: " << p.mesa << " Pediu: " << p.comida.nome;
//    cout << " Tempo de Preparo: " << p.comida.tempo << endl;
//    sleep(p.comida.tempo);
//    cout << p.comida.nome << " está pronto" << endl;
//
//
//}
void Cozinheiro::Cozinha() {
    cout << "ENVIANDO E DORMI DEPOIS" << endl;
    sleep(10);
}

void *Cozinheiro::AvisaCozinheiro(void *pedido) {
    cout <<"Entro aqui tamo dentro"<<endl;
    up(&customers);
    while (true) {
        cout <<"Testando 2"<<endl;
        sem_wait(&customers);   /* vai dormir se o número de clientes for 0 */
        cout <<"testando 1"<<endl;
        sem_wait(&mutex);       /* obtém acesso a 'waiting' */
        cout <<"atestando 2"<<endl;
        sem_post(&barbers);     /* um barbeiro está agora pronto para cortar cabelo */
        cout <<"Entro aqui 33"<<endl;
        sem_post(&mutex);       /* libera 'waiting' */
        cout <<"Entro aqui 333"<<endl;
        Cozinha();             /* corta o cabelo (fora da região crítica) */
    }

    pthread_exit(NULL);
}

void Cozinheiro::AguardarPedido() {
    if (pthread_join(thread, NULL) != 0) {

    }
}

void Cozinheiro::CancelarPedido() {
    if (pthread_cancel(thread) != 0) {

    }
}

void Cozinheiro::Detach() {
    if (pthread_detach(thread) != 0) {

    }
}

pthread_t Cozinheiro::GetId() {
    return thread;
}