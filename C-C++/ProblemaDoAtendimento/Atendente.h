//
// Created by rafael on 14/12/16.
//

#ifndef PROBLEMADOATENDIMENTO_ATENDENTE_H
#define PROBLEMADOATENDIMENTO_ATENDENTE_H
#include <zconf.h>
using namespace std;
class Atendente {
private:
    pid_t pid;
    int  idUser;
    string txt;
public:
    Atendente();
    int getUser();
    void setUser(int user);

    string getTxt();
    void anotarPedido(string &txt);


};


#endif //PROBLEMADOATENDIMENTO_ATENDENTE_H

