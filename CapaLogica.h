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
    IteradorPersonas listarSupervisoresCapa (IteradorPersonas &); //Devuelve un iterador con todos los supervisores del sistema
    IteradorPersonas listarVendedoresCapa (IteradorPersonas &); //Devuelve un iterador con todos los vendedores del sistema
    void listarVendedor (long int, TipoError &, Vendedor *); //Dada una cedula devuelve un vendedor y su supervisor //Dada una cedula devuelve un vendedor y su supervisor
    void ventasSemanales (Vendedor * &, int, TipoError &); //Dada una cedula le asigna la cantidad de ventas semanales a un vendedor
    float calculoSueldoTotal (); //Devuelve el sueldo total a pagar
    int cantContratadosHasta (Fecha, TipoError &); //Devuelve el numero de vendedores zafrales que poseen contrato con fecha mayor a la dada
    bool validoCed (long int); //Comprueba si es una cedula valida
    bool perteneceSupervisor (long int);
    bool perteneceVendedor (long int);
    Supervisor * obtengoSupervisor (long int);
    Vendedor * obtengoVendedor (long int);
};

#endif // CAPALOGICA_H_INCLUDED
