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

//AYUDA CON ITERADOR, COMO SE LISTAN LOS OBJETOS
//CASTEO DE ZAFRAL EN COMPARAR FECHAS
//COMO MOSTRAR ELEMENTOS DE LOS ITERADORES
//calcularSueldo PREGUNTARRRR

// Pasar TipoError a validoCedula?
// Declarar variables arriba del todo? Ahora esta declarado 50 veces long int cedula por ejemplo
// Revisar comentarios

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

long int nuevaCedula ()
{
            int i;
            string ced;
            long int cedula;
            do
            {
                while(true)
                {
                    cout << "Ingrese la cedula: ";
                    getline(cin, ced);
                    stringstream mystream(ced);
                    if(mystream >> i) break;
                    cout << "Cedula no valida. Solo se permiten numeros. Intente nuevamente.\n" << endl;
                }
                istringstream(ced)>>cedula;
                if(!validoCed(cedula))
                    cout << "Cedula no valida. Por favor compruebe el digito verificador y vuelva a intentarlo.\n" << endl;
            }while(!validoCed(cedula));
            return cedula;
}

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
        case 1:
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
                cout << "Supervisor cargado con cedula: " << s->getCedula() << endl;
            }
            else
            {
                cout << "Borrando datos..." << endl;
                system("PAUSE");
                system("cls");
            }
        }break;
        case 2:
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
            float sueldo;
            cin>>sueldo;
            cout << "Desea registrar un vendedor Zafral o Fijo? Z/F: ";
            char opcionReq2;
            cin >> opcionReq2;
            if (opcionReq2 == 'z' || opcionReq2 == 'Z')
            {
                int comision,dd,mm,aa;
                cout << "\nIngrese comision: ";
                cin >> comision;
                cout << "\nIngrese fecha fin de contrato" << endl;
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
                cout << "\nIngrese plus: ";
                int plu;
                cin >> plu;
                Vendedor * vend = new Fijo (plu, cedula, nombre, sueldo, 0, NULL);
                TipoError error;
                Fachada.registrarVendedor(vend,error,cedulaSupervisor);
                muestroError (error);
            }
            system("cls");
        }break;
//        case 3: //Listado de supervisores registrados. No se pide ningún orden para este listado.
//        {
//            system("cls");
//            cout << "3. Listar supervisores\n" << endl;
//            Fachada.listarSupervisoresCapa(Iterador);
//            while (Iterador.hayMasPersonas())
//            {
//                Persona * p = Iterador.proximaPersona();
//                cout <<p->getCedula() << " ";
//                ((Supervisor *) p)->getNombre().print();
//                ((Supervisor *) p)->getBarrio().print();
//                cout <<((Supervisor *) p)->getManzanas() << " ";
//            }
//        }break;

        case 3: //Listado de supervisores registrados. No se pide ningún orden para este listado.
        {
            IteradorPersonas iteradorSupervisores = Fachada.listarSupervisoresCapa();
            if (iteradorSupervisores.hayMasPersonas())
            {
                system("PAUSE");
                while (iteradorSupervisores.hayMasPersonas())
                {
                    Persona * p = (Supervisor *) iteradorSupervisores.proximaPersona();
                    cout << p->getCedula() << " ";
                    ((Supervisor *) p)->getNombre().print();
                    ((Supervisor *) p)->getBarrio().print();
                    cout <<((Supervisor *) p)->getManzanas() << " ";
                }
            }
            else
                cout << "ERROR: No hay supervisores en el sistema." << endl;
        }
        break;

        case 4:
        {
            system("cls");
            cout << "4. Listar vendedores\n" << endl;
            IteradorPersonas iteradorVendedores = Fachada.listarVendedoresCapa();
            if (iteradorVendedores.hayMasPersonas())
            {
                system("PAUSE");
                while (iteradorVendedores.hayMasPersonas())
                {
                    Persona * p = iteradorVendedores.proximaPersona();
                    cout << p->getCedula() << " - ";
                    ((Vendedor *)p)->getNombre().print();
                    cout << " - ";
                    ((Vendedor *)p)->getTipo().print();
                }
            }
            else
                cout << "ERROR: No hay supervisores en el sistema." << endl;
        }break;
        case 5: //Dada la cedula de un vendedor, listar todos sus datos junto con los datos de su supervisor.
        {
            system("cls");
            cout << "5. Listar datos de un vendedor\n" << endl;
            cout << "Ingrese el Vendedor\n" << endl;

            cedula=nuevaCedula();
            Vendedor * v;
            if(Fachada.perteneceVendedor(cedula))
            {
                v=Fachada.obtengoVendedor(cedula);
                cout << "\nLos datos del Vendedor son: \n" << endl;
                cout << "Cedula: " << v->getCedula() << endl;
                cout << "Nombre: " ;
                v->getNombre().print();
                cout << "\nSueldo Base: " << v->getSueldoBase() <<endl;
                cout << "Cantidad de Ventas: " << v->getCantVentas() <<endl;
                if(v->getTipo()=="Zafral")
                {
                    Fecha f=((Zafral *)v)->getFecha();
                    cout << "Zafral\n" << endl;
                    cout << "Comision: " << ((Zafral *) v)->getComision() << endl;
                    f.mostrar();
                }
                else
                {
                    cout << "Fijo\n" << endl;
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
        case 6: //Dada la cédula de un vendedor, registrar la cantidad de ventas que realizó en la semana
        {
            system("cls");
            cout << "6. Registrar ventas semanales de un vendedor\n" << endl;
            cout << "Ingrese cedula de vendedor" << endl;
            cedula=nuevaCedula();

            cout << "Ingrese cantidad de ventas semanal: ";
            int ventas;
            cin >> ventas;
            Vendedor * v = Fachada.obtengoVendedor(cedula);
            TipoError error;
            Fachada.ventasSemanales(v, ventas, error);
            muestroError(error);
        }break;
        case 7:
        {
            system("cls");
            cout << "7. Calcular sueldos semanales\n" << endl;
            float totalSueldos = Fachada.calculoSueldoTotal();
            cout << "El total de sueldos a pagar en la semana es: $" << totalSueldos << endl;

        }break;
        case 8:
        {
            system("cls");
            cout << "8. Cantidad de vendedores zafrales por fecha\n" << endl;
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
               TipoError error;
               if (fz.esValida())
               {
                   int total = Fachada.cantContratadosHasta(fz, error);
                   cout << "Cantidad de Vendedores Zafrales: " << total << endl;
               }
               else
               {
                   cout << "Fecha incorrecta." << endl;
                   system("PAUSE");
                   break;
               }
               muestroError(error);
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
