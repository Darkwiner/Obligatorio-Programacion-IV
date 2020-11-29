#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <sstream>
#include <iostream>
using namespace std;

bool validoCed (long int ced); //Valida que la cedula ingresada es correcta

long int nuevaCedula (); //Valida que la cedula este compuesta unicamente por numeros y llama al validoCed

int validarNum (); //Valida que se haya ingresado un numero entero

float validarFloat (); //Valida que se haya ingresado un numero float

#endif // VALIDACIONES_H_INCLUDED
