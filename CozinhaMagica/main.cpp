#include <iostream>
#include <unistd.h>
#include "Cardapio.h"
#include "Restaurante.h"


int main() {

    Restaurante rest;
    rest.cardapio.addComida("Feijao", 10);
    rest.cardapio.addComida("Arroz", 20);
    bool flag = true;
    int escolha;
    while (flag) {
        cin >> escolha;
        if (escolha == 1) {
            rest.EnviarPedido(rest.cardapio.buscarComida("Feijao"), 3);
        }


    }


    std::cout << "Todos Pratos Estão prontos !! Obrigado Pela Preferência :D" << std::endl;
    return 0;
}
