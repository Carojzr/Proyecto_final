#ifndef BALADIB_H
#define BALADIB_H
#include"bala.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <disparabo.h>
#include <dispmrua.h>


class Baladib: public QGraphicsItem
{
private:
    QPixmap *pixmap;
    Bala * bala;
    float x;
    float y;
    float escala;
    float tipodis;
public:
    Baladib(float R, float vx, float vy, int x, int y,float dato, int tipodis);
    float getX();
    float getY();
    int getTipodis();
    void setEsacala(float escal);
    void actualizar(float x, float y);
    Bala * getBala();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

};

#endif // BALADIB_H
