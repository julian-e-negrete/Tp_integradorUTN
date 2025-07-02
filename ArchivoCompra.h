#include <string>
#include "Compra.h"
#pragma once

class ArchivoCompra{
private:
    std::string _nombreArchivo;
public:
    ArchivoCompra(std::string nombreArchivo);
    bool Guardar_C(Compra compra);
    bool Guardar_C(Compra compra, int posicion);
    int Buscar_C(int idCompra);
    Compra Leer_C(int posicion);
    int CantidadRegistros_C();
    void Leer_C(int cantidadRegistros, Compra *vector);
};
