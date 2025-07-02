#include <string>
#include "Cliente.h"
#pragma once

class ArchivoCliente{
private:
    std::string _nombreArchivo;
public:
    ArchivoCliente(std::string nombreArchivo);
    bool Guardar_CL(Cliente cliente);
    bool Guardar_CL(Cliente cliente, int posicion);
    int Buscar_CL(int idPersona);
    Cliente Leer_CL(int posicion);
    int CantidadRegistros_CL();
    void Leer_CL(int cantidadRegistros, Cliente *vector);
};
