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
int fd[10][2];

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



int main() {
    string pedido;
    int id;
    pid_t pid;
    int clienteBuscado = -1;
    bool flag = true;
    do {
        if (pid == 0) {
            if (clienteBuscado > -1) {
                cout << "Passo aqui " << endl;
                close(fd[clienteBuscado][0]);


                close(fd[clienteBuscado][1]);
            }
        } else {
            cin >> id >> pedido;
//            clienteBuscado = BuscarCliente(id);
            cout << "Entenda isso rafael :D" << clienteBuscado << endl;
            cout << "Criar processo " << clienteBuscado << endl;

            if (CozinheiroDisponivel() >= 0) {
                mesa[id].setPid(getpid());
                pipe(fd[id]);
                if (fork() == 0) {
                    close(fd[id][1]);
                    cout << "lol" << endl;
                    string readbuffer;
                    bool fim = true;
                    do {
                        while (read(fd[id][0], &readbuffer, 1) > 0) {
                            write(STDOUT_FILENO, &readbuffer, 1);
                        }
                    } while (fim);

                }
            } else {
                cout << "Cozinheiros ocupados futuramente tera uma lista" << endl;
            }

        }

    } while (flag);

    return (0);
}
