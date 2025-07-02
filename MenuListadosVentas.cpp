#include <iostream>
using namespace std;
#include "ArchivoVenta.h"
#include "Venta.h"
#include "Menu.h"

void Menu::menuListadoVentas(){
    ArchivoVenta archivoVenta("ventas.dat");
    Venta registro;

    int cantRegistros = archivoVenta.CantidadRegistros_V();
    for(int i = 0;i < cantRegistros;i++){
        registro = archivoVenta.Leer_V(i);
        if(registro.getEstadoVenta()==true){
            cout << registro.toCSV() << endl;
        }
    }
}

void Menu::menuListadoVentasxTotal(){
    ArchivoVenta archivoVenta("ventas.dat");
    Venta registro;

    int cantRegistros = archivoVenta.CantidadRegistros_V();
    Venta* ventas = new Venta[cantRegistros];

    for(int i = 0;i < cantRegistros;i++){
        registro = archivoVenta.Leer_V(i);
        if(registro.getEstadoVenta()==true){
            ventas[i] = registro;
        }
    }

    for (int i = 0;i < cantRegistros-1;i++) {
        int maxTotal = i;
        for (int j = i+1;j <cantRegistros;j++) {
            if (ventas[j].getTotalVenta() > ventas[maxTotal].getTotalVenta()) {
                maxTotal = j;
            }
        }
        if (maxTotal!=i) {
            Venta productoAuxiliar = ventas[i];
            ventas[i] = ventas[maxTotal];
            ventas[maxTotal] = productoAuxiliar;
        }
    }

    for (int i = 0;i < cantRegistros;i++) {
        std::cout << ventas[i].toCSV() << std::endl;
    }
    delete[] ventas;
}
