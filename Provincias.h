#ifndef PROVINCIAS_H
#define PROVINCIAS_H

#include <cstring>

class Provincias
{
private:
    int id_provincia;
    char nombre[30];

public:
    Provincias(int idprovincia=-1);
    ~Provincias();

    int getIdProvincia();
    const char* getNombre() const;

    void setIdProvincia(int par_id);
    void setNombre(const char* nom);
};

Provincias SeleccionarProvincias();
#endif // PROVINCIAS_H
