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
    if (!validoCed(ced))
        error = CEDULANOVALIDA;
    else if (supervisores.member(ced))
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
    if (!validoCed(ced))
        error = CEDULANOVALIDA;
    else if (!validoCed(cedSup))
        error = CEDULANOVALIDA;
    else if (!supervisores.member(cedSup))
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

void CapaLogica :: listarVendedor (long int cedula, TipoError &error, Vendedor *v)
{
    if (!validoCed(cedula))
    {
        error = CEDULANOVALIDA;
    }
    else if (!vendedores.member(cedula))
    {
        error = VENDEDORNOEXISTE;
    }
    else
    {
        v = vendedores.find(cedula);
    }
}

void CapaLogica :: ventasSemanales (Vendedor * &v, int ventas, TipoError &error)
{
    long int cedula = v->getCedula();
    if (!validoCed(cedula))
        error = CEDULANOVALIDA;
    else if (!vendedores.member(cedula))
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



bool CapaLogica :: validoCed (long int ced)
{
    bool valida=true;
    if(ced<5000000 || ced>70000000)
    {
        valida=false;
    }
    else
    {
        long int aux=ced;
        int i=1,res=0,total=0,TAM=0;
        do
        {
            aux=aux/10;
            i++;
        }
        while(aux/10>0);

        TAM=i;
        int arre[TAM];

        aux=ced;

        for (i=TAM-1; i>=0; i--)
        {
            arre[i]=aux%10;
            aux=aux/10;
        }

        arre[0]=arre[0]*2;
        arre[1]=arre[1]*9;
        arre[2]=arre[2]*8;
        arre[3]=arre[3]*7;
        arre[4]=arre[4]*6;
        arre[5]=arre[5]*3;
        if (TAM==8)
            arre[6]=arre[6]*4;
        for(i=0; i<TAM-1; i++)
            total=total+arre[i] ;
        res=total%10;
        res=10-res;
        if(res!=arre[TAM-1])
            valida=false;
    }
    return(valida);
}

