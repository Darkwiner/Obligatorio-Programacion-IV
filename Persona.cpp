#include "Persona.h"

Persona :: Persona () : nombre()
{
    cedula = 0;
}

Persona :: Persona (long int ced, String nom) : nombre(nom)
{
    cedula = ced;
}

Persona :: Persona (const Persona &otro) : nombre(otro.nombre)
{
    cedula = otro.cedula;
}

long int Persona :: getCedula ()
{
    return cedula;
}

String Persona :: getNombre ()
{
    return nombre;
}

void Persona :: setCedula (long int ced)
{
    cedula = ced;
}

void Persona :: setNombre (String s)
{
    nombre = s;
}

