//
// Created by rafael on 12/01/17.
//

#ifndef UNTITLED_COZINHEIRO_H
#define UNTITLED_COZINHEIRO_H

using namespace std;

class Cozinheiro {
private:
    pid_t  pid;
    int fd[2];
    char temp[1024];
public:
    Cozinheiro();
//    ~Cozinheiro();
    void anotarPedido();
    void EnviarPedidoParaCozinheiro(const string &pedido);
    pid_t getPid();
};


#endif //UNTITLED_COZINHEIRO_H
