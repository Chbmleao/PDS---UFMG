#ifndef ALOCACAO_H
#define ALOCACAO_H

#include <iostream>
using namespace std;

struct Alocacao {

    string _dia, _horario, _sala;

    Alocacao(string dia, string horario, string sala);
    void imprimir_dados();
    
};

#endif