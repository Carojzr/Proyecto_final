#include "baladib.h"
#include "math.h"
#include <cmath>



Baladib::Baladib(float R, float vx, float vy,int x, int y, float dato, int tipodis)
{
    if(x<0){
        pixmap=new QPixmap(":/Imagenes/balas3ida.png");
    }
    else{
        pixmap=new QPixmap(":/Imagenes/balas3vuel.png");
    }
    if (tipodis==1){
        float vo=pow(pow(vx,2)+pow(vy,2),1/2); //vector velocidad
        Disparabo *balap =new Disparabo(R,vo,0,0,0, dato);
        balap ->setVo(vx);
        bala=balap;
        setPos(x,y+30);//30 pixeles mas en la parte gráfica
    }
    else{
        float vo=pow(pow(vx,2)+pow(vy,2),1/2);
        Dispmrua *balap= new Dispmrua(R,vo,0,0,0,dato);
        balap ->setVo(vx);
        bala=balap;
        setPos(x+30,y);

    }
    this->x=x;
    this-> y=y;
    this->tipodis=tipodis;

}

float Baladib::getX()
{
    return x;
}

float Baladib::getY()
{
    return y;
}

int Baladib::getTipodis()
{
    return tipodis;

}

void Baladib::setEsacala(float escal)
{
    escala=escal;
}

void Baladib::actualizar(float x, float y)
{
    this->x=x;
    this->y=y;
    setPos(x,y);
}

Bala *Baladib::getBala()
{

    return  bala;
}

QRectF Baladib::boundingRect() const
{
     return QRectF(-1*escala*bala->getR()/2,-1*escala*bala->getR()/2,escala*bala->getR(),escala*bala->getR());
}


void Baladib::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-1*escala*bala->getR()/2,-1*escala*bala->getR()/2,*pixmap,0,0,2*escala*bala->getR(),2*escala*bala->getR());

}
