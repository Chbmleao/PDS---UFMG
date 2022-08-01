#include "pizza.hpp"

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
  std::string str = "";
  str += std::to_string(this->m_qtd);
  str += "X Pizza ";
  str += this->_sabor;
  str += ", ";
  str += std::to_string(this->_pedacos);
  str += " pedacos ";
  if(this->_borda_recheada)
    str += "e borda recheada.";
  else
    str += "e sem borda recheada.";

  str += "\n";
  
  return str;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  // TODO: Implemente este metodo.
  this->_sabor = sabor;
  this->_pedacos = pedacos;
  this->_borda_recheada = borda_recheada;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}