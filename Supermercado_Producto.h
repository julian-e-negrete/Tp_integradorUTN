#ifndef SUPERMERCADO_PRODUCTO_H
#define SUPERMERCADO_PRODUCTO_H

class Supermercado_Producto
{
private:
    int id_supermercado;
    int id_producto;
    float precio;

public:
    // GETTERS
    int getIdSupermercado();
    int getIdProducto();
    float getPrecio();

    // SETTERs
    void setIdSupermercado(int par_id);
    void setIdProducto(int par_id);
    void setPrecio(float par_precio);
};

#endif // SUPERMERCADO_PRODUCTO_H
