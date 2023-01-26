#ifndef VOO_H
#define VOO_H

#include "Pessoa.h"
#include "DataHorario.h"

class Voo {
    public:
        Voo(int num, DataHorario &data);
        int proximoLivre();
        bool verifica(int);
        bool ocupa(int, Pessoa&);
        bool desocupa(int);
        int vagas();
        void imprime();
        DataHorario getHorario();
        int getNumero();
    private:
        int numeroVoo;
        DataHorario data;
        Pessoa* poltronas[100];
};

#endif
