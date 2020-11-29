#include "Fecha.h"

void Fecha :: incrementar ()
{
  switch (mm)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
      if (dd == 31)
      {
          dd = 1;
          if (mm == 12)
          {
              aa++;
              mm = 1;
          }
          else
              mm++;
      }
      else
          dd++;
      break;
  case 4:
  case 6:
  case 9:
  case 11:
      if (dd == 30)
      {
          dd = 1;
          mm++;
      }
          else
              dd++;
          break;
      case 2:
          if (((aa % 4 == 0) && (aa % 100 != 0)) || ((aa % 400 == 0)))
          {
              if (dd == 29)
              {
                  dd = 1;
                  mm++;
              }
              else
                  dd++;
          }
          else if (dd == 28)
          {
              dd = 1;
              mm++;
          }
          else
              dd++;
    }
}

Fecha :: Fecha ()
{
    aa = 2000;
    mm = 1;
    dd = 1;
}

Fecha :: Fecha (int d, int m, int a)
{
    aa = a;
    mm = m;
    dd = d;
}

Fecha :: Fecha (const Fecha &f)
{
    aa = f.aa;
    mm = f.mm;
    dd = f.dd;
}

int Fecha :: getDia ()
{
    return dd;
}

int Fecha :: getMes ()
{
    return mm;
}

int Fecha :: getAnio ()
{
    return aa;
}

bool Fecha :: operator< (Fecha f)
{
    bool es = false;
    if (aa < f.aa)
        es = true;
    else if (aa > f.aa)
        es = false;
    else if (mm < f.mm)
        es = true;
    else if (mm > f.mm)
        es = false;
    else if (dd < f.dd)
        es = true;
    else
        es = false;
    return es;
}

bool Fecha :: operator== (Fecha f)
{
    return (bool) (aa==f.aa && mm==f.mm && dd==f.dd);
}

Fecha Fecha :: operator+ (int d)
{
    Fecha resu = (*this);
    int cont;
    for (cont=1; cont <= d; cont++)
        resu.incrementar ();
    return (resu);
}

Fecha Fecha :: operator++()
{
    incrementar ();
    return (*this);
}

Fecha Fecha :: operator++(int)
{
    Fecha resu = (*this);
    incrementar ();
    return resu;
}

int Fecha :: operator- (Fecha f)
{
    Fecha aux;
    int signo = 1;
    int cont = 0;
    if (*this < f)
        for (aux = *this; aux < f; aux++)
            cont++;
    else
    {
        signo = -1;
        for (aux = f; aux < *this; aux++)
            cont++;
    }
    return (signo * cont);
}

bool Fecha :: esValida () //
{
    bool es = true;
    if (aa < 1900 || aa > 2099)
        es = false;
    else
    {
        switch (mm)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
                if(dd < 1 || dd > 31)
                    es=false;
                break;
        case 4:
        case 6:
        case 9:
        case 11:
                if(dd < 1 || dd > 30)
                    es=false;
                break;
        case 2:
                if (((aa % 4 == 0) && (aa % 100 != 0)) || (aa % 400 == 0))
                {
                    if(dd < 1 || dd > 29)
                        es=false;
                }
                else
                {
                    if(dd < 1 || dd > 28)
                        es=false;
                }
                break;
        default:
                es=false;
                break;
        }
    }
    return es;
}

void Fecha :: mostrar ()
{
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}
