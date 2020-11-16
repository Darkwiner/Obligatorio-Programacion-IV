#include "Vendedor.h"

Vendedor :: Vendedor ()
{
    sueldoBase = 0;
    cantVentas = 0;
}

Vendedor :: Vendedor (int s, int ventas)
{
    sueldoBase = s;
    cantVentas = ventas;
}

Vendedor :: Vendedor (const Vendedor &otro)
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
