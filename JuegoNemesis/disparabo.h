#ifndef DISPARABO_H
#define DISPARABO_H
#include "bala.h"


class Disparabo: public Bala
{
private:
    float vo;
    float angulo;
    float t=0;
public:
    Disparabo(float R, float vx, float vy,int x,int y,float angulo);
    void setVo(float vo);
    void setAngulo(float angu);
    float getAngulo();
    void movimiento(float t) ;

};

#endif // DISPARABO_H
