//
// Created by rafael on 26/03/17.
//

#ifndef COZINHAMAGICA_RESTAURANTE_H
#define COZINHAMAGICA_RESTAURANTE_H


#include <queue>
#include <string>
#include "Cozinheiro.h"
#include "Comida.h"
#include "Cardapio.h"

class Restaurante {
private:
    Cozinheiro **coz;
    Cardapio cardapio;
public:
    ~Restaurante();

    Restaurante(int cozinheros, int mesas, Cardapio &cardapio);

    Comida *BuscarComida(const unsigned int id);

    bool AguardarThreads(int qtd);

    static Pedido RestauranteListaDePedidos();

    void EnviarPedido(Pedido p);

    static bool fechar;
};


#endif //COZINHAMAGICA_RESTAURANTE_H
 