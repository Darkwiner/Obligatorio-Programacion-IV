#ifndef SUPERVISOR_H_INCLUDED
#define SUPERVISOR_H_INCLUDED
#include "Persona.h"

class Supervisor
{
private :
    String barrio;
    int cantManzanas;
public :
    Supervisor (); //Constructor por defecto
    Supervisor (String, int); //Constructor comun
    Supervisor (const Supervisor &); //Constructor de copia
    String getBarrio ();
    int getManzanas ();
    void setBarrio (String);
    void setManzanas (int);
};

#endif // SUPERVISOR_H_INCLUDED
