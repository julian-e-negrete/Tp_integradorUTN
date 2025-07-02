#include <string>
#include "Proveedores.h"

class ArchivoProveedores{
private:
    std::string _nombreArchivo;
public:
    ArchivoProveedores(std::string nombreArchivo);
    bool Guardar_PR(Proveedor proveedor);
    bool Guardar_PR(Proveedor proveedor, int posicion);
    int Buscar_PR(int idProveedor);
    Proveedor Leer_PR(int posicion);
    int CantidadRegistros_PR();
    void Leer_PR(int cantidadRegistros, Proveedor *vector);
};

