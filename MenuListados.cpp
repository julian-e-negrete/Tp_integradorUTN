#include <iostream>
using namespace std;
#include "ArchivoProducto.h"
#include "Producto.h"
#include "Menu.h"

void Menu::menuListadoProductos(){
    ArchivoProducto archivoProducto("productos.dat");
    Producto registro;

    int cantRegistros = archivoProducto.CantidadRegistros_P();
    for(int i = 0;i < cantRegistros;i++){
        registro = archivoProducto.Leer_P(i);
        if(registro.getEstadoProducto()==true){
            cout << registro.toCSV() << endl;
        }
    }
}

void Menu::menuListadoPxCategoria(){
    ArchivoProducto archivoProducto("productos.dat");
    Producto registro;
    int maxCategoria = 1;
    int cantRegistros = archivoProducto.CantidadRegistros_P();

    for(int i = 0;i < cantRegistros;i++){
        registro = archivoProducto.Leer_P(i);
        if(registro.getEstadoProducto()==true){
            if(registro.getIDCategoria_P()>maxCategoria){
                maxCategoria = registro.getIDCategoria_P();
            }
        }
    }

    for (int j = 1; j <= maxCategoria; j++) {
        bool contieneProductos = false;
        for (int i = 0; i < cantRegistros; i++) {
            registro = archivoProducto.Leer_P(i);
            if (registro.getEstadoProducto() && registro.getIDCategoria_P() == j) {
                contieneProductos = true;
                break;
            }
        }
        if(contieneProductos==true){
            cout << endl << "Categoria " << j << ":" << endl;
            for (int i = 0; i < cantRegistros; i++) {
                registro = archivoProducto.Leer_P(i);
                if (registro.getEstadoProducto() && registro.getIDCategoria_P() == j) {
                    cout << registro.toCSV() << endl;
                }
            }
        }

    }
}

void Menu::menuListadoPxProveedor(){
    ArchivoProducto archivoProducto("productos.dat");
    Producto registro;
    int maxIDProveedor = 1;
    int cantRegistros = archivoProducto.CantidadRegistros_P();

    for(int i = 0;i < cantRegistros;i++){
        registro = archivoProducto.Leer_P(i);
        if(registro.getEstadoProducto()==true){
            if(registro.getIDCategoria_P()>maxIDProveedor){
                maxIDProveedor = registro.getIDProveedor();
            }
        }
    }

    for (int j = 1; j <= maxIDProveedor; j++) {
        bool contieneProductos = false;
        for (int i = 0; i < cantRegistros; i++) {
            registro = archivoProducto.Leer_P(i);
            if (registro.getEstadoProducto() && registro.getIDProveedor() == j) {
                contieneProductos = true;
                break;
            }
        }
        if(contieneProductos==true){
            cout << endl << "Proveedor " << j << ":" << endl;
            for (int i = 0; i < cantRegistros; i++) {
                registro = archivoProducto.Leer_P(i);
                if (registro.getEstadoProducto() && registro.getIDProveedor() == j) {
                    cout << registro.toCSV() << endl;
                }
            }
        }

    }
}
