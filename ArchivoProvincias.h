#ifndef ARCHIVOPROVINCIAS_H
#define ARCHIVOPROVINCIAS_H

#include "Provincias.h"

class ArchivoProvincias
{
private:
    char nombre[30];
public:
    ArchivoProvincias(const char *n = "provincias.dat");
    Provincias leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Provincias reg);
};

#endif // ARCHIVOPROVINCIAS_H
