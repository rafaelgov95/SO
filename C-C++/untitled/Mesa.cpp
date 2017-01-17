//
// Created by rafael on 17/01/17.
//

#include "Mesa.h"
Mesa::Mesa() {

}
Mesa::Mesa(int idCozinheiro) {
    setIdCozinheiro(idCozinheiro);
}

int Mesa::getId() {
    return id;

}

int Mesa::getIdCozinheiro() {
    return idCozinheiro;

}

void Mesa::setId(int id) {
    this->id = id;
}

void Mesa::setIdCozinheiro(int id) {
    this->idCozinheiro = id;

}