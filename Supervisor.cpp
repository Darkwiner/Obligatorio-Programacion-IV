#include "Supervisor.h"

Supervisor :: Supervisor () : Persona (), barrio()
{
    cantManzanas = 0;
}

Supervisor :: Supervisor (String b, int manzanas) : Persona (), barrio(b)
{
    cantManzanas = manzanas;
}

Supervisor :: Supervisor (const Supervisor &otro) : Persona (), barrio(otro.barrio)
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
