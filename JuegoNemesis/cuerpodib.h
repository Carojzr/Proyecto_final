#ifndef CUERPODIB_H
#define CUERPODIB_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "cuerpo.h"
#include <stdlib.h>
#include <time.h>



class cuerpodib: public QGraphicsItem
{
private:
    cuerpo * esf;
    float escala;
    QColor color=Qt::yellow;
public:
    cuerpodib(float x, float y, float vx, float vy, float masa, float radio);
    ~cuerpodib();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void setEscala(float s);
    void actualizar(float masa, float xcentral, float ycentral, float t);
    cuerpo *getEsf();
    void setColor(QColor color);
};

#endif // CUERPODIB_H
