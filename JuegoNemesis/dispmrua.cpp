#include "dispmrua.h"



Dispmrua::Dispmrua(float R, float vx, float vy, int x, int y, float acel): Bala(R,vx,vy,x,y)
{
    this->acel=acel;
}
void Dispmrua::movimiento(float t)//ecuaciones movimiento
{
    this->t+=0.0001;// tiempo en el que cambia
    Vx=this->acel*this->t;
    this->x=x+Vx*this->t;
    this->y=y;
   ;

}

void Dispmrua::setAceleracion(float acel)
{
    this->acel=acel;

}

float Dispmrua::getAceleracion()
{
    return acel;
}

void Dispmrua::setVo(float vo)
{
    this->vo=vo;

}

