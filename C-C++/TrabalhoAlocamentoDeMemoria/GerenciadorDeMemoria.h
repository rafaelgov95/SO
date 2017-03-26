//
// Created by rafael on 06/12/16.
//

#ifndef TRABALHOALOCAMENTODEMEMORIA_GERENCIADORDEMEMORIA_H
#define TRABALHOALOCAMENTODEMEMORIA_GERENCIADORDEMEMORIA_H


class GerenciadorDeMemoria {
    //construtores do Gerenciador
    GerenciadorDeMemoria(const unsigned long n);
    GerenciadorDeMemoria(const GerenciadorDeMemoria &orig);
   //construtores de copy.
    virtual ~GerenciadorDeMemoria();

    void *alocar(unsigned long n);
    void desalocar(void *endereco, unsigned long n);
};


#endif //TRABALHOALOCAMENTODEMEMORIA_GERENCIADORDEMEMORIA_H
