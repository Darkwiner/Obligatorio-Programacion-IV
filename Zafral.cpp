#include "Zafral.h"

Zafral :: Zafral () : Fecha ()
{
    comision = 0;
}
Zafral :: Zafral (int c, Fecha f) : Fecha (f)
{
    comision = c;
}
Zafral :: Zafral (const Zafral &otro) : Fecha (otro.fechaVto)
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
Zafral :: ~Zafral()
{

}

