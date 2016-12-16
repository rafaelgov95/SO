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
    int  user;
    string txt;
public:
    Atendente();
    Atendente(pid_t pid, int id_user, string txt);

    pid_t getPid();
    void setPid(pid_t pid);

    int getUser();
    void setUser(int user);

    string getTxt();
    void setTxt(string txt);


};


#endif //PROBLEMADOATENDIMENTO_ATENDENTE_H

