#include "fila.h"

struct No {
  int chave;
  No* proximo;
};

Fila::Fila() {
  this->primeiro_ = nullptr;
  this->ultimo_ = nullptr;
}

void Fila::Inserir(int k) {
  No *pessoa = new No;
  pessoa->chave = k;
  pessoa->proximo = nullptr;
  if(this->tamanho() == 0){
    this->primeiro_ = pessoa;
    this->ultimo_ = pessoa;
  } else {
    this->ultimo_->proximo = pessoa;
    this->ultimo_ = pessoa;
  }
}

void Fila::RemoverPrimeiro() {
  if(tamanho() == 0) throw ExcecaoFilaVazia();
  if(tamanho() == 1){
    delete(this->primeiro_);
    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
  } else {
    No* auxiliar = new No;
    auxiliar->proximo = this->primeiro_->proximo;
    delete(this->primeiro_);
    this->primeiro_ = auxiliar->proximo;
    delete(auxiliar);
  }
}

int Fila::primeiro() const {
  if(tamanho() == 0) throw ExcecaoFilaVazia();
  return this->primeiro_->chave; 
}

int Fila::ultimo() const {
  if(tamanho() == 0) throw ExcecaoFilaVazia();
  return this->ultimo_->chave;
}

int Fila::tamanho() const {
  int tamanhoFila = 0;
  No *pessoaAtual = this->primeiro_;

  if(this->primeiro_ != nullptr){
    tamanhoFila++;
  } else {
    return tamanhoFila;
  }
  while(pessoaAtual->proximo != nullptr){
    tamanhoFila++;
    pessoaAtual = pessoaAtual->proximo;
  }
  return tamanhoFila;
}
