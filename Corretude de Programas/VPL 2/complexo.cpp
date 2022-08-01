// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() : Complexo(0, 0) {
}

Complexo::Complexo(double a) : Complexo(a, 0) {
}

Complexo::Complexo(double a, double b) {
  this->parteReal_ = a;
  this->parteImaginaria_ = b;
}

double Complexo::real() const {
  return this->parteReal_;
}

double Complexo::imag() const {
  return this->parteImaginaria_;
}

bool Complexo::operator==(Complexo x) const {
  return this->parteReal_ == x.parteReal_ 
      && this->parteImaginaria_ == x.parteImaginaria_;
}

void Complexo::operator=(Complexo x) {
  this->parteReal_ = x.parteReal_;
  this->parteImaginaria_ = x.parteImaginaria_;
} 

double Complexo::modulo() const {
  return sqrt(this->parteReal_ * this->parteReal_ + this->parteImaginaria_ * this->parteImaginaria_);
}

Complexo Complexo::conjugado() const {
  Complexo c;
  c.parteReal_ = this->parteReal_;
  c.parteImaginaria_ = -1 * this->parteImaginaria_;
  return c;
}

Complexo Complexo::operator-() const {
  Complexo c;
  c.parteReal_ = -1 * this->parteReal_;
  c.parteImaginaria_ = -1 * this->parteImaginaria_;
  return c;
}

Complexo Complexo::inverso() const {
  Complexo i;
  double denominador = this->parteReal_ * this->parteReal_ + this->parteImaginaria_ * this->parteImaginaria_;
  i.parteReal_ = this->parteReal_ / denominador;
  i.parteImaginaria_ = -1 * this->parteImaginaria_ / denominador;
  return i;
}

Complexo Complexo::operator+(Complexo y) const {
  Complexo s(real() + y.real(), imag() + y.imag());
  return s;
}

Complexo Complexo::operator-(Complexo y) const {
  return (*this) + -y;
}

Complexo Complexo::operator*(Complexo y) const {
  Complexo p;
  p.parteReal_ = (this->parteReal_ * y.parteReal_) - (this->parteImaginaria_ * y.parteImaginaria_);
  p.parteImaginaria_ = this->parteReal_ * y.parteImaginaria_ + y.parteReal_ * this->parteImaginaria_;
  return p;
}

Complexo Complexo::operator/(Complexo y) const {
  return (*this) * y.inverso();
}
