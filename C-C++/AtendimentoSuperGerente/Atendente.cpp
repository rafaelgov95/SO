//
// Created by rafael on 14/12/16.
//
#include <array>
#include "Atendente.h"

using namespace std;

Atendente::Atendente() : idUser(0), pid() {



}

int Atendente::getUser() {
    return idUser;
}

void Atendente::setUser(int idUser) {
    this->idUser = idUser;
}

int Atendente::getPid() {
    return pid;
}
void Atendente::setPid(int pid) {
    this->pid = pid;
}
