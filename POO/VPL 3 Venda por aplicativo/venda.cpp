#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  for(auto it = this->m_pedidos.begin(); it != this->m_pedidos.end(); ++it){
    delete *it;
  }
}

void Venda::adicionaPedido(Pedido* p) {
  // TODO: Implemente este metodo
  this->m_pedidos.emplace_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  float sum = 0.0;
  int count = 1;
  for(auto it = this->m_pedidos.begin(); it != this->m_pedidos.end(); ++it){
    std::cout << "Pedido " << count << std::endl;
    std::cout << (*it)->resumo();

    sum += (*it)->calculaTotal();
    count++;
  }
  std::cout << "Relatorio de Vendas" << std::endl;
  std::cout << "Total de vendas: R$ ";
  std::cout << std::fixed << std::setprecision(2) << sum << std::endl;
  std::cout << "Total de pedidos: " << count-1 << std::endl;
}