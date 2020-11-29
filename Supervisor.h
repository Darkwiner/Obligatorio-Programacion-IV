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
    String getBarrio (); //Selectora de barrio
    int getManzanas (); //Selectora de cantidad de manzanas
    void setBarrio (String); //Setear barrio
    void setManzanas (int); //Setear cantidad de manzanas
    String getTipo(); //Selectora de tipo de vendedor
    long int getCedulaSup(); //Selectora de cedula del supervisor
};

#endif // SUPERVISOR_H_INCLUDED
