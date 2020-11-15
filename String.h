#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <string.h>

class String
{
private:
    char * cadena;
public:
    String(); //Constructor por defecto.
    String(char* s); //Constructor común
    String(const String &); //Constructor de copia
    ~String(); //Destructor
    String operator=(const String &); //Sobrecarga de asignación
    bool operator==(String); //Compara dos strings por igualdad.
    bool operator< (String); //Compara dos strings alfabéticamente

#endif // STRING_H_INCLUDED
