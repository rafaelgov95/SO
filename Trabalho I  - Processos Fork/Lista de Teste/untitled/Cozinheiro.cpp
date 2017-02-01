

//
// Created by rafael on 12/01/17.
//

#include <zconf.h>
#include <cstdlib>

#include <cstring>
#include <signal.h>
#include <iostream>

#include "Cozinheiro.h"

using namespace std;

Cozinheiro::Cozinheiro() {

}

Cozinheiro::~Cozinheiro() {
    if (kill(pid, SIGKILL) > -1) {

    } else {

    }
}

Cozinheiro::Cozinheiro(int &mesa, int &id) {
    if (!pipe(fd)) {
        this->id = id;
        this->mesa = mesa;
        fileName.append("../LogCozinheiro/ChefeCozinha_" + to_string(id+1) + ".txt");
        memset(buff, 0, sizeof(buff));
        if ((pid = fork()) == 0) {
            anotarPedido();
        }
    }

}

void Cozinheiro::printFile(const string &pedido) {
    if (access(fileName.c_str(), F_OK) != -1) {
        escreve.open(fileName.c_str(), escreve.app | escreve.in);
        escreve << pedido << endl;
    } else {
        escreve.open(fileName.c_str(), escreve.app | escreve.in);
        escreve << "ChefeCozinha_" + to_string(id + 1) << endl;
        escreve << pedido << endl;
    }
    escreve.close();
}

void Cozinheiro::printModelo() {
    append.append("\nMESA " + to_string(mesa) + ":");
}

void Cozinheiro::anotarPedido() {
    close(fd[1]);
    printModelo();
    printFile(append);
    while (read(fd[0], &buff, sizeof(buff)) > 0) {
        string pedido;
        pedido.append(buff);
        printFile(pedido);
        memset(buff, 0, sizeof(buff));
    }
    close(fd[0]);
}


void Cozinheiro::EnviarPedidoParaCozinheiro(const string &pedido) {
    close(fd[0]);
    write(fd[1], pedido.c_str(), pedido.size());

}



