#ifndef CAPALOGICA_H_INCLUDED
#define CAPALOGICA_H_INCLUDED
#include "Supervisores.h"
#include "Vendedores.h"

class CapaLogica
{
private:
    Supervisores supervisores;
    Vendedores vendedores;
public :
    CapaLogica (); //Constructor por defecto
    void registrarSupervisor (Supervisor *, int &, long int, String, String, int); //Registra supervisor en el sistema
    void registrarVendedor (Vendedor *, int &); //Registra vendedor en el sistema
    IteradorPersonas listarSupervisores (); //Devuelve un iterador con todos los supervisores del sistema
    IteradorPersonas listarVendedores (); //Devuelve un iterador con todos los vendedores del sistema
    void listarVendedor (long int, int &); //Dada una cedula devuelve un vendedor y su supervisor
    void ventasSemanales (Vendedor &, int, int &); //Dada una cedula le asigna la cantidad de ventas semanales a un vendedor
    float sueldoTotal (); //Devuelve el sueldo total a pagar
    int cantContratadosHasta (Fecha, int &); //Devuelve el numero de vendedores zafrales que poseen contrato con fecha mayor a la dada
    bool validoCed (long int ced); //Comprueba si es una cedula valida
};

#endif // CAPALOGICA_H_INCLUDED
