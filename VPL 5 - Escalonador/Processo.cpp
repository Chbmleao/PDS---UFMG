#include "Processo.hpp"

using namespace std;

Processo::Processo(int id, std::string nome, int prioridade){
    _id = id;
    _nome = nome;
    _prioridade = prioridade;
    Processo* next = nullptr;
}

void Processo::imprimir_dados (){
    cout << this->_id << " " << this->_nome << " " << this->_prioridade << endl;
}