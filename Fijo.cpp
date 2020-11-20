#include "Fijo.h"

Fijo :: Fijo () : Vendedor()
{
  plus = 0;
}

Fijo :: Fijo (int p) : Vendedor()
{
    plus = p;
}

Fijo :: Fijo (const Fijo &otro) : Vendedor()
{
  plus = otro.plus;
}

float Fijo :: sueldoTotal ()
{
  // To do
  return 0;
}

int Fijo :: getPlus()
{
  return plus;
}

void Fijo :: setPlus (int p)
{
  plus = p;
}

String Fijo :: getTipo()
{
    String tipo("Fijo");
    return (String) tipo;
}

