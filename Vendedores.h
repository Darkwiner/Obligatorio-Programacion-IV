#ifndef VENDEDORES_H_INCLUDED
#define VENDEDORES_H_INCLUDED
#include "Vendedor.h"
#include "IteradorPersonas.h"
#include "Fecha.h"


class Vendedores
{
private:
    struct Nodo
    {
        Vendedor * info;
        Nodo * hizq;
        Nodo * hder;
    };
    Nodo * ABB;
    void destruirArbol (Nodo * &);//Destruye todo el contenido del �rbol
    bool perteneceEnArbol (Nodo *, long int);//Indica si existe un vendedor con la c�dula ingresada
    void insertEnArbol (Nodo * &, Vendedor *);//Inserta el nuevo vendedor en el �rbol
    Vendedor * obtenerEnArbol (Nodo *, long int);//Obtiene el vendedor con la c�dula ingresada
    //void cargarIterador (Nodo *, IteradorPersonas &);//Carga el iterador recorriendo el �rbol en orden
public:
    Vendedores ();//Constructor por defecto
    ~Vendedores ();//Destructor
    bool member (long int);//Indica si el vendedor con la c�dula ingresada es miembro de la colecci�n
    void insertVendedor (Vendedor *);//Inserta el nuevo vendedor a la colecci�n
    //Precondici�n: el vendedor no es miembro de la colecci�n
    Vendedor * find (long int);//Retorna al vendedor cuya c�dula es la ingresada
    //Precondici�n: el vendedor es miembro de la colecci�n
    //IteradorPersonas listarVendedores (Nodo *, IteradorPersonas &);//Devuelve un iterador conteniendo todos los vendedores a listar
    int buscarZafrales(Nodo *, Fecha);
    float calcularSueldo ();
};

#endif // VENDEDORES_H_INCLUDED
