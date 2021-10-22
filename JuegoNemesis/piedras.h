#ifndef PIEDRAS_H
#define PIEDRAS_H
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <math.h>

class piedras: public QGraphicsItem
{
    float masa;
    float angulo;
    float  x, y, vx,vy, v;
    float k, e, ax, ay, adx, ady;
    float r;


public:
     QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    piedras();
    piedras(float _masa, float _k, float _r, float _vx, float _vy );
    void calcular_posiciones();     //calcula x,y,vx,vy,ax,ay
    void colision(bool a, bool b);

    double getX() const;
    void setX(double value);
    double getY() const;
    void setY(double value);
    float getVx() const;
    void setVx(float value);

    float getVy() const;
    void setVy(float value);

    float getAy() const;
    void setAy(float value);
};

#endif // PIEDRAS_H
