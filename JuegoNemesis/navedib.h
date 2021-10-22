#ifndef NAVEDIB_H
#define NAVEDIB_H
#include <QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include "nave.h"

class Navedib:public QGraphicsItem
{
private:
    Nave *nave;
    QPixmap *pixmap;
    float escala=1;


public:
    Navedib(int alt, int anc,int x, int y,float vo,int tipodnv);
    QRectF boundingRect() const;
    Nave*getNave();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void setX(int x);
    void setY(int y);
    void setEscala(float escal);


};

#endif // NAVEDIB_H
