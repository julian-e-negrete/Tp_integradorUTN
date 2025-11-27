#include "Localidades.h"
#include <cstring>

Localidades::Localidades(int idlocalidad)
{
    id_localidad=idlocalidad;
}
Localidades::~Localidades() {}

int Localidades::getIdLocalidad()
{
    return id_localidad;
}
int Localidades::getIdProvincia()
{
    return id_provincia;
}
const char* Localidades::getNombre() const
{
    return nombre;
}

void Localidades::setIdLocalidad (int par_id )
{
    id_localidad = par_id;
}
void Localidades::setIdProvincia (int par_id)
{
    id_provincia = par_id;
}
void Localidades::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}
