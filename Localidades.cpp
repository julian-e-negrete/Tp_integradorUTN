#include "Localidades.h"
#include <cstring>
#include "ArchivoLocalidades.h"
#include "utils.h"

#include <iostream>


using namespace std;


Localidades::Localidades(int idlocalidad)
{
    id_localidad=idlocalidad;
}
Localidades::~Localidades() {}

int Localidades::getIdLocalidad()
{
    return id_localidad;
}
int Localidades::getIdProvincia()
{
    return id_provincia;
}
const char* Localidades::getNombre() const
{
    return nombre;
}

void Localidades::setIdLocalidad (int par_id )
{
    id_localidad = par_id;
}
void Localidades::setIdProvincia (int par_id)
{
    id_provincia = par_id;
}
void Localidades::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}



Localidades SeleccionarLocalidades(int id_provincia)
{
    Localidades localidades_obj;

    ArchivoLocalidades Archivo;

    int opcion;

    int cantreg = Archivo.contarRegistros();
    if (cantreg==-1)
    {
        cout<<"NO SE ENCUENTRAN LOCALIDADES DISPONIBLES"<<endl;
        waitForKey();
        return localidades_obj;
    }
    else
    {

        bool opcionValida = false;

        while(!opcionValida)
        {

            int contador=0;
            bool bandera=false;
            system("clear");
            for (int i = 0; i < cantreg; i++)
            {
                Localidades tempLocalidades = Archivo.leerRegistro(i);
                if(tempLocalidades.getIdProvincia() == id_provincia)
                {
                    if (bandera==false)
                    {
                        cout << "SELECCIONE UNA LOCALIDAD: " << endl << endl;
                        bandera=true;
                    }
                    cout << tempLocalidades.getIdLocalidad()<< ") -- " << tempLocalidades.getNombre() << endl;
                    contador++;
                }

            }
            if (contador==0)
            {
                system("clear");
                cout<<"NO SE ENCONTRARON LOCALIDADES REGISTRADAS PARA LA PROVINCIA SELECCIONADA"<<endl;
                waitForKey();
                return Localidades();
            }
            else
            {
                Localidades *vec;
                vec = new Localidades [contador];

                if (vec==nullptr)
                {
                    cout<<"NO SE PUDO ASIGNAR LOS RECURSOS NECESARIOS PARA EL PROCESO, CONTACTARSE CON SOPORTE:"<<endl<<" sofia.campos@alumnos.frgp.utn.edu.ar o con julian.negrete@alumnos.frgp.utn.edu.ar"<<endl;
                    waitForKey();
                    exit(-240);
                }
                else
                {
                    int asignar=0;
                    for (int i = 0; i < cantreg; i++)
                    {
                        Localidades tempLocalidades = Archivo.leerRegistro(i);
                        if(tempLocalidades.getIdProvincia() == id_provincia)
                        {
                            vec[asignar++]=tempLocalidades.getIdLocalidad();
                        }

                    }
                    cout<<endl;
                    cout<<"INGRESE SU ELECCION:"<<endl;
                    cin >> opcion;
                    if ((opcion > cantreg) || (opcion<0))
                    {
                        system("clear");
                        cout << "ERROR: Por favor seleccione una opcion valida." <<  endl;
                        waitForKey();

                    }
                    else
                    {
                        for (int i=0; i<contador; i++)
                        {
                            if (opcion==vec[i].getIdLocalidad())
                            {
                                localidades_obj = Archivo.leerRegistro(opcion-1);
                                opcionValida = true;
                                waitForKey();

                                break;
                            }
                            else if (i==contador-1)
                            {
                                system("clear");
                                cout << "ERROR: Por favor seleccione una opcion valida." <<  endl;
                                waitForKey();
                            }
                        }

                    }

                    delete[]vec;
                }
            }
        }

    }

    return localidades_obj;


}
