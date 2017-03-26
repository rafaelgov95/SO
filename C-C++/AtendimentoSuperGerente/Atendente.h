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
    int idUser;

public:
    Atendente();

    int getUser();
    void setUser(int user);
    int getPid();
    void setPid(int pid);


};


#endif //PROBLEMADOATENDIMENTO_ATENDENTE_H

