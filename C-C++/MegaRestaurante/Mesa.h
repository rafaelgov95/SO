//
// Created by rafael on 20/12/16.
//

#ifndef MEGARESTAURANTE_MESA_H
#define MEGARESTAURANTE_MESA_H

#include <sched.h>
#include <string>

using namespace std;

class Mesa {
private:
    int pid;
    int fd[];
    string pedido;
public:


    Mesa();

    void ativarComunicacao(int *fd);

    void setPid(int pid);

    int getPid();

    void setPipe(int *fd);

    string getPedido();

    void anotarPedido(string &pedido);


};

#endif //MEGARESTAURANTE_MESA_H
