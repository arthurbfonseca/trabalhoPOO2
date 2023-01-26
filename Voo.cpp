#include <iostream>
#include <vector>
#include "Voo.h"
//Associação
using namespace std;

Voo::Voo(int numeroVoo, DataHorario &data) : numeroVoo(numeroVoo), data(data) {
    for (int i = 0; i < 100; i++) {
        poltronas[i] = NULL;
    }
}

int Voo::getNumero(){
    return numeroVoo;
}

DataHorario Voo::getHorario(){
    return data; 
}

   void  Voo::imprime(){
            cout << "Número: " << this->getNumero() << endl;
            cout <<  "Data: ";
            this->getHorario().imprime(false);
            cout << "Quantidade de Vagas: " << vagas() << endl;
            if (vagas() < 100) {
                cout << "Passageiros: " << endl;
            }
            for (int i = 0; i < 100; i++){
                if (poltronas[i] != NULL) {
                    poltronas[i]->imprime();
                }
            }
   }

int  Voo::proximoLivre(){
int x = 0;
    for (int i = 0; i < 100; i++) {
        if (poltronas[i] == NULL) {
            x= i+1;
        }
    }
    return x;
}

bool  Voo::verifica(int a){
bool x = false;
        if (poltronas[a-1] != NULL) {
            x = true;
        }
    return x;
}

bool  Voo::ocupa(int a, Pessoa& pessoa) {
bool x = false;
        if (poltronas[a-1] == NULL){
            poltronas[a-1] = &pessoa;
            x = true;
        }
return x;
}

bool  Voo::desocupa(int a){
bool x = false;
    if (poltronas[a-1] != NULL){
        poltronas[a-1] = NULL;
        x = true;
    }
return x;    
}

int  Voo::vagas() {
        int x = 0;

        for (int i = 0; i < 100; i++){
            if (poltronas[i] == NULL) {
                x+=1;
            }
        }
    
    return x;
}



