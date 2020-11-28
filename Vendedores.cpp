#include "Vendedores.h"

void Vendedores :: destruirArbol (Nodo * &a)
{
    if (a != NULL)
    {
        destruirArbol(a->hizq);
        destruirArbol(a->hder);
        delete (a->info);
        delete (a);
        a = NULL;
    }
}

bool Vendedores :: perteneceEnArbol (Nodo * a, long int ced)
{
    bool encontre = false;
    while (!encontre && a != NULL)
        if (ced == a->info->getCedula())
            encontre = true;
        else if (ced < a->info->getCedula())
            a = a->hizq;
        else
            a = a->hder;
    return encontre;
}

void Vendedores :: insertEnArbol (Nodo * &a, Vendedor * vend)
{
    if (a == NULL)
    {
        a = new Nodo;
        a -> info = vend;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else if (vend->getCedula() < a->info->getCedula())
        insertEnArbol(a->hizq,vend);
    else
        insertEnArbol(a->hder,vend);
}

Vendedor * Vendedores :: obtenerEnArbol (Nodo * a, long int ced)
{
    while (ced != a->info->getCedula())
        if (ced < a->info->getCedula())
            a = a->hizq;
        else
            a = a->hder;
    return (a->info);
}

IteradorPersonas Vendedores :: listarVendedores ()
{
    cargarIteradorVendedor (ABB, iter);
}

IteradorPersonas Vendedores :: cargarIteradorVendedor (Nodo * a, IteradorPersonas &iter)
{
    if (a != NULL)
    {
        cargarIteradorVendedor (a->hizq, iter);
        iter.insertarPersona (a->info);
        cargarIteradorVendedor (a->hder, iter);
    }
}

Vendedores :: Vendedores ()
{
    ABB = NULL;
}

Vendedores :: ~Vendedores ()
{
    destruirArbol(ABB);
}

bool Vendedores :: member (long int ced)
{
    return perteneceEnArbol (ABB, ced);
}

void Vendedores :: insertVendedor (Vendedor * v)
{
    insertEnArbol (ABB, v);
}

Vendedor * Vendedores :: find (long int ced)
{
    return obtenerEnArbol (ABB, ced);
}
/*
int Vendedores :: buscarZafralesVendedores (Fecha f)
{
    buscarZafrales(ABB, f);
}

int Vendedores :: buscarZafrales (Nodo * a, Fecha f)
{
    int cont = 0;
    if (a != NULL)
    {
        buscarZafrales (a->hizq, f);
        if(a->info->esZafral(f, a->info))
            cont++;
        buscarZafrales()r (a->hder, f);
    }
return cont;
}*/

float Vendedores :: recorrerArbol (Nodo * a)
{
    float total = 0;
    if (a != NULL)
    {
        recorrerArbol(a->hizq);
        total = total + a->info->sueldoTotal();
        recorrerArbol(a->hder);
    }
    return total;
}

float Vendedores :: calcularSueldo ()
{
    return recorrerArbol (ABB);
}
