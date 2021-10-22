#include "bala.h"
#include "iostream"


Bala::Bala(float R, float vx, float vy, int x, int y)
{
    //llamamos a la funcion, con this apunto al objeto que la llama
    this->Radio=R;
    this ->Vx=vx;
    this ->Vy=vy;
    this->x=x;
    this->y=y;
    std::cout <<"x "<<x<<std::endl;
    std::cout <<"y "<<y<<std::endl;
}


float Bala::getR()
{
    return  Radio;

}

float Bala::getVx()
{
    return Vx;

}

float Bala::getVy()
{
    return  Vy;
}

float Bala::getX()
{
    return x;
}
void Bala::setX(float x)
{
    this ->x=x;
}
float Bala::getY()
{
    return y;
}

void Bala::setY(float y)
{
    this->y=y;
}

void Bala::movimiento(float t)
{

}
