#include "jugador.h"
#include <iostream>


Jugador::Jugador(QString nombre,int disparos,int numNaves, int numJugador)
{
    this->numNaves=numNaves;
    this->numJugador=numJugador;
    this->disparos=disparos;
    this->nombre=nombre;
    //agrega un número de naves por nivel
    if(numNaves==5){
        naves.append(new Navedib(90,60,-350,-110,1.5,1));
        nombreNaves.append("Serenity");
        naves.append(new Navedib(80,55,-140,-110,1.5,4));
        nombreNaves.append("Discovery");
        naves.append(new Navedib(80,50,-190,10,1.5,5));
        nombreNaves.append("Enterprise");
        naves.append(new Navedib(60,70,-450,140,1.5,3));
        nombreNaves.append("Galactica");
        naves.append(new Navedib(120,35,-300,50,1.5,2));
        nombreNaves.append("Enano Rojo");
    }

    else if(numNaves==4){
        naves.append(new Navedib(80,50,-300,-90,1.5,1));
        nombreNaves.append("Serenity");
        naves.append(new Navedib(125,61,-140,-110,1.5,4));
        nombreNaves.append("Discovery");
        naves.append(new Navedib(80,50,-190,10,1.5,5));
        nombreNaves.append("Enterprise");
        naves.append(new Navedib(80,90,-350,50,1.5,3));
        nombreNaves.append("Galactica");

    }
    else{
        naves.append(new Navedib(80,50,-300,-80,1.5,1));
        nombreNaves.append("Serenity");
        naves.append(new Navedib(80,50,-190,10,1.5,5));
        nombreNaves.append("Enterprise");
        naves.append(new Navedib(80,90,-310,40,1.5,3));
        nombreNaves.append("Galactica");

    }
     std::cout << naves.size()<<std::endl;


}

int Jugador::getDisparos()
{
    return disparos;
}

int Jugador::getPuntos()
{
    return puntos;
}

void Jugador::borDisp()
{
    this->disparos--;
}

void Jugador::setPuntos(int puntos)
{
    this->puntos+=puntos;
}

QVector<Navedib *> Jugador::getNave()
{
    return naves;
}
QString Jugador::getNombre()
{
    return nombre;
}
QStringList Jugador::getNombreNaves()
{
 return nombreNaves;
}


