#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "String.h"

class Persona
{
private :
    long int cedula;
    String nombre;
public :
    Persona (); //Constructor por defecto
    Persona (long int, String); //Constructor comun
    Persona (const Persona &); //Constructor de copia
    long int getCedula (); //Obtengo cedula
    String getNombre (); //Obtengo nombre
    void setCedula (long int); //Seteo cedula
    void setNombre (String); //Seteo nombre
};

#endif // PERSONA_H_INCLUDED
