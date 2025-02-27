#include "Supervisores.h"

int Supervisores :: h (int num)
{
    return (num % B);
}

void Supervisores :: crearLista (NodoH * &L)
{
    L = NULL;
}

Supervisores :: Supervisores ()
{
    for (int i=0; i < B; i++)
        crearLista(hash[i]);
}

void Supervisores :: destruirLista (NodoH * &L)
{
    NodoH * aux = L;
    while (aux != NULL)
    {
        L = aux->sig;
        delete (aux);
        aux = L;
    }
    L = aux;
}

bool Supervisores :: perteneceLista (NodoH * L, long int num)
{
    bool existe = false;
    while (!existe && L != NULL)
        if (L->info->getCedulaSup() == num)
            existe = true;
        else
            L = L->sig;
    return existe;
}

void Supervisores :: insFrontEnLista (NodoH * &L, Supervisor * su)
{
    NodoH * aux = new NodoH;
    aux->info = su;
    aux->sig = L;
    L = aux;
}

Supervisor * Supervisores :: obtenerEnLista (NodoH * L, long int ced)
{
    while (L->info->getCedula() != ced)
        L = L->sig;
    return (L->info);
}

Supervisores :: ~Supervisores ()
{
    for (int i=0; i < B; i++)
        destruirLista(hash[i]);
}

bool Supervisores :: member (long int ced)
{
    int cubeta = h(ced);
    return perteneceLista (hash[cubeta], ced);
}

void Supervisores :: insertSupervisor (Supervisor * su)
{
    long int ced = su->getCedula();
    int cubeta = h(ced);
    insFrontEnLista (hash[cubeta], su);
}

Supervisor * Supervisores :: find (long int ced)
{
    int cubeta = h(ced);
    return obtenerEnLista (hash[cubeta], ced);
}

IteradorPersonas Supervisores :: listarSupervisores ()
{
    IteradorPersonas iter;
    for (int i=0; i<B; i++)
    {
        cargarIteradorSupervisor(hash[i], iter);
    }
    return iter;
}

void Supervisores :: cargarIteradorSupervisor(NodoH * lista, IteradorPersonas &iter)
{
    while (lista != NULL)
    {
        iter.insertarPersona(lista->info);
        lista=lista->sig;
    }
}

