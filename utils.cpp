#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <limits>

using namespace std;

void cargarCadena(char *pal, int tam)
{
    std::string tmp;
    std::getline(cin, tmp);
    if (tmp.size() == 0)
    {
        std::getline(cin, tmp);
    }
    // copiar hasta tam-1 caracteres y asegurar terminación nula
    strncpy(pal, tmp.c_str(), tam - 1);
    pal[tam - 1] = '\0';
}

void waitForKey(const char* msg)
{
    cout << msg;
    std::string tmp;
    std::getline(cin, tmp);
    if (tmp.size() == 0)
    {
        std::getline(cin, tmp);
    }
}

Categoria SeleccionarCategoria()
{
    Categoria categoria_obj;
    ArchivoCategorias Archivo;

    int cantreg=0;
    cantreg = Archivo.contarRegistros();

    if (cantreg<1)
    {

        cout<<"NO SE ENCUENTRAN CATEGORIAS REGISTRADAS"<<endl;
        waitForKey();

        return Categoria();
    }
    else
    {

        int opcion;

        bool valida = false;

        while(!valida)
        {
            int contador=0;
            bool encontrado = false;
            system("clear");
            cout << "SELECCIONE UNA CATEGORIA: " << endl  << endl;
            for(int i = 0; i < cantreg; i++)
            {
                Categoria tempCategoria = Archivo.leerRegistro(i);
                cout << tempCategoria.getIdCategoria() << ") -- " << tempCategoria.getNombre() << endl;
                encontrado = true;
                contador++;
            }

                    if(!encontrado)
            {
                system("clear");
                cout << "NO SE A ENCONTRADO NINGUNA CATEGORIA" << endl;
                waitForKey();
                return Categoria();
            }
            else if (encontrado==true)
            {
                cout<<endl;
                cout<<"INGRESE SU ELECCION:"<<endl;
                cin >> opcion;

                Categoria *vec;
                vec = new Categoria[contador];

                if (vec==nullptr)
                {
                    cout<<"NO SE PUDO ASIGNAR LOS RECURSOS NECESARIOS PARA EL PROCESO, CONTACTARSE CON SOPORTE:"<<endl<<" sofia.campos@alumnos.frgp.utn.edu.ar o con julian.negrete@alumnos.frgp.utn.edu.ar"<<endl;
                    waitForKey();
                    exit (-240);
                }
                else
                {
                    int asignar=0;
                    for(int i = 0; i < cantreg; i++)
                    {
                        Categoria tempCategoria = Archivo.leerRegistro(i);

                        vec[asignar++]=tempCategoria;

                    }

                    if ((opcion > cantreg) || (opcion<=0))
                    {
                        system("clear");
                        cout << "ERROR: ELIJA UNA OPCION VALIDA." << endl;
                        waitForKey();
                    }
                    else
                    {
                        for(int i = 0; i < contador; i++)
                        {
                            if (opcion==vec[i].getIdCategoria())
                            {
                                categoria_obj = Archivo.leerRegistro(opcion-1);
                                valida = true;

                            }
                        }
                    }
                }



            }
        }

        return categoria_obj;
    }

}


Supermercados SeleccionarSupermercado()
{
    Supermercados supermercado;

    ArchivoSupermercados Archivo;

    int opcion;

    int cantreg = Archivo.contarRegistros();
    bool opcionValida = false;

    bool encontrado = false;

    while(!opcionValida)
    {
    encontrado = false;
    system("clear");
        cout << "SELECCIONE UN SUPERMERCADO: " << endl << endl;
        for (int i = 0; i < cantreg; i++)
        {
            supermercado = Archivo.leerRegistro(i);
            cout << i << ") -- " << supermercado.getNombre() << endl;
            encontrado = true;
        }
        if(!encontrado)
        {
            system("clear");
            cout << "NO SE HA ENCONTRADO NINGUN SUPERMERCADO" << endl;
            waitForKey();
            return Supermercados();
        }
        cin >> opcion;

        if (opcion > cantreg-1)
        {
            system("clear");
            cout << "ERROR: Por favor seleccione una opcion valida." <<  endl;
            waitForKey();

        }
        else
        {
            supermercado = Archivo.leerRegistro(opcion);
            opcionValida = true;

        }

    }

    return supermercado;


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


void tolower_string(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void mostrarProducto(Productos producto_obj)
{
    ArchivoSupermercado_Producto Archivo;
    int cantreg = Archivo.contarRegistros();

    for (int i = 0; i < cantreg; i++)
    {
        Supermercado_Producto tempSuperProd = Archivo.leerRegistro(i);
        if(producto_obj.getIdProducto() == tempSuperProd.getIdProducto())
        {
            cout << producto_obj.getNombre() << ": $" << tempSuperProd.getPrecio() << endl;
        }
    }
}
