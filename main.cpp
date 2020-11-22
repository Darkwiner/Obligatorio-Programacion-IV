#include "Vendedor.h"
#include "Zafral.h"
#include "Fecha.h"
#include <limits>
#include "String.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
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
    Zafral * v = new Zafral (ventas, f, cedula, nombre, 16000, 5);
    cout << "Nombre: " << nombre << endl;
    cout << "Fecha fin de contrato: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
    cout << "Cedula: " << v->getCedula() << " Sueldo: " << v->getSueldoBase() << " Ventas: " << v->getCantVentas() << endl;
}

