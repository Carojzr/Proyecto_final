#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <iostream>

#define pi 3.1416


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    timer1 = new QTimer;
    timer=new QTimer(this);
    timer2=new QTimer;
    setFixedSize(1265,695);
    ui->setupUi(this);
    this->jugador1=new Jugador("Jugador 1",5,5,1);
    this->jugador2=new Jugador("Jugador 2",5,5,2);
    juegoActual=new Jugada("default", this->jugador1,this->jugador2,1);//se crea una neuva partida
    setnivel(nivel, juegoActual);




    l1 = new QGraphicsLineItem(-604,-201,604,-201); // <-- Linea arriba
    l2 = new QGraphicsLineItem(-604,-200,-604,200); // <-- Linea izquierda
    l3 = new QGraphicsLineItem(604,201,-604,201); // <-- Linea  abajo
    l4 = new QGraphicsLineItem(604,200,604,-200); // <-- Linea derecha
    scene -> addItem(l1);
    scene -> addItem(l2);
    scene -> addItem(l3);
    scene -> addItem(l4);
    timer->stop();
    timer2->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizacion()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(mover()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer1->start(30);
    timer2->start(dtt_);

//    w2= new QMainWindow(this);
//    scene3=new QGraphicsScene();
//    v2=new QGraphicsView(scene3,w2);
//    v2->setGeometry(0,0,400,400);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::setjugador1(Jugador *jugador1)
{
    disparos1.clear();
    nave1=NULL;
    for (int i=0;i<jugador1->getNave().size() ;i++) {//recorre desde i=0, hasta las naves que tenemos
        scene->addItem(jugador1->getNave()[i]);//ciclo que añade las naves a la escena
    }
    for (int i=0;i<jugador1->getDisparos() ;i++ ) {//la variable jugador1 apunta a getDisparos en la clase jugador, que obtiene los disparos que va teniendo cada jugador
        Disparo *dis=new Disparo(15,43,-90+(i*20),0);//de la clase disparo, crea un disparo(contador de balas), y le asigna los parámetros para posicionarla en la escena
        disparos1.append(dis);
        scene1->addItem(dis);
    }
    ui->lista1->addItems(jugador1->getNombreNaves());//desplega la lista de las naves del primer jugador
}

void MainWindow::setjugador2(Jugador *jugador2)
{
    disparos2.clear();
    nave2=NULL;
    for (int i=0;i<jugador2->getNave().size() ;i++) {// get naves, es de tipo navedib, que a su vez es de tipo nave
        int x=jugador2->getNave()[i]->getNave()->getX();
        jugador2->getNave()[i]->setX((-1*x));//se invierte la posición de x, por que queda al lado contrario de la pantalla
        scene->addItem(jugador2->getNave()[i]);
    }
    for (int i=0;i<jugador2->getDisparos() ;i++ ) {
        Disparo *dis=new Disparo(15,43,-90+(i*20),0);
        disparos2.append(dis);
        scene2->addItem(dis);
    }
    ui->lista2->addItems(jugador2->getNombreNaves());

}

void MainWindow::setnivel(int nivel, Jugada *jugada)
{

    scene=new QGraphicsScene;//crea las diferentes escenas para los nivles
    scene1=new QGraphicsScene;
    scene2=new QGraphicsScene;
    ui->graphicsView_2->setScene(scene);
    ui->balas1->setScene(scene1);
    ui->balas2->setScene(scene2);
    scene->setSceneRect(-width/2,-high/2,width,high);//define el tamaño de la escena
    scene1->setSceneRect(-90,-20,180,40);
    scene2->setSceneRect(-90,-20,180,40);

    ui->lista1->clear();
    ui->lista1->addItem("Seleccione Nave"); //nombre a mostrar de la lista
    ui->lista2->clear();
    ui->lista2->addItem("Seleccione Nave");
    ui->Disparar1->setEnabled(false);
    ui->Disparar2->setEnabled(false);


    nave1=NULL;
    nave2=NULL;
                                                    //agrega a la escena
    if(nivel==1){
        ui->nivel->setText("Nivel 1");
        this->jugador1=new Jugador("Jugador 1",5,5,1);
        this->jugador2=new Jugador("Jugador 2",5,5,2);
        this->juegoActual->set_jugador1(this->jugador1);
        this->juegoActual->set_jugador2(this->jugador2);
        int j1=this->jugador1->getPuntos();
        ui->puntaje1->setText(QString::number(j1));
        ui->puntaje2->setText(QString::number(this->jugador2->getPuntos()));
        setjugador1(this->jugador1);
        setjugador2(this->jugador2);
        this->juegoActual->setDisparos1(this->disparos1);
        this->juegoActual->setDisparos2(this->disparos2);
        this->juegoActual->setNivel(1);
    }
    else if(nivel==2){                      //desactiva las flechas
            ui->fleup1->setEnabled(false);
            ui->fleder1->setEnabled(false);
            ui->fleizq1->setEnabled(false);
            ui->flebaj1->setEnabled(false);
            ui->fleup2->setEnabled(false);
            ui->fleder2->setEnabled(false);
            ui->fleizq2->setEnabled(false);
            ui->flebaj2->setEnabled(false);
            ui->Disparar1->setEnabled(true);
            ui->Disparar2->setEnabled(true);

            iniciar=true;

            ui->nivel->setText("Nivel 2");
            this->jugador1=new Jugador("Jugador 1",4,4,1);
            this->jugador2=new Jugador("Jugador 2",4,4,2);

            int p1=ui->puntaje1->text().toInt();
            this->jugador1->setPuntos(p1);
            int p2=ui->puntaje2->text().toInt();
            this->jugador2->setPuntos(p2);

            setjugador1(this->jugador1);
            setjugador2(this->jugador2);

            this->juegoActual->set_jugador1(this->jugador1);
            this->juegoActual->set_jugador2(this->jugador2);

            this->juegoActual->setDisparos1(this->disparos1);
            this->juegoActual->setDisparos2(this->disparos2);
            this->juegoActual->setNivel(2);

        }else if(nivel==3){
            ui->fleup1->setEnabled(false);
            ui->fleder1->setEnabled(false);
            ui->fleizq1->setEnabled(false);
            ui->flebaj1->setEnabled(false);
            ui->fleup2->setEnabled(false);
            ui->fleder2->setEnabled(false);
            ui->fleizq2->setEnabled(false);
            ui->flebaj2->setEnabled(false);
            ui->Disparar1->setEnabled(true);
            ui->Disparar2->setEnabled(true);

            iniciar=true;

            ui->nivel->setText("Nivel 3");
            this->jugador1=new Jugador("Jugador 1",3,3,1);
            this->jugador2=new Jugador("Jugador 2",3,3,2);

            int p1=ui->puntaje1->text().toInt();
            this->jugador1->setPuntos(p1);
            int p2=ui->puntaje2->text().toInt();
            this->jugador2->setPuntos(p2);

            setjugador1(this->jugador1);
            setjugador2(this->jugador2);

            this->juegoActual->set_jugador1(this->jugador1);
            this->juegoActual->set_jugador2(this->jugador2);

            this->juegoActual->setDisparos1(this->disparos1);
            this->juegoActual->setDisparos2(this->disparos2);
            this->juegoActual->setNivel(3);
       }else{                                   //mensajes de ganar o empatar
        if(jugador1->getPuntos()>jugador2->getPuntos()){
            mensaje.setText("Jugador 1 ha ganado");
        }else if(jugador1->getPuntos()<jugador2->getPuntos()){
             mensaje.setText("Jugador 2 ha ganado");
        }else{
             mensaje.setText("Juego empatado");
        }
        mensaje.exec();
    }
}


void MainWindow::on_lista1_currentIndexChanged(int index)
{
    std::cout <<jugador1->getNave().size()<<std::endl;
    if(index>0){
        nave1=jugador1->getNave()[index-1];
    }
}


void MainWindow::on_tipo1_currentIndexChanged(int index)  //lista tipo de disparo jugador1
{
    if(index==0){
        DisParabol1=true;
    }
    else{
        DisParabol1=false;
    }
}


void MainWindow::on_Disparar1_clicked()   //boton disparar jugador 1
{
    timer->start(dt_);
    float angulo1=ui->angulo1->value();//se ingresa el valor del angulo
    turno=true;
    if(jugador1->getDisparos()>0 and nave1!=NULL){//contador de disparos
        if(DisParabol1==true){
         bala1=nave1->getNave()->disparar(400,1.5,-1.2,angulo1,1);//dispara es tipo baladib dispara la bala con los parametros dados
        }else{
            bala1=nave1->getNave()->disparar(400,1.5,-1.2,angulo1,3);//el ultimo parametro, es tipo 1 parabolico, tipo 2 mrua
        }

        jugador1->borDisp();//quita la bala del contador

        scene1->removeItem(disparos1[jugador1->getDisparos()]);// elimina la bala de la escena
        bala1->setEsacala(0.2);//pone la imagen de la bala a escala
        scene->addItem(bala1);//añade la bala a la escena
        }

}
                    //botones de flechas para jugador 1

void MainWindow::on_fleup1_clicked()
{
    if(nave1!=NULL and (nave1->getNave()->getY()-10-(nave1->getNave()->getHigh()/2))>-high/2){
        nave1->setY(nave1->getNave()->getY()-10);
    }
}

void MainWindow::on_fleder1_clicked()
{
    if(nave1!=NULL and (nave1->getNave()->getX()+nave1->getNave()->getWidth()+10)< 0){
        nave1->setX(nave1->getNave()->getX()+10);
    }
}

void MainWindow::on_fleizq1_clicked()
{
    if(nave1!=NULL and (nave1->getNave()->getX()-10+nave1->getNave()->getWidth())>-width/2){
        nave1->setX(nave1->getNave()->getX()-10);
    }
}

void MainWindow::on_flebaj1_clicked()
{
    if(nave1!=NULL and (nave1->getNave()->getY()+(nave1->getNave()->getHigh()/2)+10)<high/2){
        nave1->setY(nave1->getNave()->getY()+10);
    }
}

void MainWindow::Actualizacion() // actualizar el recorrido y choque de la bala
{
    if(turno==true){
        bala1->getBala()->movimiento(dt_);
        float x=bala1->getBala()->getX();
        float y=bala1->getBala()->getY();
        float xcorrect=0;
        float ycorrect=0;
        if(nave1->getNave()->getY()<0){
            bala1->actualizar(x+nave1->getNave()->getX()+nave1->getNave()->getWidth()/2,-y+nave1->getNave()->getY());
        }
        else{
            bala1->actualizar(x+nave1->getNave()->getX()+nave1->getNave()->getWidth()/2,-y+nave1->getNave()->getY());
        }
        xcorrect=bala1->getX();
        ycorrect=bala1->getY();
        for(int i=0;i<jugador2->getNave().size();i++){
            Navedib *nave=jugador2->getNave()[i];
            if(nave1->getNave()->getY()<0){
                if(xcorrect>0 and xcorrect>=nave->getNave()->getX() and (nave->getNave()->getY()-ycorrect)<5 //menor a las balas
                        and xcorrect<(nave->getNave()->getWidth()+nave->getNave()->getX())
                        and ycorrect<(nave->getNave()->getHigh())+nave->getNave()->getY()and ycorrect>=(nave->getNave()->getY())){
                    jugador1->setPuntos(nave->getNave()->getPuntos());
                    ui->puntaje1->setText(QString::number(jugador1->getPuntos()));
                    if(jugador1->getDisparos()<1 and jugador2->getDisparos()<1){
                        nivel++;
                        setnivel(nivel,juegoActual);
                    }
                    timer->stop();
                    break;
                }
            }else{
                if(xcorrect>0 and xcorrect>nave->getNave()->getX() and xcorrect<(nave->getNave()->getWidth()/4+nave->getNave()->getX())
                        and ycorrect>=(nave->getNave()->getY()) and ycorrect<(nave->getNave()->getY()+nave->getNave()->getHigh())){
                    jugador1->setPuntos(nave->getNave()->getPuntos());
                    ui->puntaje1->setText(QString::number(jugador1->getPuntos()));
                    if(jugador1->getDisparos()<1 and jugador2->getDisparos()<1){
                        nivel++;
                        setnivel(nivel,juegoActual);
                    }
                    timer->stop();
                    break;
                }
            }
            if(DisParabol1==false){
                if(xcorrect>0 and xcorrect>nave->getNave()->getX() and xcorrect<(nave->getNave()->getWidth()/4+nave->getNave()->getX())
                        and ycorrect>=(nave->getNave()->getY()) and ycorrect<(nave->getNave()->getY()+nave->getNave()->getHigh())){
                    jugador1->setPuntos(nave->getNave()->getPuntos());
                    ui->puntaje1->setText(QString::number(jugador1->getPuntos()));
                    if(jugador1->getDisparos()<1 and jugador2->getDisparos()<1){
                        nivel++;
                        setnivel(nivel ,juegoActual);
                    }
                    timer->stop();
                    break;
                }
            }
            if(bala1->getX()>width/2 or bala1->getY()>high/2){
                scene->removeItem(bala1);
                if(jugador1->getDisparos()<1 and jugador2->getDisparos()<1){
                    nivel++;
                    setnivel(nivel ,juegoActual);
                }
                timer->stop();
                break;
            }
        }
    }
    else{
        float x=0;
        if(DisParabol2==true){
            bala2->getBala()->movimiento(dt_);
            x=bala2->getBala()->getX();
        }
        else{
            bala2->getBala()->movimiento(-dt_);
            x=-bala2->getBala()->getX();
        }
        float y=bala2->getBala()->getY();
        float xcorrect=0;
        float ycorrect=0;
            if(nave2->getNave()->getY()<0){
                bala2->actualizar(x+nave2->getNave()->getX()+nave2->getNave()->getWidth()/2,-y+nave2->getNave()->getY());
            }
            else{
                bala2->actualizar(x+nave2->getNave()->getX()+nave2->getNave()->getWidth()/2,-y+nave2->getNave()->getY());
             }
        xcorrect=bala2->getX();
        ycorrect=bala2->getY();
        std::cout <<"xcorrect"<<xcorrect<<std::endl;
        for(int i=0; i<jugador1->getNave().size();i++){
            Navedib *nave=jugador1->getNave()[i];
            std::cout<<"xnave: "<<nave->getNave()->getX()<<std::endl;
            if(nave2->getNave()->getY()<0){
               if(xcorrect<0 and xcorrect<nave->getNave()->getX() and (nave->getNave()->getY()-ycorrect)<5
                       and xcorrect<(nave->getNave()->getWidth()+nave->getNave()->getX())
                       and ycorrect<(nave->getNave()->getHigh())-nave->getNave()->getY()){
                   jugador2->setPuntos(nave->getNave()->getPuntos());
                   ui->puntaje2->setText(QString::number(jugador2->getPuntos()));
                   if(jugador1->getDisparos()<1 and jugador2->getDisparos()<1){
                       nivel++;
                       setnivel(nivel,juegoActual);
                   }
                   timer->stop();
                   break;
               }
            }
            else{
                if(xcorrect<0 and xcorrect<nave->getNave()->getX() and (-nave->getNave()->getY()+ycorrect)<5
                        and xcorrect<(nave->getNave()->getWidth()+nave->getNave()->getX())
                        and ycorrect>(nave->getNave()->getY())){
                    jugador2->setPuntos(nave->getNave()->getPuntos());
                    ui->puntaje2->setText(QString::number(jugador2->getPuntos()));
                    if(jugador1->getDisparos()<1 and jugador2->getDisparos()<1){
                        nivel++;
                        setnivel(nivel,juegoActual);
                    }
                    timer->stop();
                    break;
                }
            }
            if(DisParabol2==false){
                if(xcorrect<0 and xcorrect>nave->getNave()->getX() and xcorrect<(nave->getNave()->getWidth()/4+nave->getNave()->getX())
                        and ycorrect>=(nave->getNave()->getY()) and ycorrect<(nave->getNave()->getY()+nave->getNave()->getHigh())){
                    jugador2->setPuntos(nave->getNave()->getPuntos());
                    ui->puntaje2->setText(QString::number(jugador2->getPuntos()));
                    if(jugador1->getDisparos()<1 and jugador2->getDisparos()<1){
                        nivel++;
                        setnivel(nivel,juegoActual);
                    }
                    timer->stop();
                    break;
                }
            }
            if(bala2->getX()<-width/2 or bala2->getY()>high/2){
                 scene->removeItem(bala2);
                 if(jugador1->getDisparos()<1 and jugador2->getDisparos()<1){
                     nivel++;
                     setnivel(nivel,juegoActual);
                 }
                 timer->stop();
                 break;
            }
        }
    }
}

void MainWindow::mover()  // mover las piedras
{
    for (int i = 0; i <esfera.length(); i++) {
        esfera.at(i)->calcular_posiciones();

        if (esfera[i]->collidesWithItem(l1) || esfera[i] -> collidesWithItem(l3) ||esfera[i]->getY() < -175 ||esfera[i]->getY()>201){
            /* si la vy es <1 y >-175 se deben poner los valores en 0
                porque estan fuera del limite*/

            if (abs(esfera[i]->getVy()) < 1 && esfera[i]->getY() > -175){
                esfera[i]->setVy(0);
                esfera[i]->setAy(0);
            }
            esfera[i]->setY(abs(esfera[i]->getY()));
            esfera[i] -> colision(false,true);
        }

        else if (esfera[i]->collidesWithItem(l2) || esfera[i] -> collidesWithItem(l4) || esfera[i]->getX() < 0 || esfera[i]->getX()> 604){

            esfera[i]->setX(abs(esfera[i]->getX()));
            esfera[i] -> colision(true,false);
        }
    }

}


void MainWindow::on_lista2_currentIndexChanged(int index) // lista jugador 2
{
    if(index>0){
    nave2=jugador2->getNave()[index-1];
    }
}

                    //flechas jugador 2
void MainWindow::on_fleup2_clicked()
{
    if(nave2!=NULL and (nave2->getNave()->getY()-10-(nave2->getNave()->getHigh()/2))>-high/2){
        nave2->setY(nave2->getNave()->getY()-10);
    }
}


void MainWindow::on_fleder2_clicked()
{
    if(nave2!=NULL and (nave2->getNave()->getX()+10-nave2->getNave()->getWidth())<width/2){
        nave2->setX(nave2->getNave()->getX()+10);
    }
}

void MainWindow::on_flebaj2_clicked()
{
    if(nave2!=NULL and (nave2->getNave()->getY()+(nave2->getNave()->getHigh()/2)+10)<high/2){
        nave2->setY(nave2->getNave()->getY()+10);
    }
}

void MainWindow::on_fleizq2_clicked()
{
    if( nave2!=NULL and (nave2->getNave()->getX()-nave2->getNave()->getWidth()-10)> 0){
        nave2->setX(nave2->getNave()->getX()-10);
    }

}


void MainWindow::on_Iniciar_clicked()  //boton iniciar
{

    cuerpos.append(new cuerpodib(-100,0,0,0,70000,300));
    cuerpodib * cuerpo=new cuerpodib(-3600,0,2,2,70,70);
    cuerpo->setColor(Qt::green);
    cuerpodib * cuerpo1=new cuerpodib(-3000,0,-2,-2,70,70);
    cuerpo1->setColor(Qt::red);
    cuerpos.append(cuerpo);
    cuerpos.append(cuerpo1);
    //    cuerpos.append(new cuerpodib(-100,0,0,0,70000,300));
    //    //cuerpos.push_back(new cuerpodib(0,0,0,0,70,300));
    //    scene-> addItem(cuerpos.back());
    //    cuerpos.append(new cuerpodib(-3600,0,2,2,70,80));
    //    scene-> addItem(cuerpos.back());


    //    cuerpos.append(new cuerpodib(-3000,0,0,-2,70,70));
    //    scene-> addItem(cuerpos.back());
    setplanetas();


    if(iniciar==false){
        iniciar=true;
        ui->fleup1->setEnabled(false);
        ui->fleder1->setEnabled(false);
        ui->fleizq1->setEnabled(false);
        ui->flebaj1->setEnabled(false);
        ui->fleup2->setEnabled(false);
        ui->fleder2->setEnabled(false);
        ui->fleizq2->setEnabled(false);
        ui->flebaj2->setEnabled(false);
        ui->Disparar1->setEnabled(true);
        ui->Disparar2->setEnabled(true);

    }
    else{
        iniciar=false;
        ui->fleup1->setEnabled(true);
        ui->fleder1->setEnabled(true);
        ui->fleizq1->setEnabled(true);
        ui->flebaj1->setEnabled(true);
        ui->fleup2->setEnabled(true);
        ui->fleder2->setEnabled(true);
        ui->fleizq2->setEnabled(true);
        ui->flebaj2->setEnabled(true);
        ui->Disparar1->setEnabled(false);
        ui->Disparar2->setEnabled(false);
    }



}


void MainWindow::on_tipo2_currentIndexChanged(int index) //lista tipo de disparo jugador2
{
    if(index==0){
        DisParabol2=true;
    }else{
        DisParabol2=false;
    }
}


void MainWindow::on_Disparar2_clicked() //disparar jugador 2
{
    timer->start(dt_);
    float angulo2=ui->angulo2->value();//ingresa el angulo en el boton de la interfaz
    turno=false;
    if(jugador2->getDisparos()>0 and nave1!=NULL){//contador de disparos
        if(DisParabol2==true){
         bala2=nave2->getNave()->disparar(400,1.5,-1.2,angulo2,1);//dispara es tipo disparodib, dispara la bala con los parametros dados

        }else{
            bala2=nave2->getNave()->disparar(400,1.5,-1.2,angulo2,3);//el ultimo parametro, es tipo 1 parabolico, tipo 2 mrua
        }

        jugador2->borDisp();//quita disparo

        scene2->removeItem(disparos2[jugador2->getDisparos()]);
        bala2->setEsacala(0.2);
        scene->addItem(bala2);
        }

}

void MainWindow::on_Piedras_clicked()  //agregar las piedras
{

    esfera.push_back(new piedras());  //agrega un nuevo objeto y se agrega al final de la lista
    scene-> addItem(esfera.last());

    esfera.push_back(new piedras());  //agrega un nuevo objeto y se agrega al final
                                                //de la lista
    scene-> addItem(esfera.last());

    esfera.push_back(new piedras());  //agrega un nuevo objeto y se agrega al final
                                                //de la lista

}

void MainWindow::on_menu_clicked()
{
   // ui->graphicsView->setScene(Scene3)
}


void MainWindow::on_guardarP_clicked() //guardar partida
{
    QString nombre=ui->nompartida->text();
    juegoActual->setNombre(nombre);
    ui->cargaP->addItem(juegoActual->getNombre());//(guarda) carga la partida
    ui->eliminaP->addItem(juegoActual->getNombre());//elimina la partida actual
    jugadas.append(juegoActual);//agrega la partida al vector

}


void MainWindow::on_nompartida_textEdited(const QString &arg1)
{

}


void MainWindow::on_cargarP_clicked() //cargar partida
{
    scene=new QGraphicsScene;
    scene1=new QGraphicsScene;
    scene2=new QGraphicsScene;
    ui->graphicsView_2->setScene(scene);
    ui->balas1->setScene(scene1);
    ui->balas2->setScene(scene2);
    scene->setSceneRect(-width/2,- high/2,width, high);//define el tamaño de la escena
    scene1->setSceneRect(-90,-20,180,40);
    scene2->setSceneRect(-90,-20,180,40);

    ui->lista1->clear();
    ui->lista1->addItem("Seleccione Nave");
    ui->lista2->clear();
    ui->lista2->addItem("Seleccione Nave");
    ui->Disparar1->setEnabled(true);
    ui->Disparar2->setEnabled(true);
    juegoActual=jugadas[this->carga];//carga la partida
    this->jugador1=juegoActual->getJugador1();//añade los jugadores a la partida
    this->jugador2=juegoActual->getJugador2();
    setjugador1(this->jugador1);
    setjugador2(this->jugador2);

    ui->puntaje1->setText(QString::number(jugador1->getPuntos()));//añade los puntajes guardados a la partida
    ui->puntaje2->setText(QString::number(jugador2->getPuntos()));
}

void MainWindow::on_cargaP_currentIndexChanged(int index)
{
    this->carga=index-1;
}

void MainWindow::on_eliminarP_clicked() //eliminar partida
{
    jugadas.removeAt(this->elimina);//remueve la partida del vector
       ui->eliminaP->clear();//"destruye" el objeto del vector partidas
       for (int i=0; i<jugadas.size();i++ ) {
        ui->eliminaP->addItem(jugadas[i]->getNombre());// busca la partida y  la elimina
       }
}
void MainWindow::on_eliminaP_currentIndexChanged(int index)
{
    this->elimina=index-1;
}

void MainWindow::on_reiniciarP_clicked() //reiniciar partida
{
    this->jugador1=new Jugador("Jugador 1",5,5,1);
    this->jugador2=new Jugador("Jugador 2",5,5,2);

    juegoActual=new Jugada("default", this->jugador1,this->jugador2,nivel);//crea una nueva partida

    setnivel(nivel,juegoActual);

}

void MainWindow::on_nuevaP_clicked()//nueva partida
{
    this->jugador1=new Jugador("Jugador 1",5,5,1);
    this->jugador2=new Jugador("Jugador 2",5,5,2);
    juegoActual=new Jugada("default", this->jugador1,this->jugador2,1);

    setnivel(1,juegoActual);
}

void MainWindow::setplanetas() //agrega los planetas a la escena
{

    for (int i=0; i< cuerpos.size() ; i++) {
        cuerpos[i]->setEscala(0.05);
        scene->addItem(cuerpos[i]);}
}

QColor* MainWindow::colorRandom() //darle un color a los circulos
{
    int r=qrand() % 255;
    int g=qrand() % 255;
    int b=qrand() % 255;

    return new QColor(r,g,b,255);
}
void MainWindow::actualizar()// actualiza los movimientos en la escena
{
    for (int i = 1;i< cuerpos.size() ;i++ ) {
        cuerpos[i]->getEsf()->getr(cuerpos[0]->getEsf()->getPX(),cuerpos[0]->getEsf()->getPY());
        float masa=cuerpos[0]->getEsf()->getmasa();
        cuerpos[i]->actualizar(masa,cuerpos[0]->getEsf()->getPX(),cuerpos[0]->getEsf()->getPY(),dtt_);

    }
}


