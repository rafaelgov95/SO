//
// Created by rafael on 17/01/17.
//

#ifndef UNTITLED_MESA_H
#define UNTITLED_MESA_H


#include <string>
#include "Cozinheiro.h"

class Mesa {
private:
    int id;
    int idCozinheiro;
    bool fechada;
    string pedido;

public:
    Mesa();

    ~Mesa();

    Mesa(int idCozinheiro);

    void cleanPedido();

    void setIdCozinheiro(int id);

    int getIdCozinheiro();


    bool getIsFechada();

    void setIsFechada(bool valid);

    string getPedido();

    void setPedido(string &pedido);
};


#endif //UNTITLED_MESA_H
