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
};
#endif // VENDEDOR_H_INCLUDED
