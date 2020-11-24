#include "CapaLogica.h"

/* ********* Estandar de errores ***********
Codigos:
1- Cedula invalida
2- Nombre invalido
3- Sueldo base invalido
4- Cantidad de ventas invalida
5- Cantidad de manzanas invalia
200- Supervisor creado correctamente
201- Vendedor creado correctamente
400- Supervisor ya existe
401- Vendedor ya existe
*/


CapaLogica :: CapaLogica () : supervisores (), vendedores ()
{
    //N/A
}

void CapaLogica :: registrarSupervisor (Supervisor * s, int &codigo, long int ced, String nom, String b, int manzanas)
{
    bool sinErrores = true;
    while (sinErrores)
    {
        if (validoCed(ced))
            {codigo = 1; sinErrores = false;}
        else
            if (supervisores.member(ced))
                {codigo = 400; sinErrores = false;}
            else
                if (manzanas < 0)
                    {codigo = 5; sinErrores = false;}
                else
                {
                    s = new Supervisor (ced, nom, b, manzanas);
                    supervisores.insertSupervisor(s);
                    codigo = 200;
                }
    }
}

void CapaLogica :: registrarVendedor (Vendedor * v, int &error)
{

}

IteradorPersonas CapaLogica :: listarSupervisores ()
{

}

IteradorPersonas CapaLogica :: listarVendedores ()
{

}

void CapaLogica :: listarVendedor (long int cedula, int &error)
{

}

void CapaLogica :: ventasSemanales (Vendedor &v, int ventas, int &error)
{

}

float CapaLogica :: sueldoTotal ()
{
    return 0;
}

int cantContratadosHasta (Fecha, int &)
{
    return 0;
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

