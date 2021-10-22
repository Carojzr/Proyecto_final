#include "disparo.h"


Disparo::Disparo(int wid, int hig, int x, int y)
{
    this->posx=x;
    this->posy=y;
    this->width=wid;
    this->high=hig;
    pixmap= new QPixmap(":/Imagenes/balag.png");
    setPos(x,y);

}
QRectF Disparo::boundingRect() const
{
     return QRectF(-1*width/2,-1*high/2,width,high);//puntos iniciales y ancho y alto de cuadro
}
void Disparo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-1*width/2,-1*high/2,*pixmap,0,0,2*width,2*high);

}


