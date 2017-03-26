//
// Created by rafael on 02/02/17.
//

#ifndef RESTAURANTE_CHEFECOZINHA_H
#define RESTAURANTE_CHEFECOZINHA_H

class ChefeCozinha {
public:
    ChefeCozinha();

    void receberPedido(const std::string &pedido);

    virtual ~ChefeCozinha();

private:
    int fd[2];
    pid_t pid;
};


#endif //RESTAURANTE_CHEFECOZINHA_H
