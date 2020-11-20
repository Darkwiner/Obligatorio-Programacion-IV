#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <string.h>
#include <iostream>

using namespace std;

const int MAX = 80;

class String
{
private:
    char * cadena;
public:
    String(); //Constructor por defecto.
    String(char* s); //Constructor comun
    String(const String &); //Constructor de copia
    ~String(); //Destructor
    String operator=(const String &); //Sobrecarga de asignacion
    bool operator==(String); //Compara dos strings por igualdad.
    bool operator< (String); //Compara dos strings alfabaticamente
    String operator+ (String); //Concatenacion de strings.
    void scan(); //Lee un string desde la entrada estandar.
    void print(); //Muestra un string en la salida estandar
};
#endif // STRING_H_INCLUDED
