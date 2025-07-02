#include <string>
#pragma once

class Venta{
private:
    int _idVenta, _idCliente;
    float _totalVenta;
    bool _estadoVenta;
public:
    Venta();
    Venta(int idVenta, int idCliente, float totalVenta);

    int getIDVenta();
    int getIDCliente();
    float getTotalVenta();
    bool getEstadoVenta();

    void setIDVenta(int);
    void setIDCliente(int);
    void setTotalVenta(float);
    void setEstadoVenta(bool);

    void cargarVenta(int idVenta);
    std::string toCSV();
};
