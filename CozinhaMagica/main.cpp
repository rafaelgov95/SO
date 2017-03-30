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
    int mesa;
    while (flag) {
        cin >> escolha;
        if (escolha == 1) {
            cout << "Prato Escolhido = Feijão" << endl;
            cout << "Digite uma mesa" << endl;
            cin >> mesa;
            rest.EnviarPedido(rest.cardapio.buscarComida("Feijao"), mesa);
        } else if (escolha == 2) {
            cout << "Prato Escolhido = Arroz" << endl;
            cout << "Digite uma mesa" << endl;
            cin >> mesa;
            rest.EnviarPedido(rest.cardapio.buscarComida("Arroz"), mesa);
        }


    }


    std::cout << "Todos Pratos Estão prontos !! Obrigado Pela Preferência :D" << std::endl;
    return 0;
}
