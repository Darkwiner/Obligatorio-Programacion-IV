#include "Fijo.h"

Fijo :: Fijo () : Vendedor()
{
    plus = 0;
}

Fijo :: Fijo (int p, long int ced, String nombre, int sueldo, int cant, Supervisor * sup) : Vendedor(ced, nombre, sueldo, cant, sup)
{
    plus = p;
}

Fijo :: Fijo (const Fijo &otro) : Vendedor()
{
    plus = otro.plus;
}

float Fijo :: sueldoTotal ()
{
    float sueldo = Vendedor::sueldoTotal();
    if (getCantVentas() > 10 && getCantVentas() < 20)
        sueldo = sueldo + getPlus();
    else if (getCantVentas() > 20)
        sueldo = sueldo + (getPlus()*2);
    return sueldo;
}

int Fijo :: getPlus()
{
    return plus;
}

void Fijo :: setPlus (int p)
{
    plus = p;
}

String Fijo :: getTipo()
{
    String tipo("Fijo");
    return (String) tipo;
}

