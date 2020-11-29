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
    IteradorPersonas iter;
    cargarIteradorVendedor (ABB, iter);
    return iter;
}

void Vendedores :: cargarIteradorVendedor (Nodo * a, IteradorPersonas &iter)
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

int Vendedores :: buscarZafralesVendedores (Fecha f)
{
    int total = 0;
    buscarZafrales(ABB, f, total);
    return total;
}

void Vendedores :: buscarZafrales (Nodo * a, Fecha f, int &total)
{
    if (a != NULL)
    {
        buscarZafrales (a->hizq, f, total);
        if(a->info->getTipo()=="Zafral")
             if(f<((Zafral *)a->info)->getFecha())
                total = total + 1;
        buscarZafrales (a->hder, f, total);
    }
}

float Vendedores :: calcularSueldo ()
{
    float total = 0;
    calcularSueldoVendedores (ABB, total);
    return total;
}

void Vendedores :: calcularSueldoVendedores (Nodo * a, float & total)
{
    if (a != NULL)
    {
        calcularSueldoVendedores (a->hizq, total);
        total = total + a->info->sueldoTotal();
        calcularSueldoVendedores (a->hder, total);
    }
}

bool Vendedores :: esVacio ()
{
    if (ABB == NULL)
        return true;
    else
        return false;
}
