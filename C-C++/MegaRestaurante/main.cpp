#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include "Cozinheiro.h"
#include "Mesa.h"

using namespace std;
int lengPipe = 10;
Mesa mesa[10];
Cozinheiro SuperMestre[10];

int CozinheiroDisponivel() {
    for (int i = 0; i < sizeof(SuperMestre); ++i) {
        if (SuperMestre[i].getNumeroMesa() == 0) return i;
    }
    return -1;
}

int MesaDisponivel() {
    for (int i = 0; i < sizeof(mesa); ++i) {
        if (mesa[i].getPid() == 0) return i;
    }
    return -1;
}

int BuscarCliente(int b) {
    if (mesa[b].getPid() > 0)return 1;
    return -1;
}


int main() {
    string pedido;
    int id = -1;
    do {
        cin >> id >> pedido;
        int clienteBuscado = BuscarCliente(id);
        cout << clienteBuscado << endl;
        if (clienteBuscado > -1) {
            close(mesa[id].fd[0]);
            write(mesa[id].fd[1], &pedido, (sizeof(pedido)));
            close(mesa[id].fd[1]);

        } else {
            cout << "Criar processo " << clienteBuscado << endl;
            if (CozinheiroDisponivel() >= 0) {
                mesa[id].setPid(getpid());
                pipe(mesa[id].fd);
                if (fork() == 0) {
                    close(mesa[id].fd[1]);
                    cout << "lol" << endl;
                    string readbuffer;
                    while (read(mesa[id].fd[0], &readbuffer, sizeof(readbuffer)) > 0) {
                        cout << "String enviada: " << readbuffer << "Meu pid: " << getpid() << endl;
                        if (pedido.compare("FIM")) {

                        }
                    }
                    cout << "estou escapando do while" << endl;
                }
            } else {
                cout << "Cozinheiros ocupados futuramente tera uma lista" << endl;
            }

        }

    } while (1);

    return (0);
}
