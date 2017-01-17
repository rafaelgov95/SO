#include <iostream>
#include <zconf.h>
#include <cstring>

using namespace std;

#include "Cozinheiro.h"
#include "Mesa.h"

bool flag = true;
int id;
string pedido;

Cozinheiro *coz[10];
Mesa *mesa[18];
Mesa *Espera[18];

int BuscarCozinheiroDisponivel() {
    for (int i = 0; i < sizeof(coz); ++i) {
        if (coz[i] == nullptr) return i;
    }
    cout << "Nao Achou cozinheiro com esse ID ocupado." << endl;
    return -1;
}

int MesaDisponivel(int id) {
    if (mesa[id] == nullptr) return id;
//    cout << "Mesa Ocupada está sendo Atendida pelo Cozinheiro Numero: " << mesa[id]->getIdCozinheiro() << endl;
    return -1;
}

int main() {
    while (flag) {
        cin >> id >> pedido;
        if (MesaDisponivel(id) >= 0) {
            cout << "Seja bem Vindo ao Restaurante Mesa: " << id << endl;
            int index = BuscarCozinheiroDisponivel();
            if (index >= 0) {
                mesa[id] = new Mesa(index);
                coz[index] = new Cozinheiro();
                cout << "Seu cozinheiro é: " << index << endl;
            } else {
                mesa[id] = new Mesa();
                cout << " Mesa Foi para Lista de espera" << endl;
            }
        } else {
            if (pedido == "sair") {
                cout << "Saiu agora" << endl;
                coz[mesa[id]->getIdCozinheiro()] = nullptr;
                mesa[id] = nullptr;
            } else {
                coz[mesa[id]->getIdCozinheiro()]->EnviarPedidoParaCozinheiro(pedido);
            }

        }
    }
}






