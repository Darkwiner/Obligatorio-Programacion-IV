#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "String.h"
#include <iostream>

using namespace std;

const int MAX = 80;

class String
{
private:
    char * cadena;
public:
    String(); //Constructor por defecto.
    String(char* s); //Constructor com�n
    String(const String &); //Constructor de copia
    ~String(); //Destructor
    String operator=(const String &); //Sobrecarga de asignaci�n
    bool operator==(String); //Compara dos strings por igualdad.
    bool operator< (String); //Compara dos strings alfab�ticamente
    String operator+ (String); //Concatenaci�n de strings.
    void scan(); //Lee un string desde la entrada est�ndar.
    void print(); //Muestra un string en la salida est�ndar
};
#endif // STRING_H_INCLUDED
