#include "Vendedor.h"

Vendedor :: Vendedor () : Persona ()
{
    sueldoBase = 0;
    cantVentas = 0;
}

Vendedor :: Vendedor (int ced, String nom, int s, int ventas) : Persona (ced,nom)
{
    sueldoBase = s;
    cantVentas = ventas;
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

bool Vendedor :: esZafral(Fecha f, Vendedor * v)
{
    bool es = false;
    if(v->getTipo() == "Zafral")
    {
        if(v-> > f)
            es = true;

    }
}

