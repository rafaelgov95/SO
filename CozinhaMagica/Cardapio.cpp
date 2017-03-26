//
// Created by rafael on 26/03/17.
//

#include <iostream>
#include "Cardapio.h"

using namespace std;

unsigned int Cardapio::tempoDePreparo(string p) {
    if (p.compare("x") == 0) {
        return 10;
    } else if (p.compare("pao") == 0) {
        return 20;
    }else{
        return 10;
    }
}

