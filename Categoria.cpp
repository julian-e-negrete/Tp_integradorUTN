#include "Categoria.h"

Categoria::Categoria()
{
    id_categoria = 0;
}
Categoria::~Categoria(){}

int Categoria::getIdCategoria()
{
    return id_categoria;
}
const char* Categoria::getNombre() const
{
    return nombre;
}

void Categoria::setIdCategoria(int par_id)
{
    id_categoria = par_id;
}
void Categoria::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}
