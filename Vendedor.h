#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
#include "Persona.h"

class Vendedor
{
private :
    int sueldoBase;
    int cantVentas;
public :
    Vendedor (); //Constructor por defecto
    Vendedor (int, int); //Constructor comun
    Vendedor (const Vendedor &);//Constructor de copia
    virtual float sueldoTotal ();
    int getSueldoBase ();
    int getCantVentas ();
    void setSueldoBase (float);
    void setCantVentas (int);


};
#endif // VENDEDOR_H_INCLUDED
