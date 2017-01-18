//
// Created by rafael on 12/01/17.
//

#ifndef UNTITLED_COZINHEIRO_H
#define UNTITLED_COZINHEIRO_H

using namespace std;

class Cozinheiro {
private:
    pid_t pid;
    int fd[2];
    char temp[1024];
    string append;
    int idMesa;
public:
    Cozinheiro(int idMesa);
    void anotarPedido();
    void EnviarPedidoParaCozinheiro(const string &pedido);
    string getAppend();
    pid_t getPid();
};


#endif //UNTITLED_COZINHEIRO_H
