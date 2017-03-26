#include  <stdio.h>
#include  <sys/types.h>
#include <zconf.h>
#include <string>
#include <iostream>
#include "Atendente.h"

using namespace std;
pid_t pid;
Atendente t[10];

int AtendenteAtoa() {
    for (int i = 0; i < 4; ++i) {
        if (t[i].getUser() == 0) {
            return i;
        }
    }
    return -1;
}


int buscarMesa(int id) {
    for (int i = 0; i < 4; ++i) {
        if (id == t[i].getUser()) {
            return i;
        }
    }
    return -1;
}


int main() {
    int id, fd1[2], fd2[2], temp, status;
    string txt;
    /* Cria o pipe 1 */
    if (pipe(fd1) < 0) {
        perror("pipe");
        return -1;
    }
    /* Cria o pipe 2 */
    if (pipe(fd2) < 0) {
        perror("pipe");
        return -1;
    }
    while (1) {
        cin >> id >> txt;
        int mesa = buscarMesa(id);// pergunta se tem alguem com esse id, se sim retorna o id
        if ((pid = fork()) == 0) {
            if (mesa >= 0) {// o filho vai na missão de ver se tem alguem na lista do pai
//                close(fd1[0]);/* Fechando o descritor LEITURA no primeiro pipe. */
//                close(fd2[0]);/* Fechando o descritor LEITURA no segundo pipe. */
                if (!txt.compare(
                        "FIM")) {

//                    close(fd2[1]);/* Fechando o descritor LEITURA no primeiro pipe. */
                    cout << "Aqui vai rola a criação do arquivo e o salvar em disco" << endl;
//                    write(fd1[1], &mesa, sizeof(mesa));
//                    close(fd1[1]);/* Fechando o descritor LEITURA no primeiro pipe. */

                } else {
//                    close(fd2[0]);/* Fechando o descritor LEITURA no primeiro pipe. */
//                    close(fd1[0]);/* Fechando o descritor LEITURA no segundo pipe. */
//                    close(fd1[1]);/* Fechando o descritor LEITURA no primeiro pipe. */

//                    write(fd2[1], &txt, sizeof(txt));
//                    close(fd2[1]);/* Fechando o descritor LEITURA no primeiro pipe. */
                    cout << "Salvo os arquivos" << endl;

                }

            }
            cout << "Eu sou o Pid:" << getpid() << " # Meu pai é o pid: " << getppid() << " Eu vou morrer Agora By."
                 << endl;
            _exit(0);
        } else {
            cout << "Sou Pid: " << getpid()
                 << " #Eu sou o pai e sempre volto mais rapido entretanto se tiver um wait() aguardo minha vez fica Dica! # Use no .bash $:man fork"
                 << endl;
            if (mesa <
                0) {// se for menor que 0 nao tem atendente atendendo esse cara entao bora o atendente pra tabalhar
                int idAtendenteAtoa = AtendenteAtoa();
                if (idAtendenteAtoa >= 0) {
                    t[idAtendenteAtoa].setUser(id);
                    t[idAtendenteAtoa].anotarPedido(txt);
                } else {
                    cout << "Todos os Atendentes Ocupados Finalize Um Atendente!!" << endl;
                }
            } else {

                int numeroFinalizar = -1;
                string novoPedido = "valor";
                /* Fechando o descritor ESCRITA no primeiro e segundo pipe. */
//                close(fd1[1]);
//                close(fd2[1]);

//                read(fd2[0], &novoPedido, sizeof(novoPedido));
//                read(fd1[0], &numeroFinalizar, sizeof(numeroFinalizar));
//
//                close(fd1[0]);
//                close(fd2[0]);


                cout << "Passo aqui: " << numeroFinalizar << novoPedido << endl;
                if (numeroFinalizar >= 0) {
                    t[numeroFinalizar].setUser(0);
                    cout << "Cliente Pago a Conta e Vazo" << endl;
                } else if (novoPedido.compare("")) {
                    t[mesa].anotarPedido(novoPedido);
                    cout << t[mesa].getTxt() << endl;
                }

            }

        }

    }
}
