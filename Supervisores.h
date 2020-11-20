#ifndef SUPERVISORES_H_INCLUDED
#define SUPERVISORES_H_INCLUDED
#include "Supervisor.h"

const int B = 60;

class Supervisores
{
private:
    struct NodoH
    {
        Supervisor * info;
        NodoH * sig;
    };
    NodoH * hash[B];

    int h (int);  //Funcion de dispersion
    void crearLista (NodoH * &);//Crea una lista vacia
    void destruirLista (NodoH * &);//Destruye todo el contenido de la lista
    bool perteneceLista (NodoH *, long int);//Indica si existe el supervisor con la cedula dada
    void insFrontEnLista (NodoH * &, Supervisor *);//Inserta la mascota al principio de la lista
    Supervisor * obtenerEnLista (NodoH *, long int);//Obtiene al supervisor con el numero de cedula dado
    //int cuantosEnLista (NodoH *, float);// cuenta cuantas mascotas poseen el peso ingresado
public:
    Supervisores ();//Constructor por defecto
    ~ Supervisores ();//Destructor
    bool member (long int);//Indica si el supervisor con la cedula dada esta en la coleccion
    //Precondicion: el supervisor no existe en la coleccion
    void insert (Supervisor *);//Inserta el supervisor en la coleccion
    //Precondicion: el supervisor pertenece a la coleccion
    Supervisor * find (long int);//Retorna al supervisor con la cedula dada
};

#endif // SUPERVISORES_H_INCLUDED
