#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <bits/fcntl-linux.h>
//    #include <bits/fcntl-linux.h>

#define N 20
#define CHAIRS 5
#define MAX_CUT_TIME 5
#define MAX_TIME_BEFORE_START 8

sem_t *customers, *barbers;
pthread_mutex_t mutex;
int waiting = 0;
int customer_id[N];
int barber_id;
char *customer_name[20] =
        {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};

void *barber(void *arg);

void *customer(void *arg);

void cut_hair();

void get_haircut(int i);

void sem_close_n_unlink(sem_t *semId, char *semName);

void error_exit(const char *);

char *rand_str(char *mystr, int size);

int main() {

    srand(time(NULL));

    int res;
    pthread_t barber_thread, cust_thread[N];
    void *thread_result;
    int index;

    for (index = 0; index < N; index++) {
        customer_id[index] = index;
    }
    barber_id = 0;

    //iniciar mutex
    res = pthread_mutex_init(&mutex, NULL);
    if (res != 0) error_exit("Inicializacao do mutex falhou");

    // iniciar semaforos
    // atencao: em sistemas darwin, utilizamos sem_open ao inves de sem_init
    // pois no Mac OS X, apenas *semaforos nomeados* estao implementados.

    char *barbersem, *customersem;
    barbers = sem_open(rand_str(barbersem, 8), O_CREAT, 0, 0);
    customers = sem_open(rand_str(customersem, 8), O_CREAT, 0, 0);

    // criar threads
    res = pthread_create(&barber_thread, NULL, barber, (void *) &barber_id);
    if (res != 0) error_exit("Criacao de thread falhou");

    for (index = 0; index < N; index++) {
        res = pthread_create(&cust_thread[index], NULL, customer, (void *) &customer_id[index]);
        if (res != 0) error_exit("Criacao de thread falhou");
    }

    res = pthread_join(barber_thread, &thread_result);
    if (res != 0) error_exit("Falhou quando tentou pthread_join");

    //destroy mutex
    pthread_mutex_destroy(&mutex);
    // closing and unlink semaphores
    sem_close_n_unlink(barbers, barbersem);
    sem_close_n_unlink(customers, customersem);

    return 1;
}

void *barber(void *arg) {
    int id = *(int *) arg;
    while (1) {
        printf("Barbeiro desocupado.\n");
        sem_wait(customers);
        printf("== Fila de espera tem  %d clientes.\n", waiting);
        pthread_mutex_lock(&mutex);
        waiting = waiting - 1;
        sem_post(barbers);
        printf("Barbeiro pronto para cortar algum cabelo.\n");
        pthread_mutex_unlock(&mutex);
        cut_hair();
    }
}

void *customer(void *arg) {

    int id = *(int *) arg;
    sleep(rand() % MAX_TIME_BEFORE_START); //simular o comportamento de chegada dos clientes

    pthread_mutex_lock(&mutex);
    if (waiting < CHAIRS) {
        waiting = waiting + 1;
        sem_post(customers);
        printf("%s esta na fila de espera. Tamanho da fila eh %d.\n", customer_name[id], waiting);
        pthread_mutex_unlock(&mutex);
        sem_wait(barbers);
        get_haircut(id);
    } else {
        printf("  Cliente %s passando direto. Fila cheia!\n", customer_name[id]);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit("customer exits.\n");
}

void cut_hair() {
    sleep(3);
}

void get_haircut(int i) {
    printf("%s esta cortando o cabelo\n", customer_name[i]);
    sleep(3);
}

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

char *rand_str(char *mystr, int size) {
    if ((mystr = calloc(size + 1, sizeof(char))) == NULL) {
        printf("callor error.\n");
        return NULL;
    }

    int aux;
    for (aux = 0; aux < size; aux++) {
        mystr[aux] = (char) ((rand() % 23) + 'a');
    }
    mystr[aux] = '\0';

    return mystr;
}

void sem_close_n_unlink(sem_t *semId, char *semName) {

    if (sem_close(semId) == -1) {
        printf("sem_close failed\n");
        return;
    }

    if (sem_unlink(semName) == -1) {
        printf("sem_unlink failed\n");
        return;
    }
    printf("closed and unlinked semaphore\n");
}
