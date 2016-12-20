#include <iostream>
#include <zconf.h>

using namespace std;
int atendente[10];

int ExisteId(int &id) {
    for (int i = 0; i < 10; ++i) {
        if (atendente[i] == id) return atendente[i];
    }
    return -1;
}

void Atendente(int id, int meuId) {
    if (ExisteId(id) >= 0) {
        if (meuId == id) {
            cout << "" << getpid();
        }
    } else {

    }
}


int main() {
    int fd[2];
    pid_t pid;
    int id;
    int meuId;
    string pedido;
    int temp;
    int pid_pai;
    while (1) {
        cout << "Pid: " << getpid() << endl;
        cin >> id >> pedido;
        if (pipe(fd) < 0) {
            perror("pipe");
            return -1;
        }
        if(ExisteId(0))
        if (fork() == 0) {
            close(fd[0]);
            write(fd[1], str, sizeof(str) + 1);
            _exit(1);
        } else {
            wait(*temp);
        }
    }
    return 0;
}


