#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
  std::string str = "";
  str += std::to_string(this->m_qtd);
  str += "X Hamburguer ";
  str += this->_tipo;
  if (this->_artesanal)
    str += " artesanal.";
  else
    str += " simples.";
  
  str += "\n"; 
  
  return str;
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  // TODO: Implemente este metodo.
  this->_tipo = tipo;
  this->_artesanal = artesanal;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}