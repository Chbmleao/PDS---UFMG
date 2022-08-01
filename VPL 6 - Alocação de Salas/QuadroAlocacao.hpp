#ifndef QUADRO_H
#define QUADRO_H

#include "Disciplina.hpp"
#include <map>
#include <vector>

struct QuadroAlocacao {

    std::map<string, Disciplina*> mapQuadro;

    void inserir_alocacao(string codigo, string nome, string dia, string horario, string sala);
    void remover_alocacao_disciplina(string codigo, string horario);
    vector<Disciplina> recuperar_disciplinas_mais_ofertadas();
    void imprimir_alocacao_completa();

};

#endif