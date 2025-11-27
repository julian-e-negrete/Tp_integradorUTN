#ifndef FAVORITO_H_INCLUDED
#define FAVORITO_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include "clases.h"



void  AgregarFavorito(Usuarios User, int id_supermercado){

    ArchivoFavoritos Archivo;
    Favoritos favorito_obj;

    int cantreg = Archivo.contarRegistros();
    for(int i = 0; i < cantreg; i++){
        Favoritos tempFavorito = Archivo.leerRegistro(i);
        if((tempFavorito.getIdSupermercado() == id_supermercado) && (tempFavorito.getIdUsuario() == User.getIdUsuario() )){
            cout << "ERROR: SUPERMERCADO YA AGREGADO A FAVORITOS." << endl;
            waitForKey();
            return;
        }
    }

    int cantReg = Archivo.contarRegistros();
    if (cantReg > 0) {
        Favoritos Ult_favorito = Archivo.leerRegistro(cantReg - 1);
        favorito_obj.setIdFavorito(Ult_favorito.getIdFavorito() + 1);
    }
    else {
        favorito_obj.setIdFavorito(1);

    }
    favorito_obj.setIdUsuario(User.getIdUsuario());
    favorito_obj.setIdSupermercado(id_supermercado);
    Archivo.grabarRegistro(favorito_obj);

    system("clear");
    cout << "SUPERMERCADO AGREGADO A FAVORITOS." << endl;
    waitForKey();

}


#endif // FAVORITO_H_INCLUDED
