#include "Zafral.h"

Zafral :: Zafral () : Vendedor(),fechaVto()
{
    comision = 0;
}

Zafral :: Zafral (int c, Fecha f, long int ced, String nombre, int sueldo, int cant, Supervisor * sup) : Vendedor(ced, nombre, sueldo, cant, sup), fechaVto (f)
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

float Zafral :: sueldoTotal ()
{
    float sueldo = Vendedor::sueldoTotal();
    return (sueldo + (comision * getCantVentas()));
}

String Zafral :: getTipo()
{
    String tipo("Zafral");
    return (String) tipo;
}
