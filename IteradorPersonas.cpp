#include "IteradorPersonas.h"

IteradorPersonas :: IteradorPersonas ()
{
    prim = NULL;
    ult = NULL;
    actual = NULL;
}

bool IteradorPersonas :: hayMasPersonas()
{
    return (bool) (actual != NULL);
}

Persona * IteradorPersonas :: proximaPersona ()
{
    Persona * resu = actual -> info;
    actual = actual -> sig;
    return resu;
}

void IteradorPersonas :: insertarPersona (Persona * p)
{
    nodoP * nuevo = new nodoP;
    nuevo -> info = p;
    nuevo -> sig = NULL;
    if (prim == NULL)
    {
        prim = nuevo;
        ult = nuevo;
        actual = nuevo;
    }
    else
    {
        ult -> sig = nuevo;
        ult = ult -> sig;
    }
}

IteradorPersonas :: ~IteradorPersonas()
{
    nodoP * aux = prim;
    while (aux != NULL)
    {
        prim = prim -> sig;
        delete aux;
        aux = prim;
    }
}

void IteradorPersonas :: cargarIterador (nodoP * persona, IteradorPersonas &iter)
{
    insertarPersona (persona->info);
}
