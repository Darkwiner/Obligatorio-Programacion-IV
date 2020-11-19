#include "IteradorPersonas.h"

IteradorPersonas :: IteradorPersonas ()
{
    prim = NULL;
    ult = NULL;
}
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
}*/// esto no es necesario
bool IteradorPersonas :: hayMasPersonas()
{
    return ();
}
Persona IteradorPersonas :: proximoPersona ()
{
    return (l->sig->info);
}
bool IteradorPersonas :: estaLlenoPersonas () ///PREGUNTAR SI APLICA AL SER LPPF
{
    return (l.ult->sig != NULL);
}
*/
