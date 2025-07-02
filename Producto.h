#include <string>
#pragma once

class Producto{
private:
    int _idProducto, _idCategoria_P, _cantidadProducto, _idProveedor;
    float _precioUnitario;
    char _nombreProducto[20];
    bool _estadoProducto;
public:
    Producto();
    Producto(int idProducto, int idCategoria_P, int cantidadProducto, int idProveedor, float precioUnitario, char* nombreProducto);

    int getIDProducto();
    int getIDCategoria_P();
    int getCantidadProducto();
    int getIDProveedor();
    float getPrecioUnitario();
    char* getNombreProducto();
    bool getEstadoProducto();

    void setIDProducto(int);
    void setIDCategoria_P(int);
    void setCantidadProducto(int);
    void setIDProveedor(int);
    void setPrecioUnitario(float);
    void setNombreProducto(char*);
    void setEstadoProducto(bool);

    void cargarProducto(int idProducto);
    std::string toCSV();
};
