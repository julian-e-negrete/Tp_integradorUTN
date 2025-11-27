#ifndef ARCHIVOCATEGORIAS_H
#define ARCHIVOCATEGORIAS_H

#include "Categoria.h"

class ArchivoCategorias
{
private:
    char nombre[30];
public:
    ArchivoCategorias(const char *n = "categorias.dat");
    Categoria leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Categoria reg);
};

#endif // ARCHIVOCATEGORIAS_H
