#ifndef DISPARO_H
#define DISPARO_H
#include <QGraphicsItem>
#include <QPixmap>
#include<QPainter>


class Disparo:public QGraphicsItem
{
private:
    QPixmap *pixmap;
    int posx, posy;
    int width,high;

public:
    Disparo(int wid, int hig, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // DISPARO_H
