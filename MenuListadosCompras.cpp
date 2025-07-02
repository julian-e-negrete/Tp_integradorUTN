#include <iostream>
using namespace std;
#include "ArchivoCompra.h"
#include "Compra.h"
#include "Menu.h"

void Menu::menuListadoCompras(){
    ArchivoCompra archivoCompra("compras.dat");
    Compra registro;

    int cantRegistros = archivoCompra.CantidadRegistros_C();
    for(int i = 0;i < cantRegistros;i++){
        registro = archivoCompra.Leer_C(i);
        if(registro.getEstadoCompra()==true){
            cout << registro.toCSV() << endl;
        }
    }
}

void Menu::menuListadoComprasxTotal(){
    ArchivoCompra archivoCompra("compras.dat");
    Compra registro;

    int cantRegistros = archivoCompra.CantidadRegistros_C();
    Compra* compras = new Compra[cantRegistros];

    for(int i = 0;i < cantRegistros;i++){
        registro = archivoCompra.Leer_C(i);
        if(registro.getEstadoCompra()==true){
            compras[i] = registro;
        }
    }

    for (int i = 0;i < cantRegistros-1;i++) {
        int maxTotal = i;
        for (int j = i+1;j <cantRegistros;j++) {
            if (compras[j].getTotalCompra() > compras[maxTotal].getTotalCompra()) {
                maxTotal = j;
            }
        }
        if (maxTotal!=i) {
            Compra productoAuxiliar = compras[i];
            compras[i] = compras[maxTotal];
            compras[maxTotal] = productoAuxiliar;
        }
    }

    for (int i = 0;i < cantRegistros;i++) {
        std::cout << compras[i].toCSV() << std::endl;
    }
    delete[] compras;
}
