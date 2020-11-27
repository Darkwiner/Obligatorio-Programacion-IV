#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>

using namespace std;

class Fecha
{
private:
    int dd, mm, aa;
    void incrementar (); // M�todo auxiliar, incrementa 1 d�a la fecha

public:
    Fecha (); //Constructor por defecto
    Fecha (int, int, int); //Constructor com�n
    Fecha (const Fecha &); //Constructor de copia
    bool operator< (Fecha); //Compara por menor 2 fechas
    bool operator== (Fecha); //Compara por igualdad 2 fechas
    Fecha operator+ (int); //Devuelve la fecha incrementada en n dias
    Fecha operator++ (); //Operador prefijo de incremento
    Fecha operator++ (int); //Operador postfijo de incremento
    int operator- (Fecha); //Devuelve la diferencia en d�as entre 2 fechas
    bool esValida (); //Validacion de la fecha
    int getDia ();
    int getMes ();
    int getAnio ();
    void mostrar ();
};

#endif // FECHA_H_INCLUDED
