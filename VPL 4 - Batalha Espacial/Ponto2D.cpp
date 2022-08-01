#include "Ponto2D.hpp"

Ponto2D::Ponto2D(double x, double y){
    _x = x;
    _y = y;
}

double Ponto2D::calcular_distancia(Ponto2D* ponto){
    return sqrt(pow((_x - ponto->_x), 2) + pow((_y - ponto->_y), 2));
}