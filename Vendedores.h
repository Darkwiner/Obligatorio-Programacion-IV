#ifndef VENDEDORES_H_INCLUDED
#define VENDEDORES_H_INCLUDED
#include "Vendedor.h"
#include "IteradorPersonas.h"
#include "Fecha.h"
#include "Fijo.h"
#include "Zafral.h"

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
    void destruirArbol (Nodo * &); //Destruye todo el contenido del �rbol
    bool perteneceEnArbol (Nodo *, long int); //Indica si existe un vendedor con la c�dula ingresada
    void insertEnArbol (Nodo * &, Vendedor *); //Inserta el nuevo vendedor en el �rbol
    Vendedor * obtenerEnArbol (Nodo *, long int); //Obtiene el vendedor con la c�dula ingresada
    void cargarIteradorVendedor (Nodo *, IteradorPersonas &); //Carga el iterador recorriendo el �rbol en orden
    void buscarZafrales(Nodo *, Fecha, int &); //Procedimiento privado para buscar Vendedores zafrales
public:
    Vendedores (); //Constructor por defecto
    bool member (long int); //Indica si el vendedor con la c�dula ingresada es miembro de la colecci�n
    void insertVendedor (Vendedor *);//Inserta el nuevo vendedor a la colecci�n
    Vendedor * find (long int); //Retorna al vendedor cuya c�dula es la ingresada
    IteradorPersonas listarVendedores (); //Devuelve un iterador conteniendo todos los vendedores a listar
    int buscarZafralesVendedores (Fecha f); //Devuelve el total de vendedores zafrales que tienen contrato mayor a la fecha dada
    float calcularSueldo (); //Devuelve el total de sueldos a pagar
    void calcularSueldoVendedores (Nodo *, float &);
    ~Vendedores (); //Destructor
    bool esVacio (); //Devuelve si la coleccion de vendedores esta vacia
};

#endif // VENDEDORES_H_INCLUDED
