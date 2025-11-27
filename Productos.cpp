#include "Productos.h"
#include <cstring>

int Productos::getIdProducto()
{
    return id_producto;
}
const char* Productos::getNombre() const
{
    return nombre;
}
int Productos::getIdCategoria()
{
    return id_categoria;
}

void Productos::setIdProducto(int par_id)
{
    id_producto = par_id;
}
void Productos::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}
void Productos::setIdCategoria(int par_id)
{
    id_categoria = par_id;
}
