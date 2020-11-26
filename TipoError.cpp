#include "TipoError.h"

void muestroError (TipoPersona tipo)
{
    switch(tipo)
    {
    case FIJO :
        cout << "" << endl;
        system("PAUSE");
        system("cls");
        break;
    case ZAFRAL :
        break;
    case SUPERVISOR :
        break;
    }

void muestroError (TipoError error)
{
    switch(error)
    {
    case  CEDULANOVALIDA :
        cout << "ERROR: Cedula no valida. Compruebe el digito verificador y si el numero esta entre 500.000 y 7.000.000." << endl;
        system("PAUSE");
        system("cls");
        break;
    case NOMBRENOVALIDO :
        cout << "ERROR: Nombre no valido." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SUELDONOVALIDO :
        cout << "ERROR: Sueldo base no valido." << endl;
        system("PAUSE");
        system("cls");
        break;
    case CANTIDADVENTASNOVALIDA :
        cout << "ERROR: Cantidad de ventas no valida." << endl;
        system("PAUSE");
        system("cls");
        break;
    case MANZANASNOVALIDA :
        cout << "ERROR: Cantidad de manzanas no valida." << endl;
        system("PAUSE");
        system("cls");
        break;
    case COMISIONNOVALIDA :
        cout << "ERROR: Comision no valida." << endl;
        system("PAUSE");
        system("cls");
        break;
    case FECHANOVALIDA :
        cout << "ERROR: Fecha no valida." << endl;
        system("PAUSE");
        system("cls");
        break;
    case VENDEDORYAEXISTE :
        cout << "ERROR: Vendedor ya registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SUPERVISORYAEXISTE :
        cout << "ERROR: Supervisor ya registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SUPERVISORNOEXISTE :
        cout << "ERROR: Supervisor no registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SUPCARGADO :
        cout << "Supervisor registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case VENDCARGADO :
        cout << "Vendedor registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case VENDEDORNOEXISTE :
        cout << "ERROR: Vendedor no registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SETCANTIDADVENTAS :
        cout << "Cantidad de ventas cargadas correctamente." << endl;
        system("PAUSE");
        system("cls");
        break;
    }
}
