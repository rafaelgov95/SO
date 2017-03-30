#include <iostream>
#include <semaphore.h>
#include <unistd.h>
#include "Restaurante.h"

#define n_client 15 //Quantidade Maxima de Cliente
#define n_cozinheiros 3 //Quantidade de Mestres Cucas
#define  n_mesas 10 // Mesas que poderam estar sendo atendidas

sem_t sem_mesas; //Semaforo de mesas
sem_t sem_pedidos_na_cozinha[n_cozinheiros];  // 1 Pedidos que estão sendo preparado por um Mestre Cuca
sem_t sem_pedidos_atendido[n_cozinheiros];  //  2 Pedidos já estão pronto!
sem_t sem_esperando_pedido[n_cozinheiros]; //  3 cleint_cadira  3 Aguardando pedido para fazer "Cozinheiro esta no WhatsApp"

sem_t sem_escreve_visor, sem_le_visor;

int visor;

void *f_cozinheiro(void *v) {
    int id = *(int *) v;
    std::cout << "id cozinheiro " << id << std::endl;
    while (1) {
        sem_wait(&sem_escreve_visor);
        visor = id;
        sem_post(&sem_le_visor);
        sem_wait(&sem_esperando_pedido[id]);
        sleep(10);
        sem_post(&sem_pedidos_atendido[id]);
    }
    return NULL;
}

void *f_cliente(void *v) {
    int id = *(int *) v;
    int minha_mesa;

    usleep(random() % 700 + 4);
    if (sem_trywait(&sem_mesas) == 0) {
        printf("Cliente %d sentou.\n", id);
        sem_wait(&sem_le_visor);
        minha_mesa = visor;
        sem_post(&sem_escreve_visor);
        sem_wait(&sem_pedidos_na_cozinha[minha_mesa]);
        printf("Cliente %d esta sendo atendido pelo cozinheiro %d \n", id, minha_mesa);
        sem_post(&sem_esperando_pedido[minha_mesa]);
        sem_post(&sem_mesas);
        sem_wait(&sem_pedidos_atendido[minha_mesa]);
        sem_post(&sem_pedidos_na_cozinha[minha_mesa]);
        printf("Cliente %d recebeu seu pedido.\n", id);
    } else {
        printf("Cliente %d nao tinha cadeiras para sentar \n", id);
        return NULL;

    }

}


int main() {
//    Restaurante rest;
//    rest.IniciaAtendimento();
    pthread_t thr_clientes[n_client], thr_cozinheiros[n_cozinheiros];
    int i, id_cl[n_client], id_coz[n_cozinheiros];
    sem_init(&sem_mesas, 0, 5);
    sem_init(&sem_escreve_visor, 0, 1);
    sem_init(&sem_le_visor, 0, 0);
    for (i = 0; i < n_cozinheiros; i++) {
        sem_init(&sem_pedidos_na_cozinha[i], 0, 1);
        sem_init(&sem_esperando_pedido[i], 0, 0);
        sem_init(&sem_pedidos_atendido[i], 0, 0);
    }

    for (i = 0; i < n_client; i++) {
        id_cl[i] = i;
        pthread_create(&thr_clientes[i], NULL, f_cliente, (void *) &id_cl[i]);
    }
    for (i = 0; i < n_cozinheiros; i++) {
        id_coz[i] = i;
        pthread_create(&thr_cozinheiros[i], NULL, f_cozinheiro, (void *) &id_coz[i]);

    }

    for (i = 0; i < n_cozinheiros; i++) {
        pthread_join(thr_clientes[i], NULL);

    }
    printf("Fecho o Restaurante!;");
}


