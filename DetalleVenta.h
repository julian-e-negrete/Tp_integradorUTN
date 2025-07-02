#pragma once

class DetalleVenta{
private:
    int _idVenta_DV, _idProducto_DV, _cantidadProducto_DV;
    float _precioUnitario_DV;
public:
    DetalleVenta();
    DetalleVenta(int idVenta_DV, int idProducto_DV, int cantidadProducto_DV, float precioUnitario_DV);

    int getIDVenta_DV();
    int getIDProducto_DV();
    int getCantidadProducto_DV();
    float getPrecioUnitario_DV();

    void setIDVenta_DV(int);
    void setIDProducto_DV(int);
    void setCantidadProducto_DV(int);
    void setPrecioUnitario(float);
};
