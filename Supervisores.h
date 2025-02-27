#ifndef SUPERVISORES_H_INCLUDED
#define SUPERVISORES_H_INCLUDED
#include "Supervisor.h"
#include "IteradorPersonas.h"

const int B = 2;

class Supervisores
{
private:
    struct NodoH
    {
        Supervisor * info;
        NodoH * sig;
    };
    NodoH * hash[B];

    int h (int); //Funcion de dispersion
    void crearLista (NodoH * &); //Crea una lista vacia
    void destruirLista (NodoH * &); //Destruye todo el contenido de la lista
    bool perteneceLista (NodoH *, long int); //Indica si existe el supervisor con la cedula dada
    void insFrontEnLista (NodoH * &, Supervisor *); //Inserta el supervisor al principio de la lista
    Supervisor * obtenerEnLista (NodoH *, long int); //Obtiene al supervisor con el numero de cedula dado
    void cargarIteradorSupervisor(NodoH *, IteradorPersonas &); //Carga el iterador de supervisores

public:
    Supervisores ();//Constructor por defecto
    bool member (long int);//Indica si el supervisor con la cedula dada esta en la coleccion
    void insertSupervisor (Supervisor *);//Inserta el supervisor en la coleccion
    Supervisor * find (long int);//Retorna al supervisor con la cedula dada
    IteradorPersonas listarSupervisores (); //Retorna un iterador con todos los supervisores del sistema
    ~Supervisores ();//Destructor
};

#endif // SUPERVISORES_H_INCLUDED
