#include "cuerpo.h"
#include<math.h>
cuerpo::cuerpo(float PX, float PY, float vx, float vy, float masa, float radio)
{
    this->xo=PX;
    this->yo=PY;
    this->PX = PX; //pos en x
    this->PY = PY; //pos en y
    this->R = radio; //radio del cuerpo
    this->masa=masa;
    this->VX=vx;
    this->VY=vy;
}

cuerpo::~cuerpo()
{

}

float cuerpo::getmasa() const
{
    return masa;
}

float cuerpo::getPX() const
{
    return PX;
}

float cuerpo::getPY() const
{
    return PY;
}


float cuerpo::getR() const
{
    return R;
}

float cuerpo::getxo() const
{
    return xo;
}

float cuerpo::getyo() const
{
    return yo;
}

void cuerpo::getr(float x, float y)
{
    r = sqrt((pow((x-PX),2)+pow((y-PY),2))); //distancia
}


void cuerpo::actualizar(float mass, float xcentral, float ycentral, float t) //ecuaciones de movimiento
{

    AX = Gr*mass*(xcentral-PX)/pow(r,3);
    AY = Gr*mass*(ycentral-PY)/pow(r,3);
    VX=VX+(AX*t);
    VY=VY+(AY*t);
    PX=PX+(VX*t);
    PY=PY+(VY*t);
}

float cuerpo::getVX() const
{
    return VX;
}

float cuerpo::getVY() const
{
    return VY;
}

float cuerpo::getAX()
{
    return AX;
}

float cuerpo::getAY()
{
    return AY;
}
