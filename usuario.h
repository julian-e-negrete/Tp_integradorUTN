#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>



#include "supermercado.h"

using namespace std;

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






#endif // USUARIO_H_INCLUDED
