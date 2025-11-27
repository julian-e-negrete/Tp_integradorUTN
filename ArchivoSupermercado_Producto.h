#ifndef ARCHIVOSUPERMERCADO_PRODUCTO_H
#define ARCHIVOSUPERMERCADO_PRODUCTO_H

#include "Supermercado_Producto.h"

class ArchivoSupermercado_Producto
{
private:
    char nombre[30];
public:
    ArchivoSupermercado_Producto(const char *n = "supermercado_producto.dat");
    Supermercado_Producto leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Supermercado_Producto reg);
};

#endif // ARCHIVOSUPERMERCADO_PRODUCTO_H
