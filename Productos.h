#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <cstring>

class Productos
{
private:
    int id_producto;
    char nombre[30];
    int id_categoria;

public:
    // GETTERS
    int getIdProducto();
    const char* getNombre() const;
    int getIdCategoria();

    // SETTERS
    void setIdProducto(int par_id);
    void setNombre(const char* nom);
    void setIdCategoria(int par_id);
};

#endif // PRODUCTOS_H
