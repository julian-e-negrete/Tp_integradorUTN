#include "Proveedores.h"
#include <cstring>

// CONSTRUCTORES
Proveedor::Proveedor(){
    _idProveedor = 0;
    strcpy(_nombreProveedor, " ");
    strcpy(_telefonoProveedor, " ");
    strcpy(_direccionProveedor, " ");
    strcpy(_mailProveedor, " ");
    _estadoProveedor = true;
}

Proveedor::Proveedor(int idProveedor, char* nombreProveedor, char* telefonoProveedor, char* direccionProveedor, char* mailProveedor){
        _idProveedor = idProveedor;
        strcpy(_nombreProveedor, nombreProveedor);
        strcpy(_telefonoProveedor, telefonoProveedor);
        strcpy(_direccionProveedor, direccionProveedor);
        strcpy(_mailProveedor, mailProveedor);
        _estadoProveedor = true;
}

// GETTERS
int Proveedor::getIDProveedor(){
    return _idProveedor;
}
char* Proveedor::getNombreProveedor(){
    return _nombreProveedor;
}
char* Proveedor::getTelefonoProveedor(){
    return _telefonoProveedor;
}
char* Proveedor::getDireccionProveedor(){
    return _direccionProveedor;
}
char* Proveedor::getMailProveedor(){
    return _mailProveedor;
}
bool Proveedor::getEstadoProveedor(){
    return _estadoProveedor;
}

// SETTERS
void Proveedor::setIDProveedor(int idProveedor){
    _idProveedor = idProveedor;
}
void Proveedor::setNombreProveedor(char* nombreProveedor){
    strcpy(_nombreProveedor, nombreProveedor);
}
void Proveedor::setTelefonoProveedor(char* telefonoProveedor){
    strcpy(_telefonoProveedor, telefonoProveedor);
}
void Proveedor::setDireccionProveedor(char* direccionProveedor){
    strcpy(_direccionProveedor, direccionProveedor);
}
void Proveedor::setMailProveedor(char* mailProveedor){
    strcpy(_mailProveedor, mailProveedor);
}
void Proveedor::setEstadoProveedor(bool estadoProveedor){
    _estadoProveedor = estadoProveedor;
}

std::string Proveedor::toCSV(){

    std::string strProd = std::to_string((int)_idProveedor) + "," + _nombreProveedor + "," + _telefonoProveedor + "," + _direccionProveedor + "," + _mailProveedor;
    return strProd;
}
