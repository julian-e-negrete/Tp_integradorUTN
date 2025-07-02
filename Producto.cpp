#include <string>
#include <iostream>
#include <cstring>
#include "Producto.h"
using namespace std;

// CONSTRUCTORES
Producto::Producto(){
    _idProducto = 0;
    _idCategoria_P = 0;
    _cantidadProducto = 0;
    _idProveedor = 0;
    _precioUnitario = 0;
    strcpy(_nombreProducto, " ");
    _estadoProducto = true;
}

Producto::Producto(int idProducto, int idCategoria_P, int cantidadProducto, int idProveedor, float precioUnitario, char* nombreProducto){
    _idProducto = idProducto;
    _idCategoria_P = idCategoria_P;
    _cantidadProducto = cantidadProducto;
    _idProveedor = idProveedor;
    _precioUnitario = precioUnitario;
    strcpy(_nombreProducto, nombreProducto);
    _estadoProducto = true;
}

//GETTERS
int Producto::getIDProducto(){
    return _idProducto;
}
int Producto::getIDCategoria_P(){
    return _idCategoria_P;
}
int Producto::getCantidadProducto(){
    return _cantidadProducto;
}
int Producto::getIDProveedor(){
    return _idProveedor;
}
float Producto::getPrecioUnitario(){
    return _precioUnitario;
}
char* Producto::getNombreProducto(){
    return _nombreProducto;
}
bool Producto::getEstadoProducto(){
    return _estadoProducto;
}

//SETTERS
void Producto::setIDProducto(int idProducto){
    _idProducto = idProducto;
}
void Producto::setIDCategoria_P(int idCategoria_P){
    _idCategoria_P = idCategoria_P;
}
void Producto::setCantidadProducto(int cantidadProducto){
    _cantidadProducto = cantidadProducto;
}
void Producto::setIDProveedor(int idProveedor){
    _idProveedor = idProveedor;
}
void Producto::setPrecioUnitario(float precioUnitario){
    _precioUnitario = precioUnitario;
}
void Producto::setNombreProducto(char* nombreProducto){
    strcpy(_nombreProducto, nombreProducto);
}
void Producto::setEstadoProducto(bool estadoProducto){
    _estadoProducto = estadoProducto;
}

void Producto::cargarProducto(int idProducto){
    _idProducto = idProducto;
    cout << "ID de la categoria: ";
    cin >> _idCategoria_P;
    cout << "Stock del producto: ";
    cin >> _cantidadProducto;
    cout << "ID del proveedor: ";
    cin >>  _idProveedor;
    cout << "Precio unitario del producto: ";
    cin >> _precioUnitario;
    cout << "Nombre del producto: ";
    cin >> _nombreProducto;
    _estadoProducto = true;
}

std::string Producto::toCSV(){

    std::string strProd = std::to_string((int)_idProducto) + "," + std::to_string((int)_idCategoria_P) + "," + std::to_string((int)_cantidadProducto) + "," + std::to_string((int)_idProveedor) + "," + std::to_string((float)_precioUnitario) + "," +_nombreProducto;
    return strProd;
}
