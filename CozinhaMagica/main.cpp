#include <iostream>
#include <unistd.h>
#include "Cardapio.h"
#include "Restaurante.h"


int main() {
    Cardapio cardapio;
    cardapio.addComida(1, 20, "Feijao");
    cardapio.addComida(2, 4, "Arroz");
    Restaurante rest(3, 10);
    rest.cardapio = cardapio;
    bool flag = true;
    int escolha;
    int mesa, pedido;
    while (flag) {
        cin >> pedido >> mesa;
        Comida comi = rest.cardapio.buscarComida(pedido);
        if(comi== nullptr){

        }
        rest.EnviarPedido(comi, mesa);

    }


    std::cout << "Todos Pratos Estão prontos !! Obrigado Pela Preferência :D" << std::endl;
    return 0;
}
