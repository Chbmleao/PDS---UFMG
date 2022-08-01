#ifndef NAVE_H
#define NAVE_H

#include "Ponto2D.hpp"

struct Nave
{
    Ponto2D _posicao;
    double _forca;
    double _energia;

    Nave(Ponto2D, double forca=1);
    void mover(double dx, double dy);
    double calcular_distancia(Nave* nave);
    Nave* determinar_nave_mais_proxima(Nave** naves, int n);
    void atacar(Nave** naves, int n);
    void imprimir_status();
};

#endif