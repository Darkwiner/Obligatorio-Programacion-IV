#include "Supervisores.h"

int Supervisores :: h (int num)
{
    return (num % B);
}
void Supervisores :: crearLista (NodoH * &L)
{
    L = NULL;
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

// bool Supervisores :: perteneceLista (NodoH * L, int num)
// {
//     bool existe = false;
//     while (!existe && L != NULL)
//         if (L->info->getNumero() == num)
//             existe = true;
//         else
//             L = L->sig;
//     return existe;
// }

void Supervisores :: insFrontEnLista (NodoH * &L, Supervisor * su)
{
    NodoH * aux = new NodoH;
    aux->info = su;
    aux->sig = L;
    L = aux;
}

// Supervisor * Supervisores :: obtenerEnLista (NodoH * L, int num)
// {
//     while (L->info->getNumero() != num)
//         L = L->sig;
//     return (L->info);
// }

// int Supervisores :: cuantosEnLista (NodoH * L, float pe)
// {
//     int cont = 0;
//     while (L != NULL)
//     {
//         if (L->info->getPeso() == pre)
//             cont++;
//         L = L->sig;
//     }
//     return cont;
// }

/* hasta aqu� se implementaron los m�todos auxiliares privados. A
partir de aqu� se implementan los m�todos p�blicos de la clase */

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

// bool Supervisores :: member (int num)
// {
//     int cubeta = h(num);
//     return perteneceLista (hash[cubeta], num);
// }

// void Supervisores :: insert (Supervisor * su)
// {
//     int num = su->getNumero();
//     int cubeta = h(num);
//     insFrontEnLista (hash[cubeta], su);
// }

// Supervisores * Supervisores :: find (int num)
// {
//     int cubeta = h(num);
//     return obtenerEnLista (hash[cubeta], num);
// }
