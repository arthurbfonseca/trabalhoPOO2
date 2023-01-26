#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa {
public:
    Pessoa(string, string);
    string getCPF();
    string getNome();
    void imprime();
private:
    string CPF;
    string nome;
};

#endif