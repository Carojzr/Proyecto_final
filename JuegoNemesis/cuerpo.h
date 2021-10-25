#ifndef CUERPO_H
#define CUERPO_H


class cuerpo
{
public:
    float PX;
    float PY;
    float xo;
    float yo;
    float masa;
    float R;
    float VX=0; //vel en x
    float VY=0; //vel en y
    float AX; //acel en x
    float AY; //acel en y
    float Gr=1; // constante gravitacion universal
    float V; //magnitud vector de velocidad
    float dtt=10; //delta tiempo
    float t=0;
    float r;
public:
    cuerpo(float PX,float PY, float vx, float vy, float masa, float radio);
    ~cuerpo(); //Cuando el objeto deja de participar en la escena se pone ese destructor para liberar recursos
    void getr(float x, float y);
    float getmasa()const;
    float getPX() const;
    float getPY() const;
    float getR() const;
    float getxo() const;
    float getyo() const;
    void actualizar(float mass, float xcentral, float ycentral,float t);
    float getVX() const;
    float getVY() const;
    float getAX();
    float getAY();
};

#endif // CUERPO_H
