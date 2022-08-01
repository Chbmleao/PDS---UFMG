#include "QuadroAlocacao.hpp"

void QuadroAlocacao::inserir_alocacao(
    string codigo, 
    string nome, 
    string dia, 
    string horario, 
    string sala
    ){
    Disciplina* materia = new Disciplina(codigo, nome);
    std::map<string, Disciplina*>::iterator it;
    for(it = this->mapQuadro.begin(); it != this->mapQuadro.end(); it++){
        if(it->first == codigo){
            this->mapQuadro[codigo]->inserir_alocacao(dia, horario, sala);
            return;
        }
    }
    this->mapQuadro[codigo] = materia;
    this->mapQuadro[codigo]->inserir_alocacao(dia, horario, sala);
}

void QuadroAlocacao::remover_alocacao_disciplina(string codigo, string horario){
    this->mapQuadro[codigo]->remover_alocacao(horario);
}

vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas(){
    vector<Disciplina> v;
    int maior = 0;
    std::map<string, Disciplina*>::iterator it;
    
    for(it = this->mapQuadro.begin(); it != this->mapQuadro.end(); it++){
        if(int(it->second->m.size()) > maior)
            maior = it->second->m.size();
    }

    for(it = this->mapQuadro.begin(); it != this->mapQuadro.end(); it++){
        if(int(it->second->m.size()) == maior)
            v.push_back(*it->second);
    }
    
    return v;
}

void QuadroAlocacao::imprimir_alocacao_completa(){
    std::map<string, Disciplina*>::iterator it;
    for(it = this->mapQuadro.begin(); it != this->mapQuadro.end(); it++){
        it->second->imprimir_alocacao();
    }
}