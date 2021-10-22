#ifndef DISPMRUA_H
#define DISPMRUA_H
#include "bala.h"


class Dispmrua: public Bala
{
private:
    float angulo;
    float vo;
    float t=0;
    float acel;
    float G=50;//6.67384*pow(10,-11);
public:
    Dispmrua(float R, float vx, float vy, int x, int y, float acel);
    void setAceleracion(float acel);
    float getAceleracion();
    void setVo(float vo);
    void movimiento(float t);

};

#endif // DISPMRUA_H
