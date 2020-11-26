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
#include "CapaLogica.h"
//#include "TipoError.h"

//AYUDA CON ITERADOR, COMO SE LISTAN LOS OBJETOS
//CASTEO DE ZAFRAL EN COMPARAR FECHAS
//COMO MOSTRAR UN STRING CON PRINT
//COMO MOSTRAR ELEMENTOS DE LOS ITERADORES
//calcularSueldo PREGUNTARRRR


using namespace std;

int main()
{
    Supervisores HashSupervisores;
    Vendedores ABBVendedores;
    CapaLogica Fachada;
    IteradorPersonas Iterador;
    int opcion;

    do
    {
        cout << "\n                                     ## E D I T O R I A L ##" << endl;
        cout << "\n   Menu Principal" << endl;
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
            cout << "Confirma los datos ingresados? S/N: ";
            char confirma;
            cin >> confirma;
            if (confirma == 'S' || confirma == 's')
            {
                Supervisor * s = new Supervisor (cedula, nombre, barrio, cantManzanas);
                TipoError error;
                Fachada.registrarSupervisor(s,error);
                muestroError (error);
            }
            else
            {
                cout << "Borrando datos..." << endl;
                system("PAUSE");
                system("cls");
            }

        }
        break;
        case 2:
        {
            system("cls");
            {
                int i;
                string cedSup;
                while(true)
                {
                    cout << "Introduce la cedula del supervisor: ";
                    getline(cin, cedSup);
                    stringstream mystream(cedSup);
                    if(mystream >> i) break;
                    cout << "Cedula no valida, solo se permiten numeros. " << endl;
                }
                long int cedulaSupervisor;
                istringstream(cedSup)>>cedulaSupervisor;
                string ced;
                while(true)
                {
                    cout << "Introduce la cedula del vendedor: ";
                    getline(cin, ced);
                    stringstream mystream(ced);
                    if(mystream >> i) break;
                    cout << "Cedula no valida, solo se permiten numeros. " << endl;
                }
                long int cedula;
                istringstream(ced)>>cedula;
                {
                    cout << "Ingrese nombre: ";
                    char cadena[80];
                    cin >> cadena;
                    char * nombre = new char[strlen(cadena)+1];
                    nombre = cadena;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<< "Ingrese el sueldo base: ";
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
                            Vendedor * vend = new Zafral (comision, f, cedula, nombre, sueldo, 0, NULL);
                            TipoError error;
                            Fachada.registrarVendedor(vend,error,cedulaSupervisor);
                            muestroError (error);
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
                        Vendedor * vend = new Fijo (plu, cedula, nombre, sueldo, 0, NULL);
                        TipoError error;
                        Fachada.registrarVendedor(vend,error,cedulaSupervisor);
                        muestroError (error);
                    }
                }
            }
            system("PAUSE");
            system("cls");
        }
        break;
        case 3: //Listado de supervisores registrados. No se pide ningún orden para este listado.
            Fachada.listarSupervisoresCapa(Iterador);
            while (Iterador.hayMasPersonas())
            {
                Persona * p = Iterador.proximaPersona();
                cout <<p->getCedula() << " ";
                ((Supervisor *) p)->getNombre().print();
                ((Supervisor *) p)->getBarrio().print(); //Casteo
                cout <<((Supervisor *) p)->getManzanas() << " ";

            }
            break;
        case 4:
            break;
        case 5: //Dada la cedula de un vendedor, listar todos sus datos junto con los datos de su supervisor.
        {
            cout << "Ingrese cedula de vendedor" << endl;
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
            TipoError error;

            Vendedor * v;
            Fachada.listarVendedor(cedula,error,v);
            Supervisor * sup = v->getSupervisor;
            //cout << "\nLos datos son: " << v->getCedula() << v->getNombre() << v->getTipo() << endl;
        }
        break;
        case 6: //Dada la cédula de un vendedor, registrar la cantidad de ventas que realizó en la semana
        {
            cout << "Ingrese cedula de vendedor" << endl;
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
            cout << "Ingrese cantidad de ventas semanal: ";
            int ventas;
            cin >> ventas;
            Vendedor * v = Fachada.obtengoVendedor(cedula);
            TipoError error;
            cout << "Antes de setear" << v->getCantVentas();
            Fachada.ventasSemanales(v, ventas, error);
            cout << "Despues de setear" << v->getCantVentas();
            muestroError(error);
        }
        break;
        case 7:
        {

        }
        break;
        case 8:
            /*
               int monto = 0;
               cout << "Ingrese una fecha para conocer los vendedores zafrales actualmente \n registrados que estarán contratados hasta después de esa fecha." << endl;
               int dd;
               cout << "\n Ingrese dia: ";
               cin >> dd;
               int mm;
               cout << "\n Ingrese mes: ";
               cin >> mm;
               int aa;
               cout << "\n Ingrese anio: ";
               cin >> aa;
               Fecha fz = Fecha (dd,mm,aa);
               if (fz.esValida())
               {
                   monto = vendedores.buscarZafrales(Fachada.vendedores, fz);
                   cout << "Cantidad de Vendedores Zafrales: " << monto << endl;
               }
               else
               {
                   cout << "Fecha incorrecta." << endl;
                   system("PAUSE");
                   break;
               }*/
            break;
        case 0 :
            break;
        default:
            cout << endl << "No es una opcion valida, ingrese nuevamente." << endl;
            system("PAUSE");
            system("cls");
            break;
        }
    }
    while(opcion != 0);
    system("cls");
    cout << "Hasta la proxima!" << endl;
}






