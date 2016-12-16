#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

//using namespace std;
int main() {
    pid_t filhoFork;
    pid_t array[10];
    char status[10];
    int *t;
//    pid_t *filhos = new pid_  t[10] ;


    array[0] = fork();
    if (array[0] == 0) {
        printf("I'm the son process %d  is parent %d \n", getpid(), getppid());
        scanf("%s", &status);
        if (status == "fim") {
            exit(1);
        }
    } else {
//        waitpid(array[0], t, 0);
        wait(t);
        printf("I'm the parent process %d e pai %d \n", getpid(), getppid());
//    }
        return 0;
    }
}