#include "pedido.hpp"


Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  for(auto it = this->m_produtos.begin(); it != this->m_produtos.end(); ++it){
    delete *it;
  }
}

void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.
  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  // TODO: Implemente este metodo.
  float sum = 0;
  for(auto it = this->m_produtos.begin(); it != this->m_produtos.end(); ++it){
    sum += (*it)->getValor() * (*it)->getQtd();
  }
  return sum;
}

void Pedido::adicionaProduto(Produto* p) {
  // TODO: Implemente este metodo.
  this->m_produtos.emplace_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  std::string str = "";
  for(auto it = this->m_produtos.begin(); it != this->m_produtos.end(); ++it){
    str += (*it)->descricao();
  }
  str += "Endereco: ";
  str += this->m_endereco;
  str += "\n";

  return str;
}