#include "Usuarios.h"
#include "utils.h"
#include <iostream>

#include "ArchivoUsuarios.h"

#include "Supermercados.h"

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




Usuarios loginUsuario() {
    ArchivoUsuarios Archivo;
    Usuarios usuario;
    bool loggedIn = false;

    while (!loggedIn) {

        system("clear");

        int opcion;
        cout << "1) Ingresar" << endl;
        cout << "2) Crear cuenta" << endl;
        cout << "9) EXIT" << endl;

        cin >> opcion;

        switch(opcion){

    case 1:
        {

           char correoElectronico[30], contrasena[30];
            system("clear");

            cout << "Correo electronico: ";
            cin >> correoElectronico;

            cout << "Contrasena: ";
            cin >> contrasena;

            int cantReg = Archivo.contarRegistros();

            for (int i = 0; i < cantReg; i++) {
                Usuarios tempUsuario = Archivo.leerRegistro(i);
                if ((strcmp(tempUsuario.getContrasena(), contrasena) == 0) && (strcmp(tempUsuario.getCorreo(), correoElectronico) == 0)) {
                    cout << "Usuario ingresado correctamente." << endl;
                    usuario = tempUsuario;
                    loggedIn = true;
                    waitForKey();
                    break;
                }
            }

            if (!loggedIn) {
                cout << "Error: No se ha encontrado ningun usuario con ese correo electronico y contrase�a." << endl;

                waitForKey();
            }

        break;

    }

    case 2:
        {
            Usuarios Ult_usuario;
            Usuarios tempUsuario;

            tempUsuario.Cargar_N_Usuario();
            int cantReg = Archivo.contarRegistros();
            if (cantReg > 0) {
                Ult_usuario = Archivo.leerRegistro(cantReg - 1);
                tempUsuario.setIdUsuario(Ult_usuario.getIdUsuario() + 1);
            }
            else {
                tempUsuario.setIdUsuario(1);
            }

            usuario = tempUsuario;
            Archivo.grabarRegistro(usuario);

            cout << "Usuario creado correctamente." << endl;
            loggedIn = true;
        break;

        }

    case 9:
            return Usuarios();
        break;

    default:
            system("clear");
            cout << "ERROR: elija una opcion valida." << endl;
            waitForKey();
            cin.ignore();
        break;

        }

    }

    return usuario;
}





