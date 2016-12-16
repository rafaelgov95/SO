//
// Created by rafael on 14/12/16.
//
#include <array>
#include "Atendente.h"
using namespace std;
Atendente::Atendente() {
    pid = 0;
    user = 0;
    txt =" ";
}
Atendente::Atendente(pid_t pid, int user , string txt) {
    this->pid = pid;
    this->user = user;
    this->txt=txt;
}

pid_t Atendente::getPid() {
    return pid;
}
void Atendente::setPid(pid_t pid) {
     this->pid = pid;
}

int Atendente::getUser() {
    return user;
}

void Atendente::setUser(int user) {
    this->user = user;
}

string Atendente::getTxt() {
    return txt;
}
void Atendente::setTxt(string txt) {
    this->txt = txt;
}