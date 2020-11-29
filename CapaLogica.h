#ifndef CAPALOGICA_H_INCLUDED
#define CAPALOGICA_H_INCLUDED
#include "Supervisores.h"
#include "Vendedores.h"
#include "TipoError.h"
#include "IteradorPersonas.h"

class CapaLogica
{
private:
    Supervisores supervisores;
    Vendedores vendedores;

public :
    CapaLogica (); //Constructor por defecto
    void registrarSupervisor (Supervisor *, TipoError &);//Registra supervisor en el sistema
    void registrarVendedor (Vendedor *, TipoError &, long int);//Registra vendedor en el sistema
    IteradorPersonas listarSupervisoresCapa (); //Devuelve un iterador con todos los supervisores del sistema
    IteradorPersonas listarVendedoresCapa (); //Devuelve un iterador con todos los vendedores del sistema
    void ventasSemanales (Vendedor * &, int, TipoError &); //Dada una cedula le asigna la cantidad de ventas semanales a un vendedor
    float calculoSueldoTotal (); //Devuelve el sueldo total a pagar
    int cantContratadosHasta (Fecha, TipoError &); //Devuelve el numero de vendedores zafrales que poseen contrato con fecha mayor a la dada
    bool perteneceVendedor (long int); //Devuelve si el vendedor esta registrado
    Vendedor * obtengoVendedorCapa (long int, TipoError &); //Controla si el vendedor con esa cedula existe en el sistema
    Vendedor * obtengoVendedor (long int); //Retorna al vendedor con esa cedula
};

#endif // CAPALOGICA_H_INCLUDED
