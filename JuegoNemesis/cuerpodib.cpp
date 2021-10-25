#include "cuerpodib.h"

cuerpodib::cuerpodib(float x, float y, float vx, float vy, float masa, float radio):escala(1)
{
    float posx,posy,velx,vely,mass,r;
    posx = x;
    posy = y;
    r = radio;
    mass = masa;
    velx = vx;
    vely = vy;

    esf=new cuerpo(x,y,vx,vy,mass,r);
    setPos(esf->getPX(),esf->getPY());
}
cuerpodib::~cuerpodib()
{
    delete esf;
}

QRectF cuerpodib::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR()); // construye toda la esfera
}

void cuerpodib::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

void cuerpodib::setEscala(float s)
{
    escala = s;
}

void cuerpodib::actualizar(float masa, float xcentral, float ycentral, float t)// actualiza posiciones
{

    esf->actualizar(masa,xcentral,ycentral,t);
    setPos(esf->getPX()*escala,esf->getPY()*escala);
}

cuerpo *cuerpodib::getEsf()
{
    return esf;
}

void cuerpodib::setColor(QColor color)
{
    this->color=color;
}



