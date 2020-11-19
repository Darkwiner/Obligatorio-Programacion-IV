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

float Zafral :: sueldoTotal ()
{
    return 0;
}
