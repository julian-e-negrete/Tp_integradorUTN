#ifndef ARCHIVOFAVORITOS_H
#define ARCHIVOFAVORITOS_H

#include "Favoritos.h"

class ArchivoFavoritos
{
private:
    char nombre[30];
public:
    ArchivoFavoritos(const char *n = "favoritos.dat");
    Favoritos leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Favoritos reg);
};

#endif // ARCHIVOFAVORITOS_H
