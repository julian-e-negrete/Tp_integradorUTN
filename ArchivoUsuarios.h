#ifndef ARCHIVOUSUARIOS_H
#define ARCHIVOUSUARIOS_H

#include "Usuarios.h"

class ArchivoUsuarios
{
private:
    char nombre[30];
public:
    ArchivoUsuarios(const char *n = "usuarios.dat");
    Usuarios leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Usuarios reg);
};

#endif // ARCHIVOUSUARIOS_H
