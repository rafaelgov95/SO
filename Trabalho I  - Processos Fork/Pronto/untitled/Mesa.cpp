//
// Created by rafael on 17/01/17.
//

#include <signal.h>
#include <iostream>
#include "Mesa.h"

Mesa::Mesa() {

}

Mesa::~Mesa() {

}
Mesa::Mesa(int idCozinheiro) {
    this->idCozinheiro = idCozinheiro;
    this->fechada = false;
}

bool Mesa::getIsFechada() {
    return fechada;
}

void Mesa::setIsFechada(bool valid) {
    fechada = valid;

}

void Mesa::cleanPedido() {
    pedido.append("");
}

int Mesa::getIdCozinheiro() {
    return idCozinheiro;
}

void Mesa::setIdCozinheiro(int id) {
    this->idCozinheiro = id;

}

string Mesa::getPedido() {
    return this->pedido;
}

void Mesa::setPedido(string pedido) {
    this->pedido.append(pedido+"\n");

}