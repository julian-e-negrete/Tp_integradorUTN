#ifndef ARCHIVOPRODUCTOS_H
#define ARCHIVOPRODUCTOS_H

#include "Productos.h"

class ArchivoProductos
{
private:
    char nombre[30];
public:
    ArchivoProductos(const char *n = "productos.dat");
    Productos leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Productos reg);
};

#endif // ARCHIVOPRODUCTOS_H
