#include "Vendedor.h"
#include "Vendedores.h"
#include "Zafral.h"
#include "Fijo.h"
#include "Fecha.h"
#include <limits>
#include "String.h"
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Supervisor.h"
#include "Supervisores.h"

///AYUDA CON ITERADOR, COMO SE LISTAN LOS OBJETOS


using namespace std;

int main()
{
    ///Test vendedor zafral
    /*

    int i;
    string ced;

    while(true) {
        cout << "Introduce una cedula: ";
        getline(cin, ced);
        stringstream mystream(ced);
        if(mystream >> i) break;
        cout << "Cedula no valida, solo se permiten numeros. " << endl;
    }
    int cedula;
    istringstream(ced)>>cedula;
    cout<< "Ingrese el sueldo base: " <<endl;
    float sueldo;
    cin>>sueldo;
    cout<< "Ingrese la cantidad de ventas: " <<endl;
    int ventas;
    cin>>ventas;
    Fecha f = Fecha (22, 11, 2020);
    cout<< "Ingrese el nombre del vendedor: " <<endl;
    char cadena[80];
    cin >> cadena;
    char * nombre = new char[strlen(cadena)+1];
    nombre = cadena;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    Zafral * v = new Zafral (ventas, f, cedula, nombre, sueldo, ventas);
    cout << "Nombre: " << nombre << endl;
    cout << "Fecha fin de contrato: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl; ///CONSULTAR PRINT DEL STRING PARA MOSTRAR EL NOMBRE
    cout << "Cedula: " << v->getCedula() << " Sueldo: " << v->getSueldoBase() << " Ventas: " << v->getCantVentas() << endl;

    ///Test vendedor Fijo
    char cadena[80];
    cout << "Ingrese nombre: " << endl;
    cin >> cadena;
    char * nombre = new char [strlen(cadena)+1];
    nombre = cadena;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    Fijo * f = new Fijo (5, 53573642, nombre, 12000, 10);
    cout << "Plus: " << f->getPlus() << " Cedula: " << f->getCedula();
    cout << " Nombre: " << nombre;
    cout << " Sueldo: " << f->getSueldoBase() << " Cantidad de ventas: " << f->getCantVentas() << endl;

    */
    cout << "\n ## E D I T O R I A L ##" << endl;

    cout << "\nMenu" << endl;
    system("PAUSE");
    system("cls");

    cout << "\n1. Ingresar supervisor" << endl;
    cout << "\n2. Ingresar vendedor" << endl;
    cout << "\n3. Listar supervisores" << endl;
    cout << "\n4. Listar vendedores" << endl;
    cout << "\n5. Listar datos de un vendedor" << endl;
    cout << "\n6. Registrar ventas semanales de un vendedor" << endl;
    cout << "\n7. Calcular sueldos semanales" << endl;
    cout << "\n8. Cantidad de vendedores zafrales por fecha" << endl;
    cout << "\nIngrese la opcion deseada: ";
    int opcion;
    cin >> opcion;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    Supervisores HashSupervisores;
    Supervisores();
    Vendedores ABBVendedores;
    Vendedores();

    switch (opcion)
    {
    case 1:
    {
        int i;
        string ced;
        while(true)
        {
            cout << "Introduce una cedula: ";
            getline(cin, ced);
            stringstream mystream(ced);
            if(mystream >> i) break;
            cout << "Cedula no valida, solo se permiten numeros. " << endl;
        }
        int cedula;
        istringstream(ced)>>cedula;
        cout << "Ingrese nombre: ";
        char cadena[80];
        cin >> cadena;
        char * nombre = new char[strlen(cadena)+1];
        nombre = cadena;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Ingrese barrio: ";
        char cadenaBarrio[80];
        cin >> cadenaBarrio;
        char * barrio = new char[strlen(cadenaBarrio)+1];
        barrio = cadenaBarrio;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Ingrese cantidad de manzanas: ";
        int cantManzanas;
        cin >> cantManzanas;
        Supervisor * s = new Supervisor (cedula, nombre, barrio, cantManzanas);
        HashSupervisores.insertSupervisor(s);
        if (HashSupervisores.member(cedula))
            cout << "Supervisor cargado correctamente." << endl;
        else
            cout << "Ha ocurrido un error, no se ha cargado correctamente el supervisor" << endl;
    }
    break;
    case 2:
    {
        int i;
        string ced;
        while(true)
        {
            cout << "Introduce una cedula: ";
            getline(cin, ced);
            stringstream mystream(ced);
            if(mystream >> i) break;
            cout << "Cedula no valida, solo se permiten numeros. " << endl;
        }
        int cedula;
        istringstream(ced)>>cedula;
        cout << "Ingrese nombre: ";
        char cadena[80];
        cin >> cadena;
        char * nombre = new char[strlen(cadena)+1];
        nombre = cadena;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<< "Ingrese el sueldo base: " <<endl;
        float sueldo;
        cin>>sueldo;
        cout << "Desea registrar un vendedor Zafral o Fijo? Z/F: ";
        char opcionReq2;
        cin >> opcionReq2;
        if (opcionReq2 == 'z' || opcionReq2 == 'Z')
        {
            cout << "Ingrese comision: ";
            int comision;
            cin >> comision;
            cout << "Ingrese fecha fin de contrato" << endl;
            cout << "Ingrese dia: "; ///CONTROLAR QUE SEA UNA FECHA VALIDA: IMPLEMENTAR!!!!!!!!
            int dia;
            cin >> dia;
            cout << "Ingrese mes: ";
            int mes;
            cin >> mes;
            cout << "Ingrese anio: ";
            int anio;
            cin >> anio;
            Fecha f = Fecha (dia,mes,anio);
            Zafral * z = new Zafral (comision, f, cedula, nombre, sueldo, 0);
            ABBVendedores.insertVendedor(z);
            if (ABBVendedores.member(cedula))
                cout << "Vendedor Zafral cargado correctamente." << endl;
            else
                cout << "Ha ocurrido un error, no se ha cargado correctamente el vendedor" << endl;
        }
        else
        {
            cout << "Ingrese plus: ";
            int plu;
            cin >> plu;
            Fijo * f = new Fijo (plu, cedula, nombre, sueldo, 0);
            ABBVendedores.insertVendedor(f);
            if (ABBVendedores.member(cedula))
                cout << "Vendedor Zafral cargado correctamente." << endl;
            else
                cout << "Ha ocurrido un error, no se ha cargado correctamente el vendedor" << endl;
        }
    }

    break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    default:
        break;
    }

}

