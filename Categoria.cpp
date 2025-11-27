#include <iostream>
#include <cstdlib>

#include "Categoria.h"
#include "ArchivoCategorias.h"
#include "utils.h"

using namespace std;

Categoria::Categoria()
{
    id_categoria = 0;
}
Categoria::~Categoria(){}

int Categoria::getIdCategoria()
{
    return id_categoria;
}
const char* Categoria::getNombre() const
{
    return nombre;
}

void Categoria::setIdCategoria(int par_id)
{
    id_categoria = par_id;
}
void Categoria::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
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