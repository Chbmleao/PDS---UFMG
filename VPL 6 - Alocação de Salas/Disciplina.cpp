#include "Disciplina.hpp"

Disciplina::Disciplina(string codigo, string nome){
    this->_codigo = codigo;
    this->_nome = nome;
    std::map<int, Alocacao> m;
}

int convert_schedule_to_int(string schedule){
    string aux1 = "";
    string aux2 = "";
    int activate = 0;

    for(char c: schedule){
        if(c == '-'){
            break;
        } else if(c == ':'){
            activate = 1;
        }

        if(activate == 0){
            aux1 += c;
        } else if (c != ':') {
            aux2+= c;
        }
    }
    
    return stoi(aux1)*100 + stoi(aux2);
}

void Disciplina::inserir_alocacao(string dia, string horario, string sala){
    Alocacao* aula = new Alocacao(dia, horario, sala);
    this->m[convert_schedule_to_int(horario)] = aula;
}

void Disciplina::remover_alocacao(string horario){
    this->m.erase(convert_schedule_to_int(horario));
}

void Disciplina::imprimir_alocacao(){
    std::map<int, Alocacao*>::iterator it;
    for (it = this->m.begin(); it != this->m.end(); it++){
        std::cout << this->_codigo << " " << this->_nome << " ";
        it->second->imprimir_dados();
    }
}