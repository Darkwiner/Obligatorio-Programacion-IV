#include "IteradorPersonas.h"

IteradorPersonas :: IteradorPersonas ()
{
    prim = NULL;
    ult = NULL;
}

bool IteradorPersonas :: hayMasPersonas()
{
    return (bool)(actual != NULL);
}
Persona * IteradorPersonas :: proximaPersona ()
{
    Persona * resu = actual -> info;
    actual = actual -> sig;
    return resu;
}
bool IteradorPersonas :: estaLlenoPersonas () ///PREGUNTAR SI APLICA AL SER LPPF
{
    return (bool)(ult->sig != NULL);
}

// esto no es necesario
/*void IteradorPersonas :: IteradorPersonas (Persona P)
{
    NodoP * nuevo = new nodoP;
    nuevo->info = P;
    nuevo->sig = NULL;
    if (l.ult == NULL)
    {
        l.ult = nuevo;
        l.prim = nuevo;
    }
    else
    {
        l.ult->sig = nuevo;
        l.ult = nuevo;
    }
}*/

