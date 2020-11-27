#ifndef SUPERVISOR_H_INCLUDED
#define SUPERVISOR_H_INCLUDED
#include "Persona.h"

class Supervisor : public Persona
{
private :
    String barrio;
    int cantManzanas;

public :
    Supervisor (); //Constructor por defecto
    Supervisor (long int, String, String, int); //Constructor comun
    Supervisor (const Supervisor &); //Constructor de copia
    String getBarrio ();
    int getManzanas ();
    void setBarrio (String);
    void setManzanas (int);
    String getTipo();
    long int getCedulaSup();
};

#endif // SUPERVISOR_H_INCLUDED
