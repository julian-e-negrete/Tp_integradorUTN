#include "Supermercado_Producto.h"

int Supermercado_Producto::getIdSupermercado()
{
    return id_supermercado;
}
int Supermercado_Producto::getIdProducto()
{
    return id_producto;
}
float Supermercado_Producto::getPrecio ()
{
    return precio;
}

void Supermercado_Producto::setIdSupermercado(int par_id)
{
    id_supermercado = par_id;
}
void Supermercado_Producto::setIdProducto(int par_id)
{
    id_producto = par_id;
}
void Supermercado_Producto::setPrecio (float par_precio)
{
    precio = par_precio;
}
