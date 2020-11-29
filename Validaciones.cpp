#include "Validaciones.h"

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

int validarNum ()
{
            int i;
            string num;
            int numero;
            while(true)
            {
                getline(cin, num);
                stringstream mystream(num);
                if(mystream >> i) break;
                cout << "Entrada no valida. Solo se permiten numeros. \nIntente nuevamente: ";
            }
            istringstream(num)>>numero;
            return numero;
}

float validarFloat ()
{
            int i;
            string num;
            float numero;
            while(true)
            {
                getline(cin, num);
                stringstream mystream(num);
                if(mystream >> i) break;
                cout << "Entrada no valida. Solo se permiten numeros. \nIntente nuevamente: ";
            }
            istringstream(num)>>numero;
            return numero;
}
