#ifndef ARCHIVOLOCALIDADES_H
#define ARCHIVOLOCALIDADES_H

#include "Localidades.h"

class ArchivoLocalidades
{
private:
    char nombre[30];
public:
    ArchivoLocalidades(const char *n = "localidades.dat");
    Localidades leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Localidades reg);
};

#endif // ARCHIVOLOCALIDADES_H
