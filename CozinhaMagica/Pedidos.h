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

    Pedido getPedido() {
        return *this;
    }

    const Comida &getComida() const {
        return comida;
    }

    void setComida(const Comida &comida) {
        this->comida = comida;
    }

    int getCozinhero() const {
        return cozinhero;
    }

    void setCozinhero(int cozinhero) {
        this->cozinhero = cozinhero;
    }

    int getMesa() const {
        return mesa;
    }

    void setMesa(int mesa) {
        this->mesa = mesa;
    }

};


#endif //COZINHAMAGICA_PEDIDO_H
