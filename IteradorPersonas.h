#ifndef ITERADORPERSONAS_H_INCLUDED
#define ITERADORPERSONAS_H_INCLUDED
#include "Persona.h"

class IteradorPersonas
{
private:
    struct nodoP
    {
        Persona * info;
        nodoP * sig;
    };
    nodoP * prim;
    nodoP * ult;
    nodoP * actual;

public:
    IteradorPersonas (); //Constructor por defecto
    void insertarPersona (Persona *); //Inserta en el iterador
    bool hayMasPersonas (); //Indica si quedan ms Personas por recorrer
    Persona * proximaPersona (); //Devuelve la proxima Persona por recorrer
    void cargarIterador (nodoP *, IteradorPersonas &);
    ~IteradorPersonas();
};

#endif // ITERADORPERSONAS_H_INCLUDED
