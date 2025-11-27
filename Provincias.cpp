#include "Provincias.h"
#include "ArchivoProvincias.h"
#include "utils.h"

#include <iostream>

using namespace std;

Provincias::Provincias(int idprovincia)
{
    id_provincia=idprovincia;
}
Provincias::~Provincias() {}

int Provincias::getIdProvincia()
{
    return id_provincia;
}
const char* Provincias::getNombre() const
{
    return nombre;
}

void Provincias::setIdProvincia(int par_id)
{
    id_provincia = par_id;
}
void Provincias::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}



Provincias SeleccionarProvincias()
{
    Provincias provincia_obj;

    ArchivoProvincias Archivo;

    int opcion;

    int cantreg=0;
    cantreg = Archivo.contarRegistros();

    if (cantreg<1)
    {
        cout<<"NO SE ENCUENTRAN PROVINCIAS REGISTRADAS"<<endl;
        waitForKey();
        return provincia_obj;
    }
    else
    {

        bool opcionValida = false;

        while(!opcionValida)
        {
            int contador=0;
                system("clear");
                cout << "SELECCIONE UNA PROVINCIA: " << endl << endl;
            for (int i = 0; i < cantreg; i++)
            {
                Provincias tempProvincia = Archivo.leerRegistro(i);
                cout << i << ") -- " << tempProvincia.getNombre() << endl;
                contador++;
            }
            cout<<contador<<") BACK"<<endl;
            cin >> opcion;

            if (opcion==contador)
            {
                return Provincias();
            }
            else if (opcion > cantreg-1)
            {
                system("clear");
                cout << "ERROR: Por favor seleccione una opcion valida." <<  endl;
                waitForKey();

            }
            else
            {
                provincia_obj = Archivo.leerRegistro(opcion);
                opcionValida = true;
                return provincia_obj;
            }

        }

    }

    return provincia_obj;


}