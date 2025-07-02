#include <string>
#pragma once

class Categoria{
private:
    int _idCategoria;
    std::string _nombreCategoria;
public:
    Categoria();
    Categoria(int idCategoria, std::string nombreCategoria);

    int getIDCategoria();
    std::string getNombreCategoria();

    void setIDCategoria(int);
    void setNombreCategoria(std::string);
};
