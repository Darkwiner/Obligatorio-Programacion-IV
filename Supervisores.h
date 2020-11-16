#ifndef SUPERVISORES_H_INCLUDED
#define SUPERVISORES_H_INCLUDED
#include "Supervisor.h"

const int B = 60;

class Supervisores
{
private:
  struct NodoH {
      Supervisor * info;
      NodoH * sig;
  };
  NodoH * hash[B];

  int h (int);  // funci�n de dispersi�n
  void crearLista (NodoH * &);// crea una lista vac�a
  void destruirLista (NodoH * &);// destruye todo el contenido de la lista
  bool perteneceLista (NodoH *, int);// indica si existe una mascota con el n�mero ingresado
  void insFrontEnLista (NodoH * &, Supervisor *);// inserta la mascota al principio de la lista
  Supervisores * obtenerEnLista (NodoH *, int);// obtiene la mascota con el n�mero ingresado
  int cuantosEnLista (NodoH *, float);// cuenta cu�ntas mascotas poseen el peso ingresado

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
