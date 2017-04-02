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

    Cardapio cardapio;
public:
    Cozinheiro **coz;
    static bool fecho;

    bool ValorFila();

    ~Restaurante();

    static bool AvisaFechamento();

    Restaurante(int cozinheros, int mesas, Cardapio &cardapio);

    Comida *BuscarComida(const unsigned int id);

    static Pedido RestauranteListaDePedidos();

    void EnviarPedido(Pedido p);

    unsigned int EsperandoCozinheiro();
};


#endif //COZINHAMAGICA_RESTAURANTE_H
 