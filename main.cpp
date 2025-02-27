#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include "Supervisor.h"
#include "CapaLogica.h"
#include "Validaciones.h"

using namespace std;

int main()
{
    Supervisores HashSupervisores;
    Vendedores ABBVendedores;
    CapaLogica Fachada;
    IteradorPersonas Iterador;
    int opcion;
    long int cedula, cedulaSupervisor;

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

        switch(opcion)
        {
        case 1: //Registrar los datos de un nuevo supervisor.
        {
            system("cls");
            cout << "\n1. Ingresar supervisor\n" << endl;
            cedula=nuevaCedula();
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
            int cantManzanas=validarNum();
            cout << "\nConfirma los datos ingresados? S/N: ";
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
        }break;
        case 2: //Dada la c�dula de un supervisor y los datos de un nuevo vendedor, dar de alta al vendedor en el sistema, asign�ndole el supervisor con dicha c�dula.
        {
            system("cls");
            cout << "\n2. Ingresar Vendedor\n" << endl;
            cout << "\nIngrese el Supervisor\n";
            cedulaSupervisor=nuevaCedula();
            cout << "\nIngrese el Vendedor\n";
            cedula=nuevaCedula();
            cout << "Ingrese nombre: ";
            char cadena[80];
            cin >> cadena;
            char * nombre = new char[strlen(cadena)+1];
            nombre = cadena;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<< "Ingrese el sueldo base: ";
            float sueldo=validarFloat();
            cout << "Desea registrar un vendedor Zafral o Fijo? Z/F: ";
            char opcionReq2;
            cin >> opcionReq2;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (opcionReq2 == 'z' || opcionReq2 == 'Z')
            {
                int comision,dd,mm,aa;
                cout << "\nIngrese comision: ";
                comision=validarNum();
                cout << "\nIngrese fecha fin de contrato" << endl;
                cout << "Ingrese dia: ";
                dd = validarNum();
                cout << "Ingrese mes: ";
                mm = validarNum();
                cout << "Ingrese anio: ";
                aa = validarNum();
                Fecha f = Fecha (dd,mm,aa);
                if (f.esValida())
                {
                    Vendedor * vend = new Zafral (comision, f, cedula, nombre, sueldo, 0, NULL);
                    TipoError error;
                    Fachada.registrarVendedor(vend,error,cedulaSupervisor); //
                    muestroError (error);
                }
                else
                {
                    cout << "\nFecha incorrecta." << endl;
                    system("PAUSE");
                    system("cls");
                }
            }
            else
            {
                cout << "\nIngrese plus: ";
                int plu = validarNum();
                Vendedor * vend = new Fijo (plu, cedula, nombre, sueldo, 0, NULL);
                TipoError error;
                Fachada.registrarVendedor(vend,error,cedulaSupervisor); //
                muestroError (error);
            }
            system("cls");
        }break;
        case 3: //Listado de supervisores registrados. No se pide ning�n orden para este listado.
        {
            system("cls");
            cout << "3. Listar supervisores\n" << endl;
            IteradorPersonas iteradorSupervisores = Fachada.listarSupervisoresCapa(); //
            if (iteradorSupervisores.hayMasPersonas()) //
            {
                while (iteradorSupervisores.hayMasPersonas()) //
                {
                    Persona * p = (Supervisor *) iteradorSupervisores.proximaPersona();
                    cout << p->getCedula() << " - ";
                    ((Supervisor *) p)->getNombre().print();
                    cout << " - ";
                    ((Supervisor *) p)->getBarrio().print();
                    cout << " - ";
                    cout <<((Supervisor *) p)->getManzanas() << endl << endl;
                }
            }
            else
                cout << "ERROR: No hay supervisores en el sistema." << endl;
        system("PAUSE");
        }
        break;
        case 4: //Listado de vendedores registrados. Este listado debe realizarse ordenado por c�dula de menor a mayor.
        {
            system("cls");
            cout << "4. Listar vendedores\n" << endl;
            IteradorPersonas iteradorVendedores = Fachada.listarVendedoresCapa(); //
            if (iteradorVendedores.hayMasPersonas()) //
            {
                while (iteradorVendedores.hayMasPersonas()) //
                {
                    Persona * p = iteradorVendedores.proximaPersona(); //
                    cout << p->getCedula() << " - ";
                    ((Vendedor *)p)->getNombre().print();
                    cout << " - ";
                    ((Vendedor *)p)->getTipo().print();
                    cout << endl << endl;
                }
            }
            else
                cout << "ERROR: No hay supervisores en el sistema." << endl;
        system("PAUSE");
        }break;
        case 5: //Dada la c�dula de un vendedor, listar todos sus datos junto con los datos de su supervisor.
        {
            system("cls");
            cout << "5. Listar datos de un vendedor\n" << endl;
            cout << "Ingrese el Vendedor\n" << endl;

            cedula=nuevaCedula();
            Vendedor * v;
            if(Fachada.perteneceVendedor(cedula)) //
            {
                v=Fachada.obtengoVendedor(cedula); //
                cout << "\nLos datos del Vendedor son: \n" << endl;
                cout << "Cedula: " << v->getCedula() << endl;
                cout << "Nombre: " ;
                v->getNombre().print();
                cout << "\nSueldo Base: " << v->getSueldoBase() <<endl;
                cout << "Cantidad de Ventas: " << v->getCantVentas() <<endl;
                if(v->getTipo()=="Zafral")
                {
                    Fecha f=((Zafral *)v)->getFecha();
                    cout << "Zafral" << endl;
                    cout << "Comision: " << ((Zafral *) v)->getComision() << endl;
                    cout << "Fecha de Vencimiento: ";
                    f.mostrar();
                }
                else
                {
                    cout << "Fijo" << endl;
                    cout << "Plus: " << ((Fijo *) v)->getPlus() << endl;
                }
                cout << "\nLos datos de su Supervisor son: \n" << endl;
                cout << "Cedula: " << v->getSupervisor()->getCedula() << endl;
                cout << "Nombre: " ;
                v->getSupervisor()->getNombre().print();
                cout << "\nBarrio: " ;
                v->getSupervisor()->getBarrio().print();
                cout << "\nManzana: " << v->getSupervisor()->getManzanas() << endl;
            }
            else
                cout << "\nNo se encuentra el vendedor. Intente nuevamente." << endl;
            system("PAUSE");
            system("cls");
        }break;
        case 6: //Dada la c�dula de un vendedor, registrar la cantidad de ventas que realiz� en la semana.
        {
            system("cls");
            cout << "6. Registrar ventas semanales de un vendedor\n" << endl;
            cout << "Ingrese cedula de vendedor:" << endl;
            cedula=nuevaCedula();
            cout << "\nIngrese cantidad de ventas semanal: ";
            int ventas=validarNum();
            TipoError error;
            Vendedor * v = Fachada.obtengoVendedorCapa(cedula, error);
            Fachada.ventasSemanales(v, ventas, error);
            muestroError(error);
        }break;
        case 7: //Calcular el monto total de sueldos a pagar a los vendedores en la semana. Recordar que el c�lculo del sueldo de cada vendedor depende del tipo de vendedor.
        {
            system("cls");
            cout << "7. Calcular sueldos semanales\n" << endl;
            float totalSueldos = Fachada.calculoSueldoTotal(); //
            cout << "El total de sueldos a pagar en la semana es: $" << totalSueldos << endl;
            system("PAUSE");
            system("cls");
        }break;
        case 8: //Dada una fecha, contar cu�ntos de los vendedores zafrales actualmente registrados estar�n contratados hasta despu�s de esa fecha.
        {
            system("cls");
            int dd,mm,aa;
            cout << "8. Cantidad de vendedores zafrales por fecha\n" << endl;
            cout << "\nIngrese dia: ";
            dd = validarNum();
            cout << "Ingrese mes: ";
            mm = validarNum();
            cout << "Ingrese anio: ";
            aa = validarNum();
            Fecha fz = Fecha (dd,mm,aa);
            TipoError error;
            if (fz.esValida()) //
            {
                int total = Fachada.cantContratadosHasta(fz, error); //
                cout << "\nCantidad de Vendedores Zafrales: " << total << endl;
            }
            else
            {
                cout << "Fecha incorrecta." << endl;
            }
            muestroError(error);
            system("PAUSE");
            system("cls");
        }break;
        case 0:
        {
        }break;
        default:
        {
                cout << endl << "Opcion no valida. Intente nuevamente." << endl;
                system("PAUSE");
                system("cls");
        }break;
        }
    }while(opcion != 0);
    system("cls");
    cout << "Hasta la proxima!" << endl;
}
