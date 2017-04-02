//
// Created by rafael on 27/03/17.
//

#ifndef COZINHAMAGICA_PEDIDO_H
#define COZINHAMAGICA_PEDIDO_H

#include "Comida.h"

class Pedido {
private:
    Comida comida;
    int cozinhero;
    int mesa;
public:
    Pedido(const Comida &comida, const unsigned int mesa) : comida(comida), mesa(mesa) {
    };
    Pedido(const Pedido& outro):comida(outro.comida),mesa(outro.mesa){ //Construtor de cópia - copia recurso

    }
    const Comida &getComida() const {
        return comida;
    }

    int getCozinhero() const {
        return cozinhero;
    }

    int getMesa() const {
        return mesa;
    }

    void setCozinhero(int cozinhero) {
        this->cozinhero = cozinhero;
    }
};


#endif //COZINHAMAGICA_PEDIDO_H
