#include <iostream>
#include <regex>
#include "Cardapio.h"
#include "Restaurante.h"


int main() {

    Cardapio cardapio;
    int c, i, t;
    string p;
    cin >> c;
    for (int j = 0; j < c; j++) {
        cin >> i >> t;
        getline(cin, p);
        cardapio.addComida(i, t, p);

    }
    Restaurante rest(3, 10, cardapio);
    bool flag = true;
    string pedido;
    int mesa;
    regex integer("(\\+|-)?[[:digit:]]+");
    while (flag) {
        cin >> pedido >> mesa;
        if (regex_match(pedido, integer)) {
            Comida *comi = rest.BuscarComida((unsigned int)atoi(pedido.c_str()));
            if (comi != nullptr) {
                Pedido p(*comi, mesa);
                rest.EnviarPedido(p);
            } else {
                cout << "Essa opção não esta em nosso cardapio" << endl;
            }
        } else {
            if (pedido.compare("FIM") == 0) {
                cout << "O espediente foi encerado por hoje !!. Obrigado Pela Preferência ! " << endl;
                delete &rest;
                flag = false;
            } else {
                cout << "ENTRADA INVALIDA" << endl;
            }
        }


    }
    return 0;
}

