#include <string>
#pragma once

class Compra{
private:
    int _idCompra;
    float _totalCompra;
    bool _estadoCompra;
public:
    Compra();
    Compra(int idCompra, float totalCompra);

    int getIDCompra();
    float getTotalCompra();
    bool getEstadoCompra();

    void setIDCompra(int);
    void setTotalCompra(float);
    void setEstadoCompra(bool);

    void cargarCompra(int idCompra);
    std::string toCSV();
};
