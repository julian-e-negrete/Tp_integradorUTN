#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <cstring>

class Categoria
{
private:
    int id_categoria;
    char nombre[30];

public:
    Categoria();
    ~Categoria();

    int getIdCategoria();
    const char* getNombre() const;

    void setIdCategoria(int par_id);
    void setNombre(const char* nom);
};

Categoria SeleccionarCategoria();

#endif // CATEGORIA_H
