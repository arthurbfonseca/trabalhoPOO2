#ifndef DATAHORARIO_H
#define DATAHORARIO_H

class DataHorario {
    public:
        DataHorario(int, int, int, int, int, int);
        virtual ~DataHorario();
        int compara(DataHorario&);
        int getDia();
        int getMes();
        int getAno();
        int getHora();
        int getMinuto();
        int getSegundo();
        void imprime(bool);
        void imprimePorExtenso();
    private:
        int dia;
        int mes;
        int ano;
        int hora;
        int minuto;
        int segundo;
}; 

#endif