#include "Vendedor.h"

Vendedor :: Vendedor () : Persona ()
{
    sueldoBase = 0;
    cantVentas = 0;
}

Vendedor :: Vendedor (long int ced, String nom, int s, int ventas) : Persona (ced,nom)
{
    sueldoBase = s;
    cantVentas = ventas;
}

Vendedor :: Vendedor (const Vendedor &otro) //Preguntar
{
    sueldoBase = otro.sueldoBase;
    cantVentas = otro.cantVentas;
}

float sueldoTotal ()    // armar luego de tener la polimorfica armada...
{
    return 0;
}

int Vendedor:: getSueldoBase ()
{
    return sueldoBase;
}

int Vendedor :: getCantVentas ()
{
    return cantVentas;
}

void Vendedor :: setSueldoBase (float sueldo)
{
    sueldoBase = sueldo;
}

void Vendedor :: setCantVentas (int ventas)
{
    cantVentas = ventas;
}

Vendedor :: ~Vendedor()
{

}
