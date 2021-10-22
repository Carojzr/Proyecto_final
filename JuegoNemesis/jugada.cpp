#include "jugada.h"

Jugada::Jugada(QString nombre, Jugador *jugador1, Jugador *jugador2,int nivel)
{
    this->nombre=nombre;
    this->nivel=nivel;
    this->jugador1=jugador1;
    this->jugador2=jugador2;
}

QString Jugada::getNombre()
{
    return nombre;
}

void Jugada::setNombre(QString nombre)
{
    this->nombre=nombre;
}

int Jugada::getNivel()
{
    return nivel;
}

void Jugada::setNivel(int nivel)
{
    this->nivel=nivel;
}

Jugador *Jugada::getJugador1()
{
    return jugador1;
}

void Jugada::set_jugador1(Jugador *jugador1)
{
    this->jugador1=jugador1;
}

Jugador *Jugada::getJugador2()
{
    return jugador2;
}

void Jugada::set_jugador2(Jugador *jugador2)
{
    this->jugador2=jugador2;
}

QVector<Disparo *> Jugada::getDisparos1()
{
    return disparos1;
}

void Jugada::setDisparos1(QVector<Disparo *> disparos)
{
    this->disparos1=disparos;
}

QVector<Disparo *> Jugada::getDisparos2()
{
    return disparos2;
}

void Jugada::setDisparos2(QVector<Disparo *> disparos)
{
    this->disparos2=disparos;
}


