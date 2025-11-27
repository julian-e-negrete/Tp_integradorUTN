#ifndef SUPERMERCADOS_H
#define SUPERMERCADOS_H


#include <cstring>

#include "Usuarios.h"


class Supermercados
{
private:
    int id_supermercado;
    char nombre[30];
    int id_provincia;
    int id_localidad;
    char direccion[30];

public:
    Supermercados(int idsupermercado=-1);
    ~Supermercados();

    // GETTERS
    int getIdSupermercado();
    const char* getNombre() const;
    int getIdProvincia();
    int getIdLocalidad();
    const char* getDireccion() const;

    // SETTERS
    void setIdSupermercado(int par_id);
    void setNombre(const char* nom);
    void setIdLocalidad(int par_local);
    void setIdProvincia(int par_prov);

    void CargarSupermercados();
    void Mostrar_Supermercado();
};
Supermercados SeleccionarSupermercado();

Supermercados BuscarNombre();
Supermercados BuscarProvincia();
Supermercados BuscarLocalidad();
Supermercados BuscarSupermercado();
Supermercados favSupermercados(Usuarios user);
void menuSupermercado(Usuarios User);
#endif // SUPERMERCADOS_H
