#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "Alocacao.hpp"
#include <map>

struct Disciplina {

    string _codigo, _nome;
    std::map<int, Alocacao*> m;

    Disciplina(string codigo, string nome);
    void inserir_alocacao(string dia, string horario, string sala);
    void remover_alocacao(string horario);
    void imprimir_alocacao();

};

#endif