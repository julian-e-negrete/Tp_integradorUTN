#pragma once

class DetalleCompra{
private:
    int _idCompra_DC, _idProducto_DC, _cantidadProducto_DC;
    float _precioUnitario_DC;
public:
    DetalleCompra();
    DetalleCompra(int idCompra_DC, int idProducto_DC, int cantidadProducto_DC, float precioUnitario_DC);

    int getIDCompra_DC();
    int getIDProducto_DC();
    int getCantidadProducto_DC();
    float getPrecioUnitario_DC();

    void setIDCompra_DC(int);
    void setIDProducto_DC(int);
    void setCantidadProducto_DC(int);
    void setPrecioUnitario_DC(float);
};
