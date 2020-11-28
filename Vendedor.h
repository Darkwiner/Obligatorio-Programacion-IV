#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
#include "Persona.h"
#include "Supervisor.h"
#include "Fecha.h"

class Vendedor : public Persona
{
private :
    float sueldoBase;
    int cantVentas;
    Supervisor * sup;

public :
    Vendedor (); //Constructor por defecto
    Vendedor (int, String, float, int, Supervisor *); //Constructor comun
    Vendedor (const Vendedor &);//Constructor de copia
    virtual float sueldoTotal (); // Funcion polimorfica
    float getSueldoBase ();
    int getCantVentas ();
    void setSueldoBase (float);
    void setCantVentas (int);
    long int getCedulaVen ();
    void setSupervisor (Supervisor *);
    long int getCedulaSup ();
    Supervisor * getSupervisor ();
    ~Vendedor();
    bool esZafral (Fecha);
};
#endif // VENDEDOR_H_INCLUDED
