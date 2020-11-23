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

//AYUDA CON ITERADOR, COMO SE LISTAN LOS OBJETOS
//String, usar como esta o usar constructor de String, etc
//Sacar procedimientos fuera de los case?
//Validaciones en el main?
//Procedimiento Print de String, como se usa
//Validar int sin pasarlo a string?

using namespace std;

bool validoCed (long int ced)
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
        }while(aux/10>0);

        TAM=i;
        int arre[TAM];

        aux=ced;

        for (i=TAM-1;i>=0;i--)
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
        for(i=0;i<TAM-1;i++)
           total=total+arre[i] ;
        res=total%10;
        res=10-res;
        if(res!=arre[TAM-1])
            valida=false;
    }
    return(valida);
}

int main()
{
    //Test vendedor zafral
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

    Supervisores HashSupervisores;
    Supervisores();
    Vendedores ABBVendedores;
    Vendedores();
    int opcion;

    do
    {
    cout << "\n ## E D I T O R I A L ##" << endl;
    cout << "\nMenu\n" << endl;
    cout << "\n1. Ingresar supervisor" << endl;
    cout << "\n2. Ingresar vendedor" << endl;
    cout << "\n3. Listar supervisores" << endl;
    cout << "\n4. Listar vendedores" << endl;
    cout << "\n5. Listar datos de un vendedor" << endl;
    cout << "\n6. Registrar ventas semanales de un vendedor" << endl;
    cout << "\n7. Calcular sueldos semanales" << endl;
    cout << "\n8. Cantidad de vendedores zafrales por fecha" << endl;
    cout << "\n0. Salir" << endl;
    cout << "\nIngrese la opcion deseada: ";
    cin.clear();
    cin >> opcion;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    switch (opcion)
    {
    case 1:
    {
        system("cls");
        cout << "\n1. Ingresar supervisor\n" << endl;
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
        long int cedula;
        istringstream(ced)>>cedula;
        if (!validoCed(cedula))
        {
            cout << "Cedula no valida. Compruebe el digito verificador y si el numero esta entre 500.000 y 7.000.000. " << endl;
        }
        else
        {
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
                cout << "Ha ocurrido un error, no se ha cargado correctamente el supervisor." << endl;
        }
        system("PAUSE");
    }
    break;
    case 2:
    {
        system("cls");
        cout << "\n2. Ingresar vendedor" << endl;
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
            int comision,dd,mm,aa;
            cout << "Ingrese comision: ";
            cin >> comision;
            cout << "Ingrese fecha fin de contrato" << endl;
            cout << "Ingrese dia: ";
            cin >> dd;
            cout << "Ingrese mes: ";
            cin >> mm;
            cout << "Ingrese anio: ";
            cin >> aa;
            Fecha f = Fecha (dd,mm,aa);
            if (f.esValida())
            {
                Zafral * z = new Zafral (comision, f, cedula, nombre, sueldo, 0);
                ABBVendedores.insertVendedor(z);
                if (ABBVendedores.member(cedula))
                    cout << "Vendedor Zafral cargado correctamente." << endl;
                else
                    cout << "Ha ocurrido un error, no se ha cargado correctamente el vendedor." << endl;
            }
            else
            {
                cout << "Fecha incorrecta." << endl;
                system("PAUSE");
                break;
            }
        }
        else
        {
            cout << "Ingrese plus: ";
            int plu;
            cin >> plu;
            Fijo * f = new Fijo (plu, cedula, nombre, sueldo, 0);
            ABBVendedores.insertVendedor(f);
            if (ABBVendedores.member(cedula))
                cout << "Vendedor Fijo cargado correctamente." << endl;
            else
                cout << "Ha ocurrido un error, no se ha cargado correctamente el vendedor" << endl;
        }
        system("PAUSE");
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
    }while(opcion != 0);
    system("cls");
    cout << "Gracias. Vuelva pronto." << endl;
}
