#include "DetalleVenta.h"

DetalleVenta::DetalleVenta(){
    _idVenta_DV = 0;
    _idProducto_DV = 0;
    _cantidadProducto_DV = 0;
    _precioUnitario_DV = 0;
}

DetalleVenta::DetalleVenta(int idVenta_DV, int idProducto_DV, int cantidadProducto_DV, float precioUnitario_DV){
    _idVenta_DV = idVenta_DV;
    _idProducto_DV = idProducto_DV;
    _cantidadProducto_DV = cantidadProducto_DV;
    _precioUnitario_DV = precioUnitario_DV;
}

//GETTERS
int DetalleVenta::getIDVenta_DV(){
    return _idVenta_DV;
}
int DetalleVenta::getIDProducto_DV(){
    return _idProducto_DV;
}
int DetalleVenta::getCantidadProducto_DV(){
    return _cantidadProducto_DV;
}
float DetalleVenta::getPrecioUnitario_DV(){
    return _precioUnitario_DV;
}

//SETTERS
void DetalleVenta::setIDVenta_DV(int idVenta_DV){
    _idVenta_DV = idVenta_DV;
}
void DetalleVenta::setIDProducto_DV(int idProducto_DV){
    _idProducto_DV = idProducto_DV;
}
void DetalleVenta::setCantidadProducto_DV(int cantidadProducto_DV){
    _cantidadProducto_DV = cantidadProducto_DV;
}
void DetalleVenta::setPrecioUnitario(float precioUnitario_DV){
    _precioUnitario_DV = precioUnitario_DV;
}
