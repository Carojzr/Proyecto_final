#include "nave.h"

Nave::Nave( int alt, int anc,int x, int y, float vo, int ptos)
{
    this-> x=x;
    this-> y=y;
    this-> high=alt;
    this-> width=anc;
    this-> puntos=ptos;
    this-> vo=vo;

}

Baladib *Nave::disparar(float R, float vx, float vy, float dato, int tipodis)
{
    bala=new Baladib(R,vx,vy,this->x,this->y,dato,tipodis);
    return bala;
}

int Nave::getHigh()
{
    return high;
}

int Nave::getWidth()
{
    return width;
}

int Nave::getY()
{
    return y;
}

int Nave::getX()
{
    return x;
}

float Nave::getVo()
{
    return vo;
}

float Nave::getAngulo()
{
    return angulo;
}

void Nave::setAngulo(float ang)
{
    this->angulo=ang;
}

void Nave::setX(int x)
{
    this->x= x;
}

void Nave::setY(int y)
{
    this->y=y;
}

int Nave::getPuntos()
{
    return puntos;
}


