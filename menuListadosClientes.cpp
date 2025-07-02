#include <iostream>
using namespace std;
#include "ArchivoCliente.h"
#include "Cliente.h"
#include "Menu.h"

void Menu::menuListadoClientes(){
    ArchivoCliente archivoCliente("clientes.dat");
    Cliente registro;

    int cantRegistros = archivoCliente.CantidadRegistros_CL();
    for(int i = 0;i < cantRegistros;i++){
        registro = archivoCliente.Leer_CL(i);
        if(registro.getEstadoPersona()==true){
            cout << registro.toCSV() << endl;
        }
    }
}


