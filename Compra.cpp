#include "Compra.h"
#include <iostream>
using namespace std;

//CONSTRUCTORES
Compra::Compra(){
    _idCompra = 0;
    _totalCompra = 0;
    _estadoCompra = true;
}

Compra::Compra(int idCompra, float totalCompra){
    _idCompra = idCompra;
    _totalCompra = totalCompra;
    _estadoCompra = true;
}

//GETTERS
int Compra::getIDCompra(){
    return _idCompra;
}
float Compra::getTotalCompra(){
    return _totalCompra;
}
bool Compra::getEstadoCompra(){
    return _estadoCompra;
}

//SETTERS
void Compra::setIDCompra(int idCompra){
    _idCompra = idCompra;
}
void Compra::setTotalCompra(float totalCompra){
    _totalCompra = totalCompra;
}
void Compra::setEstadoCompra(bool estadoCompra){
    _estadoCompra = estadoCompra;
}

void Compra::cargarCompra(int idCompra){
    _idCompra = idCompra;
    cout << "Ingrese el total de la compra: ";
    cin >> _totalCompra;
    _estadoCompra = true;
}

std::string Compra::toCSV(){
    std::string strCompra = std::to_string((int)_idCompra) + "," + std::to_string((float)_totalCompra);
    return strCompra;
}
