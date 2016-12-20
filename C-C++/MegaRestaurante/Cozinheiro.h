//
// Created by rafael on 20/12/16.
//

#ifndef MEGARESTAURANTE_COZINHEIRO_H
#define MEGARESTAURANTE_COZINHEIRO_H

#include <array>

using namespace std;

class Cozinheiro {
private:
    int numero_da_mesa;

public:
    Cozinheiro();

    void setNumeroMesa(int n);

    int getNumeroMesa();
};


#endif //MEGARESTAURANTE_COZINHEIRO_H
