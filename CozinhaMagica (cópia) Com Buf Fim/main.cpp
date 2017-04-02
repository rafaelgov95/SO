#include <iostream>
#include <regex>
#include "Cardapio.h"
#include "Restaurante.h"


int main() {

    Cardapio cardapio;
    int c, i, t, qt_cozinheiro, qt_mesa;
    string p;
    cin >> c;
    for (int j = 0; j < c; j++) {
        cin >> i >> t;
        getline(cin, p);
        cardapio.addComida(i, t, p);
    }
    cin >> qt_cozinheiro >> qt_mesa;
    Restaurante rest(qt_cozinheiro, qt_mesa, cardapio);
    bool flag = true;
    string mesa;
    int pedido;
    regex integer("(\\+|-)?[[:digit:]]+");
    while (flag) {
        cin >> mesa;
        if (regex_match(mesa, integer)) {
            cin >> pedido;
            Comida *comi = rest.BuscarComida((unsigned int) pedido);
            if (comi != nullptr) {
                Pedido pe(*comi, atoi(mesa.c_str()));
                rest.EnviarPedido(pe);
            } else {
                cout << "ESSA OPÇÃO NÃO ESTA EM NOSSO CARDÁPIO" << endl;
            }
        } else {
            if (mesa.compare("FIM") == 0) {
                cout << "O EXPEDIENTE FOI ENCERRADO POR HOJE !!. OBRIGADO PELA PREFERÊNCIA ! " << endl;
                delete &rest;
                flag = false;
            } else {
                cout << "ENTRADA INVÁLIDA" << endl;
            }
        }

    }
    return 0;
}

