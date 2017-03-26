//
// Created by rafael on 02/02/17.
//

#include <zconf.h>
#include <iostream>
#include <signal.h>
#include "ChefeCozinha.h"

using namespace std;

ChefeCozinha::~ChefeCozinha() {
    if (kill(pid, SIGKILL) > -1) {
        cout << "Morreu" << endl;
    } else {
        cout << "Não Morreu" << endl;
    }
}

ChefeCozinha::ChefeCozinha() {
    if (pipe(fd) != -1) {
        pid = fork();
        if (pid == 0) {
            pid = getpid();
            char buffer[256];
            close(fd[1]);
            while (read(fd[0], buffer, sizeof(buffer))) {
                cout << buffer << endl;
            }
        }

    }
}

ChefeCozinha::receberPedido(const string &pedido) {

}