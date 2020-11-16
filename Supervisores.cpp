#include "Supervisores.h"

int Supervisores :: h (int num)
{
    return (num % B);
}
void Supervisores :: crearLista (Nodo * &L)
{
    L = NULL;
}
void Supervisores :: destruirLista (Nodo * &L)
{
    Nodo * aux = L;
    while (aux != NULL)
    {
        L = aux->sig;
        delete (aux);
        aux = L;
    }
    L = aux;
}

bool Supervisores :: perteneceLista (Nodo * L, int num)
{
    bool existe = false;
    while (!existe && L != NULL)
        if (L->info->getNumero() == num)
            existe = true;
        else
            L = L->sig;
    return existe;
}
void Supervisores :: insFrontEnLista (Nodo * &L, Mascota * ma)
{
    Nodo * aux = new Nodo;
    aux->info = ma;
    aux->sig = L;
    L = aux;
}
Supervisor * Supervisores :: obtenerEnLista (Nodo * L, int num)
{
    while (L->info->getNumero() != num)
        L = L->sig;
    return (L->info);
}
int Supervisores :: cuantosEnLista (Nodo * L, float pe)
{
    int cont = 0;
    while (L != NULL)
    {
        if (L->info->getPeso() == pre)
            cont++;
        L = L->sig;
    }
    return cont;
}
/* hasta aquí se implementaron los métodos auxiliares privados. A
partir de aquí se implementan los métodos públicos de la clase */
Supervisores :: Supervisores ()
{
    for (int i=0; i < B; i++)
        crearLista(hash[i]);
}
Supervisores :: ~Supervisores ()
{
    for (int i=0; i < B; i++)
        destruirLista(hash[i]);
}

bool Supervisores :: member (int num)
{
    int cubeta = h(num);
    return perteneceLista (hash[cubeta], num);
}
void Supervisores :: insert (Mascota * ma)
{
    int num = ma->getNumero();
    int cubeta = h(num);
    insFrontEnLista (hash[cubeta], ma);
}
Supervisores * Supervisores :: find (int num)
{
    int cubeta = h(num);
    return obtenerEnLista (hash[cubeta], num);
}

