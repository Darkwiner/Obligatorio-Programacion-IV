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

void Vendedores :: cargarIterador (Nodo * a, IteradorPersonas &iter)
{
    if (a != NULL)
    {
        cargarIterador (a->hizq, iter);
        iter.insertarPersona (a->info);
        cargarIterador (a->hder, iter);
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

void Vendedores :: insertVendedor (Vendedor * due)
{
    insertEnArbol (ABB, due);
}

Vendedor * Vendedores :: find (long int ced)
{
    return obtenerEnArbol (ABB, ced);
}

void Vendedores :: listarVendedores (IteradorPersonas &iter)
{
    cargarIterador (ABB, iter);
}

int Vendedores :: buscarZafrales (Nodo * a, Fecha f)
{
    int cont = 0;
    if (a != NULL)
    {
        buscarZafrales (a->hizq, f);
        a->info->esZafral(f, a->info);
        buscarZafrales()r (a->hder, f);
    }
return cont;
}


