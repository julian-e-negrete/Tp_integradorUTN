#include "Categoria.h"

Categoria::Categoria(){
    _idCategoria = 0;
    _nombreCategoria = " ";
}

Categoria::Categoria(int idCategoria, std::string nombreCategoria){
    _idCategoria = idCategoria;
    _nombreCategoria = nombreCategoria;
}

//GETTERS
int Categoria::getIDCategoria(){
    return _idCategoria;
}
std::string Categoria::getNombreCategoria(){
    return _nombreCategoria;
}

//SETTERS
void Categoria::setIDCategoria(int idCategoria){
    _idCategoria = idCategoria;
}
void Categoria::setNombreCategoria(std::string nombreCategoria){
    _nombreCategoria = nombreCategoria;
}

