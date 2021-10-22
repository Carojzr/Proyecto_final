#ifndef JUGADA_H
#define JUGADA_H
#include <QVector>
#include "jugador.h"
#include "disparo.h"


class Jugada
{
private:
    QString nombre;
    int nivel;
    Jugador *jugador1;
    QVector <Disparo*> disparos1;
    Jugador *jugador2;
    QVector <Disparo*> disparos2;

public:
    Jugada(QString nombre,Jugador *jugador1,Jugador *jugador2,int nivel);
    QString getNombre();
    void setNombre(QString nombre);//asigna el nombre de la partida
    int getNivel();//obtiene el numero del nivel en el que se esté
    void setNivel(int nivel);
    Jugador* getJugador1();
    void set_jugador1(Jugador *jugador1);
    Jugador* getJugador2();
    void set_jugador2(Jugador *jugador2);
    QVector <Disparo*> getDisparos1();//vector que obtiene los disparos
    void setDisparos1(QVector <Disparo*> disparos);//se obtienen los disparos
    QVector <Disparo*> getDisparos2();
    void setDisparos2(QVector <Disparo*> disparos);










};

#endif // JUGADA_H
