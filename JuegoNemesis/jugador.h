#ifndef JUGADOR_H
#define JUGADOR_H
#include<QVector>
#include <QString>
#include "navedib.h"


class Jugador
{
private:
    int numNaves;
    int numJugador;
    int disparos;
    int puntos=0;
    QVector<Navedib *> naves={};
    QString nombre;
    QStringList nombreNaves;

public:
    Jugador(QString nombre,int disparos,int numNaves,int numJugador);
    int getDisparos();
    int getPuntos();
    void setPuntos(int puntos);
    void borDisp();
    void disparar(int nave, float angulo, Jugador enemigo);
    QString getNombre();
    QVector<Navedib *> getNave();//vector que obtiene los nombres de las naves
    QStringList getNombreNaves();//almacena los nombres
};

#endif // JUGADOR_H
