#include "DetalleCompra.h"

//CONSTRUCTORES
DetalleCompra::DetalleCompra(){
    _idCompra_DC = 0;
    _idProducto_DC = 0;
    _cantidadProducto_DC = 0;
    _precioUnitario_DC = 0;
}

DetalleCompra::DetalleCompra(int idCompra_DC, int idProducto_DC, int cantidadProducto_DC, float precioUnitario_DC){
    _idCompra_DC = idCompra_DC;
    _idProducto_DC = idProducto_DC;
    _cantidadProducto_DC = cantidadProducto_DC;
    _precioUnitario_DC = precioUnitario_DC;
}

//GETTERS
int DetalleCompra::getIDCompra_DC(){
    return _idCompra_DC;
}
int DetalleCompra::getIDProducto_DC(){
    return _idProducto_DC;
}
int DetalleCompra::getCantidadProducto_DC(){
    return _cantidadProducto_DC;
}
float DetalleCompra::getPrecioUnitario_DC(){
    return _precioUnitario_DC;
}

//SETTERS
void DetalleCompra::setIDCompra_DC(int idCompra_DC){
    _idCompra_DC = idCompra_DC;
}
void DetalleCompra::setIDProducto_DC(int idProducto_DC){
    _idProducto_DC = idProducto_DC;
}
void DetalleCompra::setCantidadProducto_DC(int cantidadProducto_DC){
    _cantidadProducto_DC = cantidadProducto_DC;
}
void DetalleCompra::setPrecioUnitario_DC(float precioUnitario_DC){
    _precioUnitario_DC = precioUnitario_DC;
}
