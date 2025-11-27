#include "Productos.h"
#include <cstring>
#include "ArchivoSupermercado_Producto.h"
#include <iostream>

using namespace std;

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

void mostrarProducto(Productos producto_obj)
{
    ArchivoSupermercado_Producto Archivo;
    int cantreg = Archivo.contarRegistros();

    for (int i = 0; i < cantreg; i++)
    {
        Supermercado_Producto tempSuperProd = Archivo.leerRegistro(i);
        if(producto_obj.getIdProducto() == tempSuperProd.getIdProducto())
        {
            cout << producto_obj.getNombre() << ": $" << tempSuperProd.getPrecio() << endl;
        }
    }
}


