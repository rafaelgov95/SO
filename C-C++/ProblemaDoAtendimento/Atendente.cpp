//
// Created by rafael on 14/12/16.
//
#include <array>
#include "Atendente.h"
using namespace std;
Atendente::Atendente() : idUser(0),txt("") {
}

int Atendente::getUser() {
    return idUser;
}

void Atendente::setUser(int idUser) {
    this->idUser = idUser;
}

string Atendente::getTxt() {
    return txt;
}
void Atendente::anotarPedido(string &txt) {
    this->txt.append(txt+";");
}