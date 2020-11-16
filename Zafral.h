#ifndef ZAFRAL_H_INCLUDED
#define ZAFRAL_H_INCLUDED
#include "Fecha.h"

class Zafral
{
private:
  int comision;
  Fecha fechaVto;
public:
  Zafral (); //Constructor por defecto
  Zafral (int,Fecha); //Constructor comun
  Zafral (const Zafral &); //Constructor de copia
  int getComision(); //Selectora comision
  Fecha getFecha(); // Selectora fecha
  void setComision(int); //Seteo comision
  void setFecha(Fecha); // Selectora fecha
  float sueldoTotal (); // Funcion polimorfica
};

#endif // ZAFRAL_H_INCLUDED
