#include "Atendente.h"
#include <iostream>

int atendentes[10];
using namespace std;

int AtendenteAtoa() {
    for (int i = 0; i < 10; ++i) {
        if (atendentes[i] == 0)return i;
    }
    return -1;
}

bool ExisteId(int id) {
    for (int i = 0; i < 10; ++i) {
        if (atendentes[i] == id)return true;
    }
    return false;
}


int main() {
    int atendentes[10];
    string pedido;
    int meuUser = -1;
    int atendenteAtual;
    int id;
    int pid;
    while (1) {
        cout << "Bem vindo Oque Deseja?" << endl;
        cin >> id >> pedido;
        if ((atendenteAtual = AtendenteAtoa()) >= 0) {
            if (ExisteId(id)) {
                if (id == meuUser) {
                    cout << "Usuario ja existe, " << pedido << "Meu pid: " << getpid() << endl;
                }
            } else {    
                if ((pid = fork()) == 0) {
                    meuUser = id;
                    string Txtpedido = pedido;
                    cout << "salvo aqui" << getpid() << "meu user" << meuUser << endl;
                    atendentes[atendenteAtual] = id;
                } else {


                }
            }
        } else {
            cout << "Todos os Atendentes estao ocupados. Aguarte e tente novamente" << endl;
        }


    }
    return 0;

}


//
//int main() {
//    cout << "Bem vindo Oque Deseja?" << endl;
//    int id;
//    string pedido;
//    int meuUser = -1;
//    while (1) {
//        cin >> id >> pedido;
//        for (int i = 0; i < 10; ++i) {
//            cout << "Atendente " << i << " : " << atendentes[i].getUser() << endl;
//        }
//        int atendenteAtual = AtendenteAtoa();
//        cout << "Pai Raiz : " << getpid() << " ! Meu user: " << meuUser << endl;
//        if (ExisteId(id)) {
//            cout << "entro aqui" << BuscaPid(id) << " : " << getpid() << endl;
//            if (BuscaPid(id) == meuUser) {
//                cout << "Usuario ja existe, " << pedido << "Meu pid: " << getpid() << endl;
//                return 0;
//            }
//        } else {
//
//            if (AtendenteAtoa() >= 0) {
//                atendentes[atendenteAtual].setUser(id);
//                if ((fork()) == 0) {
//                    meuUser = id;
//                    string Txtpedido = pedido;
//                    cout << "salvo aqui" << getpid() << "meu user" << meuUser << endl;
//                    return 0 ;
//                }else{
//                    cin >> id >> pedido;
//                }
//            } else {
//                cout << "Todos atendentes estão ocupados" << endl;
//
//            }
//        }
//    }
//    return 0;
//}