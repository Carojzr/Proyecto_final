#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>
#include <QTimer>
#include <QVector>
#include "jugador.h"
#include "disparo.h"
#include "jugada.h"
#include <QMessageBox>
#include <QList>
#include <QDebug>
#include <piedras.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setjugador1(Jugador* jugador);
    void setjugador2(Jugador* jugador);
    void setnivel(int nivel, Jugada* jugada);


private slots:
    void on_lista1_currentIndexChanged(int index);

    void on_tipo1_currentIndexChanged(int index);

    void on_Disparar1_clicked();

    void on_fleup1_clicked();

    void on_fleder1_clicked();

    void on_fleizq1_clicked();

    void on_flebaj1_clicked();


    void on_lista2_currentIndexChanged(int index);

    void on_fleup2_clicked();

    void on_fleder2_clicked();

    void on_flebaj2_clicked();

    void on_fleizq2_clicked();



    void on_Iniciar_clicked();

    void on_tipo2_currentIndexChanged(int index);

    void on_Disparar2_clicked();

    void on_Piedras_clicked();

    void on_menu_clicked();

    void on_guardarP_clicked();

    void on_nompartida_textEdited(const QString &arg1);

    void on_cargarP_clicked();

    void on_eliminarP_clicked();

    void on_reiniciarP_clicked();

    void on_nuevaP_clicked();



    void on_cargaP_currentIndexChanged(int index);

    void on_eliminaP_currentIndexChanged(int index);

public slots:
    void Actualizacion();
    void mover();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene3;
    QMainWindow *w2;
    QGraphicsView *v2;
    QGraphicsScene *scene;
    QGraphicsScene *scene1;
    QGraphicsScene *scene2;
    Jugador *jugador1 ;
    Jugador *jugador2 ;
    Navedib *nave1;
    Navedib *nave2;
    bool iniciar=false;
    bool DisParabol1=true;
    bool DisParabol2=true;
    QTimer *timer;
    QTimer *timer1;
    float dt_=0.1;
    bool turno=true;//turno jugador1
    Baladib *bala1;
    Baladib *bala2;
    QMessageBox mensaje;
    QVector <Disparo*> disparos1;
    QVector <Disparo*> disparos2;
    int width=700;
    int high=400;
    int cambiar_nivel=0;
    int nivel=1;
    bool menu=false;
    QVector <Jugada*> jugadas;
    Jugada *juegoActual;
    QList < piedras *> esfera;
    QGraphicsLineItem *l1, *l2, *l3, *l4;
    int carga=0;
    int elimina=0;

};
#endif // MAINWINDOW_H
