#include <piedras.h>
#include <stdlib.h>
#include <math.h>
#include <QDebug>
#define G 10
#define t 0.01


double piedras::getX() const
{
    return x;
}

void piedras::setX(double value)
{
    x = value;
}

double piedras::getY() const
{
    return y;
}

void piedras::setY(double value)
{
    y = value;
}

float piedras::getVx() const
{
    return vx;
}

void piedras::setVx(float value)
{
    vx = value;
}

float piedras::getVy() const
{
    return vy;
}

void piedras::setVy(float value)
{
    vy = value;
}

float piedras::getAy() const
{
    return ay;
}

void piedras::setAy(float value)
{
    ay = value;
}
QRectF piedras::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);   //tamaño del rectangulo del item
}
void piedras::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        painter -> setBrush(Qt::black);
        painter -> drawEllipse(boundingRect());
}

piedras::piedras()
{
    r = 3 ;      //radio de la bola
    y = 51 + rand()%(451);  //posicion y
    x = 50 + rand()%(951);  //posicion x
    masa = 10 ;   //masa
    vx = 100;// + rand()%(301);  //velocidad x
    vy = 100;//+ rand()%(301); //velocidad en y
    e = 0.5+ ((float)(rand()%11))/10;  //coeficiente de restitucion
    k = ((float)(rand()%11))/1000;  //valores de k

    setPos(x,y);

}

void piedras::calcular_posiciones()
{
    angulo = atan2(vy,vx);
    v = sqrt( pow((vx),2) + pow((vy),2) );
    ax = -((k * pow(v,2) * pow(r,2)) /(masa)) * cos(angulo);   //aceleraciones
    ay = -((k * pow(v,2) * pow(r,2)) / (masa)) * sin(angulo) + 10;  // ""

    vx += ax * t;   //velocidad x
    vy += ay * t;   //velocidad y

    x = x+vx*t+(0.5*ax*t*t);    //posicion x
    y = y+vy*t+(0.5*ay*t*t);    //posicion y

    // modifica la posición del objeto gráfico
    setPos(x,y);

}

void piedras::colision(bool a, bool b)
{
    if(x-r<0){
         x += r;
     }
     if (x+r>604){
         x=604-r;
     }
     if(y-r<0){
         y += r;
     }

     if (r+y>201){
         y = 201 -r;
     }


     if (a){             // choca con los laterales
       vx *= (-e);}
     if(b){
       vy *= (-e);}   // b -> choca con el piso

         setPos(x,y);

}




