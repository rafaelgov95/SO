#include <iostream>
#include <unistd.h>
#include "Cardapio.h"
#include "Restaurante.h"


int main() {
    Restaurante rest;

    rest.cardapio.addComida("Feijao", 10);
    rest.cardapio.addComida("Arroz", 20);
    rest.EnviarPedido(rest.cardapio.buscarComida("Feijao"));

    std::cout << "Todos Pratos Estão prontos !! Obrigado Pela Preferência :D" << std::endl;
    return 0;
}
