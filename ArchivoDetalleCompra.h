#include <string>
#include "DetalleCompra.h"

class ArchivoDetalleCompra{
private:
    std::string _nombreArchivo;
public:
    ArchivoDetalleCompra(std::string nombreArchivo);
    bool Guardar_DC(DetalleCompra detalleCompra);
    bool Guardar_DC(DetalleCompra detalleCompra, int posicion);
    int Buscar_DC(int idDetalleCompra);
    DetalleCompra Leer_DC(int posicion);
    int CantidadRegistros_DC();
    void Leer_DC(int cantidadRegistros, DetalleCompra *vector);
};
