#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

class Aluno : public Pessoa {
public:
    Aluno(string, string, int, double, double, double);
    int getRA();
    double media();
    bool aprovado();
    bool sac();
    double notaSAC();
    void imprime();
private:
    int RA;
    double notaP1;
    double notaP2;
    double notaT;
};

#endif