#ifndef MURO_H
#define MURO_H
#include<QGraphicsItem>
#include<QPainter>

class muro: public QGraphicsItem
{
    int w,h;
    int posx, posy;

public:
    muro(int w_, int h, int x, int y);
    QRectF boundingRect() const; //dibuja el area en la que esta el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option , QWidget *witget = nullptr);
};

#endif // MURO_H
