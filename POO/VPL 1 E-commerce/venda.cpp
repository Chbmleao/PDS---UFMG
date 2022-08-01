#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>

void Venda::adicionaCelular(const Celular& celular) {
  // TODO: Implemente este metodo
  this->m_celulares.push_back(celular);
}

bool compareToSort (Celular a, Celular b){
  if (a.fabricante != b.fabricante){
    return a.fabricante < b.fabricante;
  } else {
    return a.modelo < b.modelo;
  }
}

void Venda::ordena() {
  // TODO: Implemente este metodo
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  this->m_celulares.sort(compareToSort);
  
}

void Venda::recarregaEstoque(int cod, int qtd) {
  // TODO: Implemente este metodo
  for (std::list<Celular>::iterator it = m_celulares.begin(); it != m_celulares.end(); it++)
  {
    if (it->cod == cod)
      it->quantidade += qtd;
  } 
}

void Venda::efetuaVenda(int cod, int qtd) {
  // TODO: Implemente este metodo
  /**
   * Observe na descricao do enunciado que nao e permita a venda de um modelo
   * cuja quantidade seja maior que a quantidade atual em estoque.
   * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
   * partir de 6 unidades devem ser ignoradas.
   */
   for (std::list<Celular>::iterator it = m_celulares.begin(); it != m_celulares.end(); it++)
  {
    if (it->cod == cod && it->quantidade >= qtd){
        it->quantidade -= qtd;
        if (it->quantidade == 0)
        {
          removeModelo(cod);
        }
        break;
    }
  } 
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
  // TODO: Implemente este metodo
  for (std::list<Celular>::iterator it = m_celulares.begin(); it != m_celulares.end(); it++)
  {
    if (it->fabricante == fabricante)
        it->valor_unitario -= (it->valor_unitario * desconto/100);
  } 
}

void Venda::removeModelo(int cod) {
  // TODO: Implemente este metodo
  for (std::list<Celular>::iterator it = m_celulares.begin(); it != m_celulares.end(); it++)
  {
    if (it->cod == cod){
        m_celulares.erase(it);
        break;
    }
  } 
}

void Venda::imprimeEstoque() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce tera que imprimir a lista de celulares em estoque com as
   * restricoes descritas no enunciado do problema. Notem no exemplo que a
   * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
   * apenas um item em estoque de determinado modelo de celular, voce tera que
   * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
   * celulares com pelo menos um item em estoque deverao ser exibidos.
   */

  for (auto const i : m_celulares)
  {
    std::cout << i.fabricante << " ";
    std::cout << i.modelo << ", ";
    std::cout << i.armazenamento << "GB, ";
    std::cout << i.memoria << "GB RAM, ";
    std::cout << int(i.peso * 1000) << " gramas, ";
    std::string aux = "";
    std::locale loc;
    aux += std::toupper(i.cor[0], loc);
    aux += i.cor.substr(1,i.cor.size());
    std::cout << aux << ", ";
    if(i.quantidade == 1)
      std::cout << i.quantidade << " restante, ";
    else
      std::cout << i.quantidade << " restantes, ";
    std::cout << "R$ " << std::fixed << std::setprecision(2) << i.valor_unitario  << std::endl;
  }  
}