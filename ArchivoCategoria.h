#include <string>
#include "Categoria.h"

class ArchivoCategoria{
private:
    std::string _nombreArchivo;
public:
    ArchivoCategoria(std::string nombreArchivo);
    bool Guardar_CA(Categoria categoria);
    bool Guardar_CA(Categoria categoria, int posicion);
    int Buscar_CA(int idCategoria);
    Categoria Leer_CA(int posicion);
    int CantidadRegistros_CA();
    void Leer_CA(int cantidadRegistros, Categoria *vector);
};

