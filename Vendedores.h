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
    void destruirArbol (Nodo * &);//Destruye todo el contenido del árbol
    bool perteneceEnArbol (Nodo *, long int);//Indica si existe un vendedor con la cédula ingresada
    void insertEnArbol (Nodo * &, Vendedor *);//Inserta el nuevo vendedor en el árbol
    Vendedor * obtenerEnArbol (Nodo *, long int);//Obtiene el vendedor con la cédula ingresada
    //void cargarIterador (Nodo *, IteradorPersonas &);//Carga el iterador recorriendo el árbol en orden
public:
    Vendedores ();//Constructor por defecto
    ~Vendedores ();//Destructor
    bool member (long int);//Indica si el vendedor con la cédula ingresada es miembro de la colección
    void insertVendedor (Vendedor *);//Inserta el nuevo vendedor a la colección
    //Precondición: el vendedor no es miembro de la colección
    Vendedor * find (long int);//Retorna al vendedor cuya cédula es la ingresada
    //Precondición: el vendedor es miembro de la colección
    //IteradorPersonas listarVendedores (Nodo *, IteradorPersonas &);//Devuelve un iterador conteniendo todos los vendedores a listar
    int buscarZafrales(Nodo *, Fecha);
    float calcularSueldo ();
};

#endif // VENDEDORES_H_INCLUDED
