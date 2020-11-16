#include "Fijo.h"

Fijo :: Fijo ()
{
  plus = 0;
}

Fijo :: Fijo (int plus)
{
    plus = plus;
}

Fijo :: Fijo (const Fijo &otro)
{
  plus = otro.plus;
}

String Supervisor :: getBarrio ()
{
    return barrio;
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
