//#include <iostream>
//
//int main() {
//
//    FILE *pFile;
//
//    pFile = fopen("../myfile.txt", "w");
//    char txt[50] = "rafael viana";
//    fprintf(pFile,"%s",txt);
//    fclose(pFile);
//
//    pFile=fopen("../myfile.txt", "w");
//
//    fprintf(pFile);
//    return 0;
//}
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string line;
    string novaline="fadfadfa";
    ofstream escreve; //buffer de escrita
//    escreve.open ("test.txt",std::ofstream::app);

    escreve.open("../myfile.txt",escreve.app|escreve.in	); // carrega o arquivo em buffer
//    cin >> novaline;
    getline(cin, novaline);
    escreve << novaline << endl;
    escreve.close();

    ifstream myfile("../myfile.txt"); // ifstream = padrão ios:in
    if (myfile.is_open()) {
        while (!myfile.eof()) //enquanto end of file for false continua
        {
            getline(myfile, line); // como foi aberto em modo texto(padrão)//e não binário(ios::bin) pega cada linha
            cout << line << endl;
        }
        myfile.close();
    } else cout << "Unable to open file";

    return 0;
}