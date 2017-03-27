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
    Cozinheiro cozz[10];
    queue<int> cozDisp;
    int mesa[20];
public:
    Restaurante();

    Cardapio cardapio;
    bool CheckMesaDisponivel(int n);
    int BuscarCozinheiroDisponivel();

    void AdicionarCozinheiroDisponivel(int coz);

    void EnviarPedido(Comida nomeDaComida,int mesa);
};


#endif //COZINHAMAGICA_RESTAURANTE_H
