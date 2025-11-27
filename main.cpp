#include <iostream>
#include <cstdlib>
#include <cstring>

#include "supermercado.h"

#include "usuario.h"

using namespace std;

void menuInicial(Usuarios usuario){
    int opcion;
    bool valida = false;

    while(!valida){

        system("clear");
        cout << "1) SUPERMERCADO" << endl;
        cout << "2) PRODUCTOS" << endl;
        cout << "3) EXPORTAR    " << endl;
        cout << "9) BACK" << endl;

        cin >> opcion;

        switch(opcion){
            case 1:
                menuSupermercado(usuario);
                break;

            case 2:
                menuProductos(usuario);
                break;

            case 3:
                menuExportar();

                break;

            case 9:
                return;

            default:
                system("clear");
                cout << "ERROR: elija una opcion valida." <<  endl;
                waitForKey();
                break;

        }
    }
}



void CrearProvincia(){
    Provincias provincia_obj;
    ArchivoProvincias Archivo;
    int cantreg = Archivo.contarRegistros();


    char nombre[30];
    system("clear");
    cout << "INGRESE EL NOMBRE DE LA PROVINCIA: ";
    cargarCadena(nombre, 30);


    if (cantreg > 0) {
        Provincias ult_provincia= Archivo.leerRegistro(cantreg - 1);
        provincia_obj.setIdProvincia(ult_provincia.getIdProvincia() + 1);
    } else {
        provincia_obj.setIdProvincia(1);  // Asigno 1 si no existe otro supermercado
    }

    provincia_obj.setNombre(nombre);

    Archivo.grabarRegistro(provincia_obj);
    system("clear");
    cout << "Provincia " << provincia_obj.getNombre() << " generada correctamente." << endl;

}


void crearLocalidad(){
    Localidades localidad_obj;
    ArchivoLocalidades Archivo;
    Provincias provincia_obj = SeleccionarProvincias();

    int cantreg = Archivo.contarRegistros();
    char nombre[30];

    system("clear");
    cout << "LOCALIDADES: " << endl << endl;
    cout << "INGRESE EL NOMBRE DE LA LOCALIDAD: ";
    cargarCadena(nombre, 30);


    localidad_obj.setIdProvincia(provincia_obj.getIdProvincia());
    localidad_obj.setNombre(nombre);
    if (cantreg > 0) {
        Localidades ult_Localidad= Archivo.leerRegistro(cantreg - 1);
        localidad_obj.setIdLocalidad(ult_Localidad.getIdLocalidad() + 1);
    } else {
        localidad_obj.setIdLocalidad(1);  // Asigno 1 si no existe otro supermercado
    }

    Archivo.grabarRegistro(localidad_obj);

}


void CrearCategoria(){
    Categoria categoria_obj;
    ArchivoCategorias Archivo;

    int cantreg = Archivo.contarRegistros();
    char nombre[30];

    system("clear");
    cout << "CATEGORIAS: " <<  endl << endl;
    cout << "INGRESE EL NOMBRE: ";
    cargarCadena(nombre, 30);

    if(cantreg > 0){
        Categoria ultCategoria = Archivo.leerRegistro(cantreg - 1);
        categoria_obj.setIdCategoria(ultCategoria.getIdCategoria() + 1);
    }
    else{
        categoria_obj.setIdCategoria(1);
    }

    categoria_obj.setNombre(nombre);

    Archivo.grabarRegistro(categoria_obj);



}


void menuLogin(){

    bool valida = false;
    while (!valida){
        int opcion = 0;;

        system("clear");
        cout << "LOGIN" << endl << endl;
        cout << "1) USUARIO" << endl;

//        cout << "2) CREAR PROVINCIA" << endl;
//        cout << "3) CREAR LOCALIDAD" << endl;

        cout << "4) CREAR CATEGORIA" << endl;
        cout<<"9) EXIT "<<endl;


        cin >> opcion;

        if (opcion == 1){
            // logeo usuario
            Usuarios usuario = loginUsuario();
            if (usuario.getCorreo()[0] != '\0') {
                menuInicial(usuario);
            }
        }

//        else if(opcion == 2){
//            CrearProvincia();
//            waitForKey();
//
//        }
//        else if (opcion == 3){
//            crearLocalidad();
//            waitForKey();
//
//        }

        else if (opcion == 4){
            CrearCategoria();
        }
        else if (opcion==9){
            exit(-10);
        }

        else{
            system("clear");
            cout << "ERROR: elija una opcion valida." <<  endl;
            waitForKey();
        }
    }

}





int main()
{

    menuLogin();



    return 0;
}
