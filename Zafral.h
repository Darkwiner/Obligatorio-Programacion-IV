#ifndef ZAFRAL_H_INCLUDED
#define ZAFRAL_H_INCLUDED
#include "Fecha.h"
#include "Vendedor.h"

class Zafral : public Vendedor
{
private:
  int comision;
  Fecha fechaVto;
public:
  Zafral (); //Constructor por defecto
  Zafral (int,Fecha, long int, String, int, int); //Constructor comun
  Zafral (const Zafral &); //Constructor de copia
  int getComision(); //Selectora comision
  Fecha getFecha(); // Selectora fecha
  void setComision(int); //Seteo comision
  void setFecha(Fecha); // Seteo fecha
  float sueldoTotal (); // Funcion polimorfica
  String getTipo();
};

#endif // ZAFRAL_H_INCLUDED
