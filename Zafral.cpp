#include "Zafral.h"

Zafral :: Zafral () : Vendedor(),fechaVto()
{
    comision = 0;
}

Zafral :: Zafral (int c, Fecha f) : Vendedor(), fechaVto (f)
{
    comision = c;
}

Zafral :: Zafral (const Zafral &otro) : Vendedor(), fechaVto (otro.fechaVto)
{
    comision = otro.comision;
}

int Zafral :: getComision()
{
    return comision;
}

Fecha Zafral :: getFecha()
{
    return fechaVto;
}

void Zafral :: setComision(int c)
{
    comision = c;
}

void Zafral :: setFecha(Fecha f)
{
    fechaVto = f;
}

/*
• Vendedor zafral: El sueldo del vendedor zafral siempre es proporcional a la cantidad de
ventas realizadas en la semana. Se calcula multiplicando el valor de su
comisión por la cantidad de ventas realizadas y sumando el resultado al salario base del vendedor*/

float Zafral :: sueldoTotal ()
{
    float sueldo = getSueldoBase();
    return (sueldo + (comision * getCantVentas()));
}

String Zafral :: getTipo()
{
    String tipo("Zafral");
    return (String) tipo;
}










