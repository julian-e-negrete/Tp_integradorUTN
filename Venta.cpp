#include "Venta.h"
#include <iostream>
using namespace std;

//CONSTRUCTORES
Venta::Venta(){
    _idVenta = 0;
    _idCliente = 0;
    _totalVenta = 0;
}

Venta::Venta(int idVenta, int idCliente, float totalVenta){
    _idVenta = idVenta;
    _idCliente = idCliente;
    _totalVenta = totalVenta;
}

//GETTERS
int Venta::getIDVenta(){
    return _idVenta;
}
int Venta::getIDCliente(){
    return _idCliente;
}
float Venta::getTotalVenta(){
    return _totalVenta;
}
bool Venta::getEstadoVenta(){
    return _estadoVenta;
}

//SETTERS
void Venta::setIDVenta(int idVenta){
    _idVenta = idVenta;
}
void Venta::setIDCliente(int idCliente){
    _idCliente = idCliente;
}
void Venta::setTotalVenta(float totalVenta){
    _totalVenta = totalVenta;
}
void Venta::setEstadoVenta(bool estadoVenta){
    _estadoVenta = estadoVenta;
}
void Venta::cargarVenta(int idVenta){
    _idVenta = idVenta;
    cout << "Ingrese el ID del cliente: ";
    cin >> _idCliente;
    cout << "Ingrese el total de la venta: ";
    cin >> _totalVenta;
    _estadoVenta = true;
}


std::string Venta::toCSV(){
    std::string strVenta = std::to_string((int)_idVenta) + "," + std::to_string((int)_idCliente) + "," + std::to_string((float)_totalVenta);
    return strVenta;
}

