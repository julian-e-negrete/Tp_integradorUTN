#ifndef COMPRAS_H
#define COMPRAS_H

#include "Usuarios.h"
#include "Supermercados.h"

class Compras {
private:
    int id_compra;
    int id_usuario;
    int id_supermercado;
    int id_producto;
    float precio;
    char fecha[11]; // YYYY-MM-DD

public:
    // getters
    int getIdCompra() const;
    int getIdUsuario() const;
    int getIdSupermercado() const;
    int getIdProducto() const;
    float getPrecio() const;
    const char* getFecha() const;

    // setters
    void setIdCompra(int id);
    void setIdUsuario(int id);
    void setIdSupermercado(int id);
    void setIdProducto(int id);
    void setPrecio(float p);
    void setFecha(const char *f);
};

void mostrarCompra(const Compras &c);

// agrega una compra para el usuario en el supermercado seleccionado
void registrarCompra(class Usuarios user, class Supermercados supermercado);

#endif // COMPRAS_H
