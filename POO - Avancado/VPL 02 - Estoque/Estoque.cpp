#include <string>
#include <iostream>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if(this->_m[mercadoria])
    this->_m[mercadoria] += qtd;
  else
    this->_m[mercadoria] = qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if(this->_m[mercadoria] < qtd)
    std::cout << mercadoria << " insuficiente" << std::endl;
  else if (!(this->_m[mercadoria]))
    std::cout << mercadoria << " inexistente" << std::endl;
  else
    this->_m[mercadoria] -= qtd;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  std::map<std::string, int> mapEstoque = this->_m;
  
  if(mapEstoque[mercadoria])
    return mapEstoque[mercadoria];
  else
    return 0;
}

void Estoque::imprime_estoque() const {
  for(auto it = this->_m.begin(); it != this->_m.end(); it++){
    std::cout << it->first << ", " << it->second << std::endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  for(auto it = rhs._m.begin(); it != rhs._m.end(); it++){
    this->add_mercadoria(it->first, it->second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for(auto it = rhs._m.begin(); it != rhs._m.end(); it++){
    this->sub_mercadoria(it->first, it->second);
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  for(auto it = lhs._m.begin(); it != lhs._m.end(); it++){
    if(it->second >= rhs._m[it->first])
      return false;
  }
  return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  return rhs < lhs;
}