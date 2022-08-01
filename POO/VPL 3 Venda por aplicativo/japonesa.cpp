#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */
  
  std::string str = "";
  str += std::to_string(this->m_qtd);
  str += "X Comida japonesa - ";
  str += this->_combinado;
  str += ", ";
  str += std::to_string(this->_sushis);
  str += " sushis, ";
  str += std::to_string(this->_temakis);
  str += " temakis e ";
  str += std::to_string(this->_hots);
  str += " hots.";

  str += "\n";

  return str;
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  // TODO: Implemente este metodo.
  this->_combinado = combinado;
  this->_sushis = sushis;
  this->_temakis = temakis;
  this->_hots = hots;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}