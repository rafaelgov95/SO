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
    string pedido;
    int mesa;
    regex integer("(\\+|-)?[[:digit:]]+");
    while (flag) {
        cin >> pedido;
        if (regex_match(pedido, integer)) {
            cin >> mesa;
            cout << pedido << endl;
            Comida *comi = rest.BuscarComida((unsigned int) atoi(pedido.c_str()));
            if (comi != nullptr) {
                Pedido p(*comi, mesa);
                rest.EnviarPedido(p);
            } else {
                cout << "ESSA OPÇÃO NÃO ESTA EM NOSSO CARDÁPIO" << endl;
            }
        } else {
            if (pedido.compare("FIM") == 0) {
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

