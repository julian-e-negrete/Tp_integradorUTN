#include <string>
#include "Venta.h"
#pragma once

class ArchivoVenta{
private:
    std::string _nombreArchivo;
public:
    ArchivoVenta(std::string nombreArchivo);
    bool Guardar_V(Venta venta);
    bool Guardar_V(Venta venta, int posicion);
    int Buscar_V(int idVenta);
    Venta Leer_V(int posicion);
    int CantidadRegistros_V();
    void Leer_V(int cantidadRegistros, Venta *vector);
};

