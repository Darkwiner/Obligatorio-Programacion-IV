#ifndef SUPERVISORES_H_INCLUDED
#define SUPERVISORES_H_INCLUDED
#include "Supervisor.h"

const int B = 60;

class Supervisores
{
private:
        struct NodoH{
                        Mascota * info;
                        NodoH * sig;
                        };
        NodoH * hash[B];

int h (int);  // función de dispersión
void crearLista (Nodo * &);// crea una lista vacía
void destruirLista (Nodo * &);// destruye todo el contenido de la lista
boolean perteneceLista (Nodo *, int);// indica si existe una mascota con el número ingresado
void insFrontEnLista (Nodo * &, Mascota *);// inserta la mascota al principio de la lista
Supervisores * obtenerEnLista (Nodo *, int);// obtiene la mascota con el número ingresado
int cuantosEnLista (Nodo *, float);// cuenta cuántas mascotas poseen el peso ingresado

public:

Supervisores ();// constructor por defecto

~ Supervisores ();// destructor

boolean member (int);// indica si la mascota con el número ingresado es miembro de// la colección

void insert (Supervisores *);// inserta la nueva mascota a la colección
// precondición: la mascota no es miembro de la colección

Supervisores * find (int);// retorna la mascota cuyo número es el ingresado
// precondición: la mascota es miembro de la colección

};


#endif // SUPERVISORES_H_INCLUDED
