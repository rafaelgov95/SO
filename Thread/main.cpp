#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/unistd.h>
#include <iostream>
#include "pedido.h"


using namespace std;

//void *envia_p(void *arg) {
//    int tid = *((int *) arg);
//    cout << "Sou a Thread que vou le Atender seu pedido foi " << tid << endl;
//    sleep(tid);
//    cout << "pedido tempo "<< tid << "esta pronto" << endl;
//    pthread_exit(NULL);
//}
//
//int main(int argc, char **argv) {
//    pthread_t threads[5];
//    bool flag = true;
//    int i =0;
//
//    while (flag) {
//
//        i++;
//        string ped;
//        cin >> ped;
//        pedido cardapio;
//        int temp = cardapio.envia_pedido(ped);
//        int erro = pthread_create(&threads[i], NULL, envia_p, &temp);
//        if (erro) {
//            printf("Erro. FOi %d\n", erro);
//            exit(EXIT_FAILURE);
//        }
//
//
//    }
//    pthread_exit(NULL);
//    return (EXIT_SUCCESS);
//}



//#include <iostream>
//#include "Cozinheiro.h"
//#include ""
int main() {
    Cozinheiro coz[2];
    coz[1].EnviarPedido("Marmita");

    coz[1].AguardarPedido();

    std::cout << "Esta pronto a comida" << std::endl;
    return 0;
}