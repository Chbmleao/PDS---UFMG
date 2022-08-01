#include "celular.hpp"

// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.

int Celular::codeNumber = 0;

Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) {
  // TODO: Implemente este metodo
  this->modelo = modelo;
  this->fabricante = fabricante;
  this->armazenamento = armazenamento;
  this->memoria = memoria;
  this->peso = peso;
  this->cor = cor;
  this->quantidade = qtd;
  this->valor_unitario = valor;
  this->codeNumber++;
  this->cod = codeNumber;
}

bool Celular::operator<(const Celular& other) {
  // TODO: Implemente este metodo. 
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  
  if (this->fabricante != other.fabricante){
    return this->fabricante[0] < other.fabricante[0];
  } else {
    return this->modelo[0] < other.modelo[0];
  }
}