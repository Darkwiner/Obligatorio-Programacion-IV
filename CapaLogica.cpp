#include "CapaLogica.h"

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

bool CapaLogica :: perteneceVendedor (long int ced)
{
    return vendedores.member(ced);
}

IteradorPersonas CapaLogica :: listarSupervisoresCapa ()
{
    return supervisores.listarSupervisores();
}

IteradorPersonas CapaLogica :: listarVendedoresCapa ()
{
    return vendedores.listarVendedores();
}

int CapaLogica :: cantContratadosHasta (Fecha f, TipoError &error)
{
    return(vendedores.buscarZafralesVendedores(f));
}

float CapaLogica :: calculoSueldoTotal ()
{
    float total = 0;
    if (!vendedores.esVacio())
        total = vendedores.calcularSueldo();
    else
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

Vendedor * CapaLogica :: obtengoVendedorCapa (long int cedula, TipoError &error)
{
    if (!perteneceVendedor(cedula))
        error = VENDEDORNOEXISTE;
    else
        return obtengoVendedor(cedula);
}

Vendedor * CapaLogica :: obtengoVendedor (long int ced)
{
    Vendedor * v = vendedores.find(ced);
    return v;
}
