#include "Aluno.h"
#include <iostream>

using namespace std;

Aluno::Aluno(string CPF, string nome, int RA, double notaP1, double notaP2, double notaT) : Pessoa(CPF, nome), RA(RA), notaP1(notaP1), notaP2(notaP2), notaT(notaT) {
}

int Aluno::getRA(){
    return RA;
}

double Aluno::media() {
    double MF;
    MF = (notaP1*7 + notaP2*7 + notaT*6)/20;
    return MF;
}

bool Aluno::aprovado(){
    if (media() >= 6) {
        return true;
    }
    else {
        return false;
    }
}

bool Aluno::sac(){
    if (media() >= 5 && media() < 6) {
        return true;
    }
    else {
        return false;
    }
}

double Aluno::notaSAC() {
    double notaSAC;
    if (sac()) {
        notaSAC = 12 - media();
        return notaSAC;
    }   
    else {
        return 0;
    }
}

void Aluno::imprime(){
    Pessoa::imprime();
    cout << "RA: " << RA << endl;
    if (aprovado()){
        cout << "Aprovado com média " << media() << endl;
    }
    else {
        if(sac()) {
            cout << "(SAC) Nota mínima aprovação: " << notaSAC() << endl;
        }
        else {
            cout << "Reprovado com média: " << media() << endl;
        }
    }
    
}

