#include "Vendedor.h"

Vendedor :: Vendedor () : Persona ()
{
    sueldoBase = 0;
    cantVentas = 0;
    sup = NULL;
}

Vendedor :: Vendedor (int ced, String nom, float s, int ventas, Supervisor * super) : Persona (ced,nom)
{
    sueldoBase = s;
    cantVentas = ventas;
    sup = super;
}

Vendedor :: Vendedor (const Vendedor &otro) //Preguntar
{
    sueldoBase = otro.sueldoBase;
    cantVentas = otro.cantVentas;
}

float Vendedor :: sueldoTotal ()    // armar luego de tener la polimorfica armada...
{
    return sueldoBase; ///PREGUNTAR QUE ES LO QUE SE RETORNA
}

int Vendedor:: getSueldoBase ()
{
    return sueldoBase;
}

int Vendedor :: getCantVentas ()
{
    return cantVentas;
}

void Vendedor :: setSueldoBase (float sueldo)
{
    sueldoBase = sueldo;
}

void Vendedor :: setCantVentas (int ventas)
{
    cantVentas = ventas;
}

Vendedor :: ~Vendedor()
{

}

long int Vendedor :: getCedulaVen ()
{
    long int ced = getCedula();
    return ced;
}

void Vendedor :: setSupervisor (Supervisor * super)
{
    sup = super;
}

/*
bool Vendedor :: esZafral(Fecha f, Vendedor * v)
{
    bool es = false;
    if(v->getTipo() == "Zafral")
    {
        if(v-> > f)
            es = true;

    }
}*/

