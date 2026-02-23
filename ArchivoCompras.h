#ifndef ARCHIVOCOMPRAS_H
#define ARCHIVOCOMPRAS_H

#include "Compras.h"

class ArchivoCompras {
private:
    char nombre[30];
public:
    ArchivoCompras(const char *n = "compras.dat");
    Compras leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Compras reg);
};

#endif // ARCHIVOCOMPRAS_H
