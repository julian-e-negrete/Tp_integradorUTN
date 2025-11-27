#include "Supermercados.h"
#include "utils.h"
#include <iostream>

using namespace std;

Supermercados::Supermercados(int idsupermercado)
{
    id_supermercado=idsupermercado;
}
Supermercados::~Supermercados() {}

int Supermercados::getIdSupermercado()
{
    return id_supermercado;
}
const char* Supermercados::getNombre() const
{
    return nombre;
}
int Supermercados::getIdProvincia()
{
    return id_provincia;
}
int Supermercados::getIdLocalidad()
{
    return id_localidad;
}
const char* Supermercados::getDireccion() const
{
    return direccion;
}

void Supermercados::setIdSupermercado(int par_id)
{
    id_supermercado = par_id;
}

void Supermercados::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}
void Supermercados::setIdLocalidad(int par_local)
{
    id_localidad = par_local;
}
void Supermercados::setIdProvincia(int par_prov)
{
    id_provincia = par_prov;
}

void Supermercados::CargarSupermercados()
{
    cout << "INGRESE NOMBRE: " << endl;
    cargarCadena(nombre, 30);

    cout << "INGRESE DIRECCION: " << endl;
    cargarCadena(direccion, 30);

}
void Supermercados::Mostrar_Supermercado()
{
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"DIRECCION: "<<direccion<<endl;
}
