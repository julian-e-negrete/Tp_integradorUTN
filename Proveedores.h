#include <string>
#pragma once

class Proveedor{
private:
    int _idProveedor;
    char _nombreProveedor[20], _telefonoProveedor[20], _direccionProveedor[20], _mailProveedor[20];
    bool _estadoProveedor;

public:
    Proveedor();
    Proveedor(int idProveedor, char* nombreProveedor, char* telefonoProveedor, char* direccionProveedor, char* mailProveedor);

    int getIDProveedor();
    char* getNombreProveedor();
    char* getTelefonoProveedor();
    char* getDireccionProveedor();
    char* getMailProveedor();
    bool getEstadoProveedor();

    void setIDProveedor(int);
    void setNombreProveedor(char*);
    void setTelefonoProveedor(char*);
    void setDireccionProveedor(char*);
    void setMailProveedor(char*);
    void setEstadoProveedor(bool);

    std::string toCSV();
};
