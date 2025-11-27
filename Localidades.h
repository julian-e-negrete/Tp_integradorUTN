#ifndef LOCALIDADES_H
#define LOCALIDADES_H

#include <cstring>

class Localidades
{
private:
    int id_localidad;
    int id_provincia;
    char nombre[30];

public:
    Localidades(int idlocalidad=-1);
    ~Localidades();

    int getIdLocalidad();
    int getIdProvincia();
    const char* getNombre() const;

    void setIdLocalidad (int par_id );
    void setIdProvincia (int par_id);
    void setNombre(const char* nom);
};

Localidades SeleccionarLocalidades(int id_provincia);
#endif // LOCALIDADES_H
