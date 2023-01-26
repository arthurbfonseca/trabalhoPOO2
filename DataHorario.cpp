#include <iostream>
#include "DataHorario.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

DataHorario::DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo) : dia(dia), mes(mes), ano(ano), hora(hora), minuto(minuto), segundo(segundo) {
    if (ano % 4 == 0 && ano % 100 != 0 ) {
            if (mes == 2) {
                if (dia > 29) {
                    this->dia = 1;
                    this->mes = 1;
                    this->ano = 1;
                    this->hora = 0;
                    this->minuto = 0;
                    this->segundo = 0;
                }
            }
        }
    else if (ano %  4 == 0 && ano % 100 == 0) {
            if (ano % 400 == 0) {
                if (mes == 2) {
                    if (dia > 29) {
                        this->dia = 1;
                        this->mes = 1;
                        this->ano = 1;
                        this->hora = 0;
                        this->minuto = 0;
                        this->segundo = 0;
                    }
                }
            }
            else {
                if (mes == 2) {
                    if (dia > 28) {
                        this->dia = 1;
                        this->mes = 1;
                        this->ano = 1;
                        this->hora = 0;
                        this->minuto = 0;
                        this->segundo = 0;
                    }
                }
            }
        }
    else {
        if (mes == 2) {
            if (dia > 28) {
                this->dia = 1;
                this->mes = 1;
                this->ano = 1;
                this->hora = 0;
                this->minuto = 0;
                this->segundo = 0;
            }
        }
    }
    if (hora > 23 || minuto > 59 || segundo > 59 || hora < 0 || minuto < 0 || segundo < 0 || dia <= 0 || mes <= 0 || mes > 12 || ano <= 0) {
        this->dia = 1;
        this->mes = 1;
        this->ano = 1;
        this->hora = 0;
        this->minuto = 0;
        this->segundo = 0;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30) {
            this->dia = 1;
            this->mes = 1;
            this->ano = 1;
            this->hora = 0;
            this->minuto = 0;
            this->segundo = 0; 
        }
    }
    else {
        if (dia > 31) {
            this->dia = 1;
            this->mes = 1;
            this->ano = 1;
            this->hora = 0;
            this->minuto = 0;
            this->segundo = 0; 
        }
    }
}  

DataHorario::~DataHorario(){
}

int DataHorario::compara(DataHorario& horarioParametro){
    double somaParametro;
    double somaCorrente;
    double x;

    somaParametro = horarioParametro.ano*10000000000 + horarioParametro.mes*100000000 + horarioParametro.dia*1000000 + horarioParametro.hora*10000 + horarioParametro.minuto*100 + horarioParametro.segundo*1;
    somaCorrente = this->ano*10000000000 + this->mes*100000000 + this->dia*1000000 + this->hora*10000 + this->minuto*100  +  this->segundo*1;
    
    if (somaCorrente == somaParametro) {
        x = 0;
    }
    else if (somaCorrente > somaParametro) {
        x = 1;
    }
    else {
        x = -1;
    }
    
    return x;
}

int DataHorario::getAno(){
    return ano;
}

int DataHorario::getMes(){
    return mes;
}

int DataHorario::getDia(){
    return dia;
}

int DataHorario::getHora(){
    return hora;
}

int DataHorario::getMinuto(){
    return minuto;
}

int DataHorario::getSegundo(){
    return segundo;
}

void DataHorario::imprime(bool s){
stringstream ss1;
int horaAMPM;

    if (s) {
        if (hora >= 12) {
            switch (hora) {
                case 12: 
                    horaAMPM = 12;
                break;
                case 13: 
                    horaAMPM = 1;
                break;
                case 14: 
                    horaAMPM = 2;
                break;
                case 15: 
                    horaAMPM = 3;
                break;
                case 16: 
                    horaAMPM = 4;
                break;
                case 17: 
                    horaAMPM = 5;
                break;
                case 18: 
                    horaAMPM = 6;
                break;
                case 19: 
                    horaAMPM = 7;
                break;
                case 20: 
                    horaAMPM = 8;
                break;
                case 21: 
                    horaAMPM = 9;
                break;
                case 22: 
                    horaAMPM = 10;
                break;
                case 23: 
                    horaAMPM = 11;
                break;
            };

            ss1 << setfill('0') << setw(2) << this->getDia();
            ss1 << "/";
            ss1 << setfill('0') << setw(2) << this->getMes();
            ss1 << "/";
            ss1 << setfill('0') << setw(4) << this->getAno();
            ss1 << " ";
            ss1 << setfill('0') << setw(2) << horaAMPM;
            ss1 << ":";
            ss1 << setfill('0') << setw(2) << this->getMinuto();
            ss1 << ":";
            ss1 << setfill('0') << setw(2) << this->getSegundo();
            cout << ss1.str() << " PM " << endl;
        }
        else {
            if (hora == 0) {
                horaAMPM = 12;
            }
            ss1 << setfill('0') << setw(2) << this->getDia();
            ss1 << "/";
            ss1 << setfill('0') << setw(2) << this->getMes();
            ss1 << "/";
            ss1 << setfill('0') << setw(4) << this->getAno();
            ss1 << " ";
            ss1 << setfill('0') << setw(2) << horaAMPM;
            ss1 << ":";
            ss1 << setfill('0') << setw(2) << this->getMinuto();
            ss1 << ":";
            ss1 << setfill('0') << setw(2) << this->getSegundo();
            cout << ss1.str() << " AM " << endl;
        }    
    }
    else {
            ss1 << setfill('0') << setw(2) << this->getDia();
            ss1 << "/";
            ss1 << setfill('0') << setw(2) << this->getMes();
            ss1 << "/";
            ss1 << setfill('0') << setw(4) << this->getAno();
            ss1 << " ";
            ss1 << setfill('0') << setw(2) << this->getHora();
            ss1 << ":";
            ss1 << setfill('0') << setw(2) << this->getMinuto();
            ss1 << ":";
            ss1 << setfill('0') << setw(2) << this->getSegundo();
            cout << ss1.str() << endl;
    }
}

void DataHorario::imprimePorExtenso(){
    string x;
    stringstream ss2, ss3, ss4;
    
    switch (mes) {
        case 1:
            x = "Janeiro";
        break;
        case 2:
            x = "Fevereiro";
        break;
        case 3:
            x = "Março";
        break;
        case 4:
            x = "Abril";
        break;
        case 5:
            x = "Maio";
        break;
        case 6:
            x = "Junho";
        break;
        case 7:
            x = "Julho";
        break;
        case 8:
            x = "Agosto";
        break;
        case 9:
            x = "Setembro";
        break;
        case 10:
            x = "Outubro";
        break;
        case 11:
            x = "Novembro";
        break;
        case 12:
            x = "Dezembro";
        break;  
    };

    ss2 << setfill('0') << setw(2) << this->getHora();
    ss3 << setfill('0') << setw(2) << this->getMinuto();
    ss4 << setfill('0') << setw(2) << this->getSegundo();

    cout << this->getDia() << " de " << x << " de " << this->getAno() << " -- " << ss2.str() << " hora(s)" << ", " << ss3.str() << " minuto(s)" << " e " << ss4.str() << " segundos " << endl;
}