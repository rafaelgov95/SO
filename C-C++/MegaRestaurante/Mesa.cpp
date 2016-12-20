//
// Created by rafael on 20/12/16.
//

#include "Mesa.h"
#include <array>

using namespace std;

Mesa::Mesa() {
}

int Mesa::getPid() {
    return pid;
}

void Mesa::setPid(int pid) {
    this->pid = pid;
}

//void Mesa::ativarComunicacao() {
//    close(fd[1]);
//}

//void Mesa::setPipe(int fd[]) {
//    this->fd = fd;
//}

string Mesa::getPedido() {
    return this->pedido;
}

void Mesa::anotarPedido(string &pedido) {
    this->pedido.append(pedido + ";");
}