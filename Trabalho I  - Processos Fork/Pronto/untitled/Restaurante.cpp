//
// Created by rafael on 19/01/17.
//

#include <csignal>
#include <iostream>
#include <zconf.h>
#include "Restaurante.h"

using namespace std;

//Busca Cozinheiro Disponivel na Fila de Cozinheiro.
int Restaurante::BuscarCozinheiroDisponivel() {
    if (!cozDisp.empty()) {
        int index = cozDisp.front();
        return index;
    }
    return -1;
}

bool Restaurante::MesaDisponivel(int id) {
    if (mesa[id] == nullptr) return true;
    return false;
}

void Restaurante::EncaminharPedidoAoCozinheiro(int id, string pedido) {
    coz[id]->EnviarPedidoParaCozinheiro(pedido);

}

void Restaurante::FecharConta(int id) {
    cozDisp.push(mesa[id]->getIdCozinheiro());
    delete coz[mesa[id]->getIdCozinheiro()];
    coz[mesa[id]->getIdCozinheiro()] = nullptr;
    delete mesa[id];
    mesa[id] = nullptr;


}

void Restaurante::AtendimentoNaListaDeEspera() {
    while (!mesaEspera.empty() && !cozDisp.empty()) {
        int index = BuscarCozinheiroDisponivel();
        int T = mesaEspera.front();
        cozDisp.pop();
        coz[index] = new Cozinheiro(T, index);
        mesa[T]->cleanPedido();
        mesa[T]->setIdCozinheiro(index);
        mesaEspera.pop();
        sleep(1);
        EncaminharPedidoAoCozinheiro(index, mesa[T]->getPedido());
        sleep(1);
        if (mesa[T]->getIsFechada()) {
            cout << "Encerou pela Fila " << endl;
            FecharConta(T);
        }
    }
}

void Restaurante::IniciarAtendimentoAMesa(int id) {
    cout << "SEJA BEM VINDO AO RESTAURANTE" << endl;
    int index = BuscarCozinheiroDisponivel();
    mesa[id] = new Mesa(index);
    pedido = "  - " + pedido;
    mesa[id]->setPedido(pedido);
    if (index > -1) {
        coz[index] = new Cozinheiro(id, index);
        cozDisp.pop();

        EncaminharPedidoAoCozinheiro(index, pedido);
    } else {
        mesaEspera.push(id);
        cout << "PEDIDO SALVO NA MESA" << endl;
    }

}

void GerenteFinalizaConta(int s) {
    wait(sta);

}

void Restaurante::iniciarRestaurante() {
    cout << "Olá sou o Luiz, sou o Gerente Virtual do Restaurante BOM DE MAIS SOH\n"
         << "Informe nº de Cozinheiros e Mesas: "
         << endl;
    cin >> c >> m;

    mesa = new Mesa *[m + 1];
    coz = new Cozinheiro *[c + 1];
    for (int i = 0; i < c; ++i) {
        cozDisp.push(i);
    }
    RestauranteLoop();
}


void Restaurante::RestauranteLoop() {
    while (flag) {
        signal(SIGCHLD, &GerenteFinalizaConta);
        AtendimentoNaListaDeEspera();
        cin >> id;
        if (id.compare("FIM") && id.compare("fim")) {
            int idMesa = stoi(id);
            getline(cin, pedido);
            if (MesaDisponivel(idMesa)) {
                IniciarAtendimentoAMesa(idMesa);
            } else {
                if (mesa[idMesa]->getIdCozinheiro() == -1) {
                    if (!pedido.compare(" fim")) {
                        mesa[idMesa]->setIsFechada(true);
                        cout << "PEDIDO NA MESA FECHO CONTA" << endl;
                    } else {
                        pedido = "  - " + pedido;
                        mesa[idMesa]->setPedido(pedido);
                        cout << "PEDIDO SALVO NA MESA" << endl;
                    }
                } else {
                    if (!pedido.compare(" fim")) {
                        cout << "Encerou por modo Normal" << endl;
                        FecharConta(idMesa);

                    } else {
                        pedido = "  - " + pedido;
                        EncaminharPedidoAoCozinheiro(mesa[idMesa]->getIdCozinheiro(), pedido);

                    }
                }
            }

        } else {
            cout << "ACABO O HORARIO DE EXPEDIENTE" << endl;
            _exit(0);
        }
    }
}