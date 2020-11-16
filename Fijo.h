#ifndef FIJO_H_INCLUDED
#define FIJO_H_INCLUDED
#include "Vendedor.h"

class Fijo : public Vendedor
{
private:
  int plus;
public :
  Fijo (); //Constructor por defecto
  Fijo (int); //Constructor comun
  Fijo (const Fijo &); //Constructor de copia
  float sueldoTotal (); // Funcion polimorfica
  virtual ~Fijo();
  int getPlus();  // Selectora
  void setPlus (int); //Seteo plus
};

#endif // FIJO_H_INCLUDED
