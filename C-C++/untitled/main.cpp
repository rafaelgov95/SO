#include <iostream>
#include <zconf.h>
#include <cstring>

using namespace std;

#include "Cozinheiro.h"

Cozinheiro *coz[10];
int messas[18];

int BuscarCozinheiro(int b) {
    if (coz[b] != nullptr) return b;
    cout << "Nao Achou cozinheiro com esse id" << endl;
    return -1;
}

int MesaDisponivel() {
    for (int i = 0; i < sizeof(coz); ++i) {
        if (coz[i] == nullptr) return i;
    }
    return -1;
}

int main() {
    bool flag = true;
    int id ;
    string pedido;
    while (flag) {
        cin >> id >> pedido;
        if (BuscarCozinheiro(id) >= 0) {
            coz[id]->EnviarPedidoParaCozinheiro(pedido);
        } else {
            int index = MesaDisponivel();
            coz[index] = new Cozinheiro();
        }
    }
}






