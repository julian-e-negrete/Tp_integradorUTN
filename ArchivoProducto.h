#include <string>
#include "Producto.h"
#pragma once

class ArchivoProducto{
private:
    std::string _nombreArchivo;
public:
    ArchivoProducto(std::string nombreArchivo);
    bool Guardar_P(Producto producto);
    bool Guardar_P(Producto producto, int posicion);
    int Buscar_P(int idProducto);
    Producto Leer_P(int posicion);
    int CantidadRegistros_P();
    void Leer_P(int cantidadRegistros, Producto *vector);
};
