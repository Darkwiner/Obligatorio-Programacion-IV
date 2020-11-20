#include "Fijo.h"

Fijo :: Fijo () : Vendedor()
{
    plus = 0;
}

Fijo :: Fijo (int p) : Vendedor()
{
    plus = p;
}

Fijo :: Fijo (const Fijo &otro) : Vendedor()
{
    plus = otro.plus;
}

/*Vendedor fijo: Si realizó menos de 10 ventas en la semana, cobra únicamente su salario
base. Si realizó entre 10 y 20, cobra su salario base mas el valor del plus, y
si realizó más de 20 ventas, cobra su salario base mas el doble del plus.*/

float Fijo :: sueldoTotal ()
{
    float sueldo = getSueldoBase();
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

