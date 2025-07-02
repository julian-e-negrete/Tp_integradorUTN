#include <iostream>
using namespace std;
#include "ArchivoProveedores.h"
#include "Proveedores.h"
#include "Menu.h"

void Menu::menuListadoProveedores(){
    ArchivoProveedores archivoProveedor("proveedores.dat");
    Proveedor registro;

    int cantRegistros = archivoProveedor.CantidadRegistros_PR();
    for(int i = 0;i < cantRegistros;i++){
        registro = archivoProveedor.Leer_PR(i);
        if(registro.getEstadoProveedor()==true){
            cout << registro.toCSV() << endl;
        }
    }
}

