#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <cstring>
#include "Supermercados.h"
#include "Usuarios.h"

class Productos
{
private:
    int id_producto;
    char nombre[30];
    int id_categoria;

public:
    // GETTERS
    int getIdProducto();
    const char* getNombre() const;
    int getIdCategoria();

    // SETTERS
    void setIdProducto(int par_id);
    void setNombre(const char* nom);
    void setIdCategoria(int par_id);
};
void mostrarProducto(Productos producto_obj);


Productos SeleccionarProductos();

Productos CrearProductos(Supermercados supermercado_obj);

Productos BuscarNombreProducto();

Productos BuscarCategoria();

Productos BuscarPrecio();

Productos SeleccionarProducto_Supermercado(Supermercados supermercado_obj);

Productos BuscarProductos();

void menuProductos(Usuarios user);

void menuProductos_super(Usuarios user, Supermercados supermercado);

#endif // PRODUCTOS_H
