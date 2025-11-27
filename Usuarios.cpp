#include "Usuarios.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

int Usuarios::getIdUsuario()
{
    return id_usuario;
}
const char* Usuarios::getNombre() const
{
    return nombre;
}
const char* Usuarios::getCorreo() const
{
    return correo_electronico;
}
const char* Usuarios::getContrasena() const
{
    return contrasena;
}

void Usuarios::setIdUsuario(int par_id)
{
    id_usuario = par_id;
}
void Usuarios::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}
void Usuarios::setCorreo(const char* par_correo)
{
    strncpy(correo_electronico, par_correo, sizeof(correo_electronico));
    correo_electronico[sizeof(correo_electronico)-1] = '\0';
}
void Usuarios::setContrasena(const char* par_contrasena)
{
    strncpy(contrasena, par_contrasena, sizeof(contrasena));
    contrasena[sizeof(contrasena)-1] = '\0';
}

void Usuarios::Cargar_N_Usuario()
{
    cout << "INGRESE EL NOMBRE DEL USUARIO: " << endl;
    cargarCadena(nombre, 30);
    cout << "INGRESE EL CORREO ELECTRONICO: " << endl;
    cargarCadena(correo_electronico, 30);
    cout << "INGRESE LA CONTRASENA: " << endl;
    cargarCadena(contrasena, 30);
}

void Usuarios::MostrarUsuario()
{
    cout << "ID DEL USUARIO: " << id_usuario << endl;
    cout << "NOMBRE: " << nombre << endl;
    cout << "CORREO: " << correo_electronico << endl;
}
