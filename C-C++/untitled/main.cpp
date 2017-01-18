#include <iostream>
#include <zconf.h>
#include <cstring>

using namespace std;

#include "Cozinheiro.h"
#include "Mesa.h"

bool flag = true;
int id;
string pedido;

Cozinheiro *coz[3];
Mesa *mesa[18];
Mesa *Espera[18];

int BuscarCozinheiroDisponivel() {
    for (int i = 0; i < (sizeof(coz) / sizeof(*coz)); ++i) {
        if (coz[i] == nullptr) return i;
    }
    return -1;
}

int MesaDisponivel(int id) {
    if (mesa[id] == nullptr) return id;
    return -1;
}

int main() {
    while (flag) {

        cin >> id;
        getline(cin, pedido);
        if (MesaDisponivel(id) >= 0) {
            cout << "Seja bem Vindo ao Restaurante Mesa: " << id << endl;
            int index = BuscarCozinheiroDisponivel();
            if (index >= 0) {
                mesa[id] = new Mesa(index);
                coz[index] = new Cozinheiro(id);
                cout << "Seu cozinheiro é: " << index << endl;
                coz[mesa[id]->getIdCozinheiro()]->EnviarPedidoParaCozinheiro(pedido);
            } else {
                cout << " Mesa Foi para lista de espera sem cozinheiro disponivel " << endl;
            }
        } else {
            cout << "Seu cozinheiro é: " << mesa[id]->getIdCozinheiro() << endl;
            coz[mesa[id]->getIdCozinheiro()]->EnviarPedidoParaCozinheiro(pedido);
        }

    }
}








