#include "navedib.h"

Navedib::Navedib(int alt, int anc,int x, int y, float vo, int tiponv)
{
   if(tiponv==1){
       pixmap= new QPixmap(":/Imagenes/Serenity.png");
       nave= new Nave(alt,anc,x,y,vo,25);
   }
   else if(tiponv==2){
       pixmap= new QPixmap(":/Imagenes/Enano Rojo.png");
       nave= new Nave(alt,anc,x,y,vo,35);
   }
   else if(tiponv==3){
       pixmap= new QPixmap(":/Imagenes/Galactica.png");
       nave= new Nave(alt,anc,x,y,vo,50);
   }
   else if(tiponv==4){
       pixmap= new QPixmap(":/Imagenes/Discovery.png");
       nave= new Nave( alt,anc,x,y,vo,40);
   }
   else if(tiponv==5){
       pixmap= new QPixmap(":/Imagenes/Enterprise.png");
       nave= new Nave( alt,anc,x,y,vo,15);
   }
   setPos(x,y);//posición de las naves
}

QRectF Navedib::boundingRect() const
{
    return QRectF(-1*escala*nave->getWidth()/2,-1*escala*nave->getHigh()/2,escala*nave->getWidth(),escala*nave->getHigh());//puntos iniciales, ancho y alto de cuadro
}

Nave *Navedib::getNave()
{
    return nave;
}

void Navedib::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     painter->drawPixmap(-1*escala*nave->getWidth()/2,-1*escala*nave->getHigh()/2,*pixmap,0,0,2*escala*nave->getWidth(),2*escala*nave->getHigh());

}

void Navedib::setX(int x)//posiciones en x de las naves en la escena
{
    nave->setX(x);
    setPos(x,nave->getY());
}

void Navedib::setY(int y)//posiciones en y de las naves en la escena
{
    nave->setY(y);
    setPos(nave->getX(),y);

}

void Navedib::setEscala(float escal)
{
    escala=escal;
}

