#include <iostream>
#include "Cozinheiro.h"


int main() {
    Cozinheiro coz[3];
    string comidas[3];
    comidas[0] = "feijao";
    comidas[1] = "pao";
    comidas[2] = "x";

/// Esse for nao funciona ele enviar " x "  para todos pratos

//    for (int j = 0; j < 3; j++) {
//    coz[j].EnviarPedido(comidas[j]);
//    }

/// sem o for funcona perfeitamente!

    coz[0].EnviarPedido(comidas[0]);
    coz[1].EnviarPedido(comidas[1]);
    coz[2].EnviarPedido(comidas[2]);




    for (int i = 0; i < 3; i++) {
        coz[i].AguardarPedido();
    }
    std::cout << "Todos Pratos Estão prontos !! Obrigado Pela Preferência :D" << std::endl;
    return 0;
}
