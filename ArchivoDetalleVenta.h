#include <string>
#include "DetalleVenta.h"

class ArchivoDetalleVenta{
private:
    std::string _nombreArchivo;
public:
    ArchivoDetalleVenta(std::string nombreArchivo);
    bool Guardar_DV(DetalleVenta detalleVenta);
    bool Guardar_DV(DetalleVenta detalleVenta, int posicion);
    int Buscar_DV(int idDetalleVenta);
    DetalleVenta Leer_DV(int posicion);
    int CantidadRegistros_DV();
    void Leer_DV(int cantidadRegistros, DetalleVenta *vector);
};

