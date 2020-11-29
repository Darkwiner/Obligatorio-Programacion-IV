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
    virtual float sueldoTotal (); //Funcion polimorfica
    float getSueldoBase (); //Selectora de sueldo base
    int getCantVentas (); //Selectora de cantidad de ventas
    void setSueldoBase (float); //Setear sueldo base
    void setCantVentas (int); //Setear cantidad de ventas
    long int getCedulaVen (); //Selectora de cedula de vendedor
    void setSupervisor (Supervisor *); //Setear supervisor a vendedor
    long int getCedulaSup (); //Selectora de cedula de supervisor de vendedor
    Supervisor * getSupervisor (); //Obtengo el supervisor del vendedor
    ~Vendedor(); //Destructor
    bool esZafral (Fecha); //Devuelve si el vendedor es zafral
};
#endif // VENDEDOR_H_INCLUDED
