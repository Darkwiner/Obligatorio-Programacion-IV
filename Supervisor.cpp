#include "Supervisor.h"

Supervisor :: Supervisor () : barrio()
{
    cantManzanas = 0;
}

Supervisor :: Supervisor (String b, int manzanas) : barrio(b)
{
    cantManzanas = manzanas;
}

Supervisor :: Supervisor (const Supervisor &otro) : barrio(otro.barrio)
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
