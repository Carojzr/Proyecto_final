#ifndef BALA_H
#define BALA_H
#include<math.h>
const double Gravedad=9.8;
const double Pi=3.141592;


class Bala
{
protected:
    float Radio;
    float Vx=0;
    float Vy=0;
    float x;
    float y;
public:
    Bala(float R, float vx, float vy,int x, int y); //constructor
    float getR();
    float getVx();
    float getVy();
    float getX();
    void setX(float x);
    float getY();   
    void setY(float y);
    virtual void movimiento(float t);


};

#endif // BALA_H
