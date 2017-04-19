//
// Created by rafael on 19/01/17.
//

#include <csignal>
#include <iostream>
#include <zconf.h>
#include <wait.h>
#include <unistd.h>

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
            FecharConta(T);
        }
    }
}

void Restaurante::IniciarAtendimentoAMesa(int id) {
    int index = BuscarCozinheiroDisponivel();
    mesa[id] = new Mesa(index);

    if (index > -1) {
        coz[index] = new Cozinheiro(id, index);
        cozDisp.pop();
        EncaminharPedidoAoCozinheiro(index, "  - " + pedido);
    } else {
        pedido = "  - " + pedido + "\n";
        mesa[id]->setPedido(pedido);
        mesaEspera.push(id);
    }

}

void GerenteFinalizaConta(int s) {

    int saved_errno = errno;
    while (waitpid((pid_t) (-1), 0, WNOHANG) > 0) {}
    errno = saved_errno;

}

void Restaurante::iniciarRestaurante() {
    cin >> c >> m;
    mesa = new Mesa *[m + 1];
    coz = new Cozinheiro *[c + 1];
    for (int i = 0; i < c; ++i) {
        cozDisp.push(i);
    }
    RestauranteLoop();
}


void Restaurante::RestauranteLoop() {
    signal(SIGCHLD, &GerenteFinalizaConta);
    while (flag) {
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

                    } else {
                        pedido = "  - " + pedido;
                        mesa[idMesa]->setPedido(pedido);
                    }
                } else {
                    if (!pedido.compare(" fim")) {
                        FecharConta(idMesa);
                    } else {

                        EncaminharPedidoAoCozinheiro(mesa[idMesa]->getIdCozinheiro(), "  - " + pedido);

                    }
                }
            }

        } else {

            _exit(0);
        }
    }
}