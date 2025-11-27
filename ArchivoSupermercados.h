#ifndef ARCHIVOSUPERMERCADOS_H
#define ARCHIVOSUPERMERCADOS_H

#include "Supermercados.h"

class ArchivoSupermercados
{
private:
    char nombre[30];
public:
    ArchivoSupermercados(const char *n = "supermercados.dat");
    Supermercados leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Supermercados reg);
};

#endif // ARCHIVOSUPERMERCADOS_H
