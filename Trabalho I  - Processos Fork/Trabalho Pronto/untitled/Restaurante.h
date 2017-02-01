//
// Created by rafael on 19/01/17.
//

#ifndef UNTITLED_RESTAURANTE_H
#define UNTITLED_RESTAURANTE_H


#include <string>
#include <queue>
#include "Cozinheiro.h"
#include "Mesa.h"

void GerenteFinalizaConta(int a);

class Restaurante {
private:
    bool flag = true;
    int m, c;
    string id, pedido;
    queue<int> cozDisp;
    Cozinheiro **coz;
    Mesa **mesa;
    queue<int> mesaEspera;
public:
    int BuscarCozinheiroDisponivel();

    bool MesaDisponivel(int id);

    void EncaminharPedidoAoCozinheiro(int idCozinheiro, string pedido);

    void FecharConta(int id);

    void AtendimentoNaListaDeEspera();

    void IniciarAtendimentoAMesa(int id);


    void iniciarRestaurante();

    void RestauranteLoop();
};

#endif //UNTITLED_RESTAURANTE_H