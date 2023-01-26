#include <iostream>
#include "Pessoa.h"

using namespace std;

Pessoa::Pessoa(string CPF, string nome) : CPF(CPF), nome(nome)  {
}

string Pessoa::getNome(){
    return nome;
}

string Pessoa::getCPF(){
    return CPF;
}
void Pessoa::imprime(){
    cout << "CPF: " << CPF << ". Nome: " << nome << endl;
}
