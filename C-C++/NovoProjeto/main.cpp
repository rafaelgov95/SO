#include <unistd.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    int fd_p2c[2], fd_c2p[2], bytes_read;
    pid_t childpid;
    char readbuffer[80];
    string program_name = "/bin/cat";
    string gulp_command = "this is the command data sent to the child cat (kitten?)";
    string receive_output = "";

    if (pipe(fd_p2c) != 0 || pipe(fd_c2p) != 0)
    {
        cerr << "Failed to pipe\n";
        exit(1);
    }
    childpid = fork();

    if (childpid < 0)
    {
        cout << "Fork failed" << endl;
        exit(-1);
    }
    else if (childpid == 0)
    {
        if (dup2(fd_p2c[0], 0) != 0 ||
            close(fd_p2c[0]) != 0 ||
            close(fd_p2c[1]) != 0)
        {
            cerr << "Child: failed to set up standard input\n";
            exit(1);
        }
        if (dup2(fd_c2p[1], 1) != 1 ||
            close(fd_c2p[1]) != 0 ||
            close(fd_c2p[0]) != 0)
        {
            cerr << "Child: failed to set up standard output\n";
            exit(1);
        }

        execl(program_name.c_str(), program_name.c_str(), (char *) 0);
        cerr << "Failed to execute " << program_name << endl;
        exit(1);
    }
    else
    {
        close(fd_p2c[0]);
        close(fd_c2p[1]);

        cout << "Writing to child: <<" << gulp_command << ">>" << endl;
        int nbytes = gulp_command.length();
        if (write(fd_p2c[1], gulp_command.c_str(), nbytes) != nbytes)
        {
            cerr << "Parent: short write to child\n";
            exit(1);
        }
        close(fd_p2c[1]);

        while (1)
        {
            bytes_read = read(fd_c2p[0], readbuffer, sizeof(readbuffer)-1);

            if (bytes_read <= 0)
                break;

            readbuffer[bytes_read] = '\0';
            receive_output += readbuffer;
        }
        close(fd_c2p[0]);
        cout << "From child: <<" << receive_output << ">>" << endl;
    }
    return 0;
}

//#include <iostream>
//#include <zconf.h>
//#include <cstring>
//
//using namespace std;
//
//int main() {
//    int fd[2];
//    pid_t childpid;
//    char string[] = "Hello, world!\n";
//
//
//    do {
//        pipe(fd);
//        cin >> string;
//        if ((childpid = fork()) == -1) {
//            perror("fork");
//            exit(1);
//        }
//        if (childpid == 0) {
//            close(fd[1]);
//            char  readbuffer[255];
//            while (read(fd[0], &readbuffer, sizeof(readbuffer)) > 0) {
//                cout << "String enviada: " << getpid() << readbuffer << endl;
//            }
//            cout << "passo aqui" << endl;
//        } else {
//            cout << "Pai envia msg" << endl;
//            close(fd[0]);
//            write(fd[1], string, (strlen(string) + 1));
//            close(fd[1]);
//        }
//    } while (1);
//    return (0);
//}