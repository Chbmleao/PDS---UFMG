#ifndef PROCESSO_H
#define PROCESSO_H

#include <iostream>

struct Processo {
    
    int _id;
    int _prioridade;
    std::string _nome;
    Processo* next = nullptr;

    Processo(int id, std::string nome, int prioridade);
    void imprimir_dados();
};

#endif