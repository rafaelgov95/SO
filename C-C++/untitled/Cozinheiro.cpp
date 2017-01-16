

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



Cozinheiro::Cozinheiro() {
    if (!pipe(fd)) {

        if (fork() == 0) {
            memset(temp, 0, sizeof(temp));
            pid = getpid();
            anotarPedido();
        }
    }
}

void Cozinheiro::anotarPedido() {
    close(fd[1]);
    while (read(fd[0], &temp, sizeof(temp)) > 0) {
        write(STDOUT_FILENO, &temp, sizeof(temp));
        memset(temp, 0, sizeof(temp));
        cout << endl << pid << endl;
    }

    close(fd[0]);
}

void Cozinheiro::EnviarPedidoParaCozinheiro(const string &pedido) {
    close(fd[0]);
    cout << "Enviando para o pipe do Cozinheiro " << endl;
    write(fd[1], pedido.c_str(), pedido.size());


}

pid_t Cozinheiro::getPid() {
    return pid;
}



