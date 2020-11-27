#include "CapaLogica.h"

/* ********* Estandar de errores ***********
Codigos:
1- Cedula invalida
2- Nombre invalido
3- Sueldo base invalido
4- Cantidad de ventas invalida
5- Cantidad de manzanas invalia
6- Comision invalida
7- Fecha invalida
200- Supervisor creado correctamente
201- Vendedor creado correctamente
400- Supervisor ya existe
401- Vendedor ya existe
500- Supervisor no registrado en el sistema
*/


CapaLogica :: CapaLogica () : supervisores (), vendedores ()
{
    //N/A
}

void CapaLogica :: registrarSupervisor (Supervisor * s, TipoError &error)
{
    long int ced = s->getCedula();
    if (supervisores.member(ced))
        error = SUPERVISORYAEXISTE;
    else if (s->getManzanas() < 0)
        error = MANZANASNOVALIDA;
    else
    {
        supervisores.insertSupervisor(s);
        error = SUPCARGADO;
    }
}

void CapaLogica :: registrarVendedor (Vendedor * v, TipoError &error, long int cedSup)
{
    long int ced = v->getCedula();
    if (!supervisores.member(cedSup))
        error = SUPERVISORNOEXISTE;
    else if (vendedores.member(ced))
        error = VENDEDORYAEXISTE;
    else if (v->getSueldoBase() < 0)
        error = SUELDONOVALIDO;
    else
    {
        Supervisor * s = supervisores.find(cedSup);
        v->setSupervisor(s);
        vendedores.insertVendedor(v);
        error = VENDCARGADO;
    }
}

bool CapaLogica :: perteneceSupervisor (long int ced)
{
    return supervisores.member(ced);
}

bool CapaLogica :: perteneceVendedor (long int ced)
{
    return vendedores.member(ced);
}


IteradorPersonas CapaLogica :: listarSupervisoresCapa (IteradorPersonas &iter)
{
    supervisores.listarSupervisores(iter);
    return  iter;
}

/*
IteradorPersonas CapaLogica :: listarVendedores ()
{

}

int cantContratadosHasta (Fecha, int &)
{
    return 0;
}*/


float CapaLogica :: calculoSueldoTotal ()
{
    float total = 0;
    {
        total = vendedores.calcularSueldo();
    }
    return total;
}

void CapaLogica :: ventasSemanales (Vendedor * &v, int ventas, TipoError &error)
{
    long int cedula = v->getCedula();
    if (!vendedores.member(cedula))
        error = VENDEDORNOEXISTE;
    else
    {
        v = vendedores.find(cedula);
        v->setCantVentas(ventas);
        error = SETCANTIDADVENTAS;
    }
}

Supervisor * CapaLogica :: obtengoSupervisor (long int ced)
{
    Supervisor * s = supervisores.find(ced);
    return s;
}

Vendedor * CapaLogica :: obtengoVendedor (long int ced)
{
    Vendedor * v = vendedores.find(ced);
    return v;
}
