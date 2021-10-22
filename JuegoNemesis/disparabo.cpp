#include "disparabo.h"


Disparabo::Disparabo(float R, float vx, float vy, int x, int y,float angulo): Bala(R,vx,vy,x,y)
{
    this ->angulo=angulo;
}


void Disparabo::movimiento(float t)//ecuaciones de movimiento
{
    this->t+=0.001*t; //tiempo en el que van cambiando las ecuaciones
    //ecuaciones posicion de particula
    x = x + Vx*this->t;
    y = y + Vy*this->t -(0.5*Gravedad*this->t*this->t);
   //ecuaciones de velocidades
    Vx = vo*cos((angulo)*Pi/180);//pi/180 para tener el ángulo en radiades
    Vy = vo*sin((angulo)*Pi/180);


}

void Disparabo::setVo(float vo)
{
    this->vo=vo;
}

void Disparabo::setAngulo(float angu)
{
    this->angulo=angu;
}

float Disparabo::getAngulo()
{
    return angulo;
}

