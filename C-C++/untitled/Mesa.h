//
// Created by rafael on 17/01/17.
//

#ifndef UNTITLED_MESA_H
#define UNTITLED_MESA_H


#include <string>
#include "Cozinheiro.h"

class Mesa {
private:
    int id;
    int idCozinheiro;
public:
    Mesa();
    Mesa(int idCozinheiro);
    void setIdCozinheiro(int id);
    int getIdCozinheiro();

};


#endif //UNTITLED_MESA_H
