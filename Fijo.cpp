#include "Fijo.h"

Fijo :: Fijo ()
{
  plus = 0;
}

Fijo :: Fijo (int p)
{
    plus = p;
}

Fijo :: Fijo (const Fijo &otro)
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

Fijo :: ~Fijo()
{

}
