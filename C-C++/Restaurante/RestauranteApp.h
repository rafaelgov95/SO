//
// Created by rafael on 02/02/17.
//

#ifndef RESTAURANTE_RESTAURANTEAPP_H
#define RESTAURANTE_RESTAURANTEAPP_H


#include <istream>

using namespace std;

class RestauranteApp {
private:

public:
    RestauranteApp();

    RestauranteApp(const RestauranteApp &orig);

    virtual ~RestauranteApp();

    void processarEntrada(istream &entrada);

};


#endif //RESTAURANTE_RESTAURANTEAPP_H
