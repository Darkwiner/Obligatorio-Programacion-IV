#include "Vendedor.h"

Vendedor :: Vendedor () : Persona ()
{
    sueldoBase = 0;
    cantVentas = 0;
    sup = NULL;
}

Vendedor :: Vendedor (int ced, String nom, float s, int ventas, Supervisor * super) : Persona (ced,nom)
{
    sueldoBase = s;
    cantVentas = ventas;
    sup = super;
}

Vendedor :: Vendedor (const Vendedor &otro)
{
    sueldoBase = otro.sueldoBase;
    cantVentas = otro.cantVentas;
}

float Vendedor :: sueldoTotal ()
{
    return sueldoBase;
}

float Vendedor:: getSueldoBase ()
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
/*
long int Vendedor :: getCedulaVen ()
{
    long int ced = getCedula();
    return ced;
}*/

long int Vendedor :: getCedulaSup ()
{
    return sup->getCedula();
}

void Vendedor :: setSupervisor (Supervisor * super)
{
    sup = super;
}

Supervisor * Vendedor :: getSupervisor ()
{
    return  sup;
}
