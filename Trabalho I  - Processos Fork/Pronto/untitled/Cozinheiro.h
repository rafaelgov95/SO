//
// Created by rafael on 12/01/17.
//

#ifndef UNTITLED_COZINHEIRO_H
#define UNTITLED_COZINHEIRO_H

#include <fstream>

using namespace std;

class Cozinheiro {
private:
    pid_t pid;
    int mesa;
    int id;
    int fd[2];
    char buff[1024];
    string append;
    string fileName;
    ofstream escreve;


public:
    ~Cozinheiro();

    Cozinheiro();

    Cozinheiro(int &mesa, int &id);
    pid_t getPid();

    void anotarPedido();

    void EnviarPedidoParaCozinheiro(const string &pedido);

    void printModelo();

    void printFile(const string &pedido);
};


#endif //UNTITLED_COZINHEIRO_H

