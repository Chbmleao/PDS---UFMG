#include "Alocacao.hpp"

Alocacao::Alocacao(string dia, string horario, string sala){
    this->_dia = dia;
    this->_horario = horario;
    this->_sala = sala;
}

void Alocacao::imprimir_dados(){
    cout << this->_dia << " " << this->_horario << " " << this->_sala << endl;
}