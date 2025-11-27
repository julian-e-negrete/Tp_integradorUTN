#ifndef USUARIOS_H
#define USUARIOS_H

#include <cstring>

class Usuarios
{
private:
    int id_usuario; // PK
    char nombre[30];
    char correo_electronico[30];
    char contrasena[30];

public:
    // Getters
    int getIdUsuario();
    const char* getNombre() const;
    const char* getCorreo() const;
    const char* getContrasena() const;

    // Setters
    void setIdUsuario(int par_id);
    void setNombre(const char* nom);
    void setCorreo(const char* par_correo);
    void setContrasena(const char* par_contrasena);

    void Cargar_N_Usuario();
    void MostrarUsuario();
};

Usuarios loginUsuario();
#endif // USUARIOS_H
