#include "Provincias.h"

Provincias::Provincias(int idprovincia)
{
    id_provincia=idprovincia;
}
Provincias::~Provincias() {}

int Provincias::getIdProvincia()
{
    return id_provincia;
}
const char* Provincias::getNombre() const
{
    return nombre;
}

void Provincias::setIdProvincia(int par_id)
{
    id_provincia = par_id;
}
void Provincias::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}
