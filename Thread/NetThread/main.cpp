#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/unistd.h>


void t1_function(void *arg) {
    int tid = (int) arg;
    printf("Thread num = %d\n", tid);
    sleep(5);
    printf("morri\n");
    pthread_exit(NULL);
}

int main(int argc, char** argv) {


    pthread_t threads[5];
    pthread_attr_t t1_attr;

    for (int i = 0; i < 5; i++) {
        //criando a thread e chamando o metodo
        int erro = pthread_create(&threads[i], NULL, t1_function, i);
        if (erro) {
            printf("Erro. FOi %d\n", erro);
            exit(EXIT_FAILURE);
        }
    }

    //bloqueia a passagem até a trhead 3 morrer
    pthread_join(threads[3], NULL);
    printf("a trhead 3 morreu\n");

    pthread_exit(NULL);

    return (EXIT_SUCCESS);
}