#ifndef SUPERVISORES_H_INCLUDED
#define SUPERVISORES_H_INCLUDED
#include "Supervisor.h"

const int B = 60;

class Supervisores
{
private:
  struct NodoH {
      Mascota * info;
      NodoH * sig;
  };
  NodoH * hash[B];

  int h (int);  // funci�n de dispersi�n
  void crearLista (Nodo * &);// crea una lista vac�a
  void destruirLista (Nodo * &);// destruye todo el contenido de la lista
  bool perteneceLista (Nodo *, int);// indica si existe una mascota con el n�mero ingresado
  void insFrontEnLista (Nodo * &, Mascota *);// inserta la mascota al principio de la lista
  Supervisores * obtenerEnLista (Nodo *, int);// obtiene la mascota con el n�mero ingresado
  int cuantosEnLista (Nodo *, float);// cuenta cu�ntas mascotas poseen el peso ingresado

public:
  Supervisores ();// constructor por defecto
~ Supervisores ();// destructor

bool member (int);// indica si la mascota con el n�mero ingresado es miembro de// la colecci�n

void insert (Supervisores *);// inserta la nueva mascota a la colecci�n
// precondici�n: la mascota no es miembro de la colecci�n

Supervisores * find (int);// retorna la mascota cuyo n�mero es el ingresado
// precondici�n: la mascota es miembro de la colecci�n
};

#endif // SUPERVISORES_H_INCLUDED
