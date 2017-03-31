#include <iostream>
#include <regex>
#include "Cardapio.h"
#include "Restaurante.h"


int main() {
    Cardapio cardapio;

//    int c, i, t;
//    string p;
//    cin >> c;
//    for (int i = 0; i < c; ++i) {
//        cin >> i >> t >> p;
//        cardapio.addComida(i,t, p);
//    }

    cardapio.addComida(1, 20, "Feijao");
    cardapio.addComida(2, 4, "Arroz");
    cardapio.addComida(3, 40, "Camarao");
    cardapio.addComida(4, 10, "Churrasco");
    cardapio.addComida(5, 15, "Bolo");
    Restaurante rest(3, 10, cardapio);
    bool flag = true;
    string pedido;
    int mesa;
    regex integer("(\\+|-)?[[:digit:]]+");
    while (flag) {
        cin >> pedido;
        if (regex_match(pedido, integer)) {
            int intPedido = atoi(pedido.c_str());
            cin >> mesa;
            Comida *comi = rest.BuscarComida(intPedido);
            if (comi != nullptr) {
                Pedido p(*comi, mesa);
                rest.EnviarPedido(p);
            }
        } else {
            if (pedido.compare("FIM") == 0) {
                cout << "Todos Pratos Estão prontos !! Obrigado Pela Preferência :D" << endl;
                flag = false;
            } else {
                cout <<"ENTRADA INVALIDA"<< endl;
            }
        }


    }
    return 0;
}

