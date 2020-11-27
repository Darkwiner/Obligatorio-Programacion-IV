#include "TipoError.h"

void muestroError (TipoError error)
{
    switch(error)
    {
    case  CEDULANOVALIDA :
        cout << "\nERROR: Cedula no valida. Compruebe el digito verificador y si el numero esta entre 500.000 y 7.000.000." << endl;
        system("PAUSE");
        system("cls");
        break;
    case NOMBRENOVALIDO :
        cout << "\nERROR: Nombre no valido." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SUELDONOVALIDO :
        cout << "\nERROR: Sueldo base no valido." << endl;
        system("PAUSE");
        system("cls");
        break;
    case CANTIDADVENTASNOVALIDA :
        cout << "\nERROR: Cantidad de ventas no valida." << endl;
        system("PAUSE");
        system("cls");
        break;
    case MANZANASNOVALIDA :
        cout << "\nERROR: Cantidad de manzanas no valida." << endl;
        system("PAUSE");
        system("cls");
        break;
    case COMISIONNOVALIDA :
        cout << "\nERROR: Comision no valida." << endl;
        system("PAUSE");
        system("cls");
        break;
    case FECHANOVALIDA :
        cout << "\nERROR: Fecha no valida." << endl;
        system("PAUSE");
        system("cls");
        break;
    case VENDEDORYAEXISTE :
        cout << "\nERROR: Vendedor ya registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SUPERVISORYAEXISTE :
        cout << "\nERROR: Supervisor ya registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SUPERVISORNOEXISTE :
        cout << "\nERROR: Supervisor no registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SUPCARGADO :
        cout << "\nSupervisor registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case VENDCARGADO :
        cout << "\nVendedor registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case VENDEDORNOEXISTE :
        cout << "\nERROR: Vendedor no registrado en el sistema." << endl;
        system("PAUSE");
        system("cls");
        break;
    case SETCANTIDADVENTAS :
        cout << "\nCantidad de ventas cargadas correctamente." << endl;
        system("PAUSE");
        system("cls");
        break;
    }
}
