#include "Supervisor.h"

Supervisor :: Supervisor () : Persona (), barrio()
{
    cantManzanas = 0;
}

Supervisor :: Supervisor (long int ced, String nom, String b, int manzanas) : Persona (ced,nom), barrio(b)
{
    cantManzanas = manzanas;
}

Supervisor :: Supervisor (const Supervisor &otro) : Persona (otro), barrio(otro.barrio)
{
    cantManzanas = otro.cantManzanas;
}

String Supervisor :: getBarrio ()
{
    return barrio;
}

int Supervisor :: getManzanas ()
{
    return cantManzanas;
}

void Supervisor :: setBarrio (String b)
{
    barrio = b;
}

void Supervisor :: setManzanas (int manzanas)
{
    cantManzanas = manzanas;
}

String Supervisor :: getTipo()
{
    String tipo("Supervisor");
    return (String) tipo;
}

long int Supervisor :: getCedulaSup()
{
    long int ced = getCedula();
    return ced;
}
