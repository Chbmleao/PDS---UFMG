#include "Nave.hpp"
#include <iostream>

using namespace std;

Nave::Nave(Ponto2D posicao, double forca){
    _posicao = posicao;
    _forca = forca;
    _energia = 100;
}

void Nave::mover(double dx, double dy){
    _posicao._x += dx;
    _posicao._y += dy;
}

double Nave::calcular_distancia(Nave* nave){
    return _posicao.calcular_distancia(&nave->_posicao);
}

Nave* Nave::determinar_nave_mais_proxima(Nave** naves, int n){
    double auxDist=0, menorDist = 0;
    Nave* menorNave;

    for (int i = 0; i < n; i++)
    {
        if(naves[i]!=this){
            auxDist = this->calcular_distancia(naves[i]);
            if(menorDist==0){
                menorDist = auxDist;
                menorNave = naves[i];
            }
            else if (auxDist < menorDist){
                menorDist = auxDist;
                menorNave = naves[i];
            }
        }
    }
    return menorNave;
}

void Nave::atacar(Nave** naves, int n){
    Nave* alvo = this->determinar_nave_mais_proxima(naves, n); 
    double distancia = this->calcular_distancia(alvo);
    double dano = (100/distancia)*this->_forca;

    if (dano >= 30)
        alvo->_energia -= 30;
    else    
        alvo->_energia -= dano;
    
    if (alvo->_energia <= 50)
        cout << "Energia baixa!";
}

void Nave::imprimir_status(){
    cout << this->_posicao._x << " " << this->_posicao._y << " " << this->_energia << endl;
}

