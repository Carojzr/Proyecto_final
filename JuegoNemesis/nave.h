#ifndef NAVE_H
#define NAVE_H
#include "baladib.h"


class Nave
{
private:
    int x;
    int y;
    int high;// alto
    int width; //ancho
    int puntos;
    float vo;
    float v0x;
    float v0y;
    float angulo;
    Baladib *bala;


public:
    Nave(int alt, int anc,int x, int y,float vo,int ptos);
    Baladib *disparar(float R, float vx, float vy,float dato, int tipodis);
    int getHigh();
    int getWidth();
    int getY();
    int getX();
    int getPuntos();
    float getVo();
    float getAngulo();
    void setX(int x);
    void setY(int y);
    void setAngulo(float ang);

};

#endif // NAVE_H
