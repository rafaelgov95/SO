

//
// Created by rafael on 12/01/17.
//

#include <zconf.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fcntl.h>
#include "Cozinheiro.h"

using namespace std;


Cozinheiro::Cozinheiro(int idMesa) {
    if (!pipe(fd)) {
        this->idMesa = idMesa;
        if (fork() == 0) {
            memset(temp, 0, sizeof(temp));
            pid = getpid();
            anotarPedido();

        }
    }
}

void Cozinheiro::anotarPedido() {
    close(fd[1]);
    int historico;
    while (read(fd[0], &temp, sizeof(temp)) > 0) {
        cout << pid << " Mesa: " << idMesa << endl;
        historico++;
        append.append(to_string(historico) + " : " + temp + "\n");
        cout << getAppend() << endl;
        memset(temp, 0, sizeof(temp));
    }

}

string Cozinheiro::getAppend() {
    return this->append;
}

void Cozinheiro::EnviarPedidoParaCozinheiro(const string &pedido) {
    close(fd[0]);
    cout << "Enviando para o pipe do Cozinheiro: ";
    write(fd[1], pedido.c_str(), pedido.size());
}

pid_t Cozinheiro::getPid() {
    return pid;
}



