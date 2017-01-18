//
// Created by rafael on 17/01/17.
//

#include "Mesa.h"

Mesa::Mesa() {

}

Mesa::Mesa(int idCozinheiro) {
    setIdCozinheiro(idCozinheiro);
}

int Mesa::getIdCozinheiro() {
    return idCozinheiro;
}

void Mesa::setIdCozinheiro(int id) {
    this->idCozinheiro = id;

}