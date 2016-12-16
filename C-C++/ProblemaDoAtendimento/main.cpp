#include  <stdio.h>
#include  <sys/types.h>
#include <zconf.h>
#include <string>
#include <iostream>
#include "Atendente.h"

using namespace std;
pid_t pid;
Atendente t[4];

//
int vazio() {
    for (int i = 0; i < 4; ++i) {
        if (t[i].getUser() == 0) {
            return i;
        }
    }
    return -1;
}

string buscar(int id) {
    for (int i = 0; i < 4; ++i) {
        if (id == t[i].getUser()) {
            return t[i].getTxt();
        }
    }
    return "-1";
}

int main() {
    int id;
    string txt;
    bool flag = true;
    while (1) {
        cin >> id >> txt;
        string txtNovo = buscar(id);
        if ((pid = fork()) == 0) {
            if (txtNovo != "-1") {
                if (txt == "FIM") {
                    cout << "Aqui vai rola a criação do arquivo e o salvar em disco" << endl;
                } else {
                    t[id].setTxt(txtNovo);
                    cout << "Salvo os arquivos" << endl;
                }
            } else {
                int temp;
                if ((temp = vazio()) >= 0) {
                    t[temp].setUser(id);
                    t[temp].setTxt(txt);

                } else {
                    cout << "Todos os Atendentes Ocupados Finalize Um Atendente!!" << endl;
                }
            }
            cout <<"Eu sou o Pid:" << getpid() << " # Meu pai é o pid: " << getppid() << " Eu vou morrer Agora By."<< endl;
            _exit(0);
        } else {
            cout << "Sou Pid: " << getpid()
                 << " #Eu sou o pai e sempre volto mais rapido entretanto se tiver um wait() aguardo minha vez fica Dica! # Use no .bash $:man fork"
                 << endl;

        }
    }
}
