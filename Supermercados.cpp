#include "Supermercados.h"
#include "utils.h"
#include <iostream>

#include "ArchivoSupermercados.h"
#include "ArchivoProvincias.h"

#include "ArchivoLocalidades.h"
#include "Localidades.h"


#include "Usuarios.h"

#include "ArchivoFavoritos.h"
#include "Favoritos.h"

#include "Productos.h"

using namespace std;

Supermercados::Supermercados(int idsupermercado)
{
    id_supermercado=idsupermercado;
}
Supermercados::~Supermercados() {}

int Supermercados::getIdSupermercado()
{
    return id_supermercado;
}
const char* Supermercados::getNombre() const
{
    return nombre;
}
int Supermercados::getIdProvincia()
{
    return id_provincia;
}
int Supermercados::getIdLocalidad()
{
    return id_localidad;
}
const char* Supermercados::getDireccion() const
{
    return direccion;
}

void Supermercados::setIdSupermercado(int par_id)
{
    id_supermercado = par_id;
}

void Supermercados::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}
void Supermercados::setIdLocalidad(int par_local)
{
    id_localidad = par_local;
}
void Supermercados::setIdProvincia(int par_prov)
{
    id_provincia = par_prov;
}

void Supermercados::CargarSupermercados()
{
    cout << "INGRESE NOMBRE: " << endl;
    cargarCadena(nombre, 30);

    cout << "INGRESE DIRECCION: " << endl;
    cargarCadena(direccion, 30);

}
void Supermercados::Mostrar_Supermercado()
{
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"DIRECCION: "<<direccion<<endl;
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



Supermercados AgregarSupermercado()
{

    Supermercados new_Supermercado;
    Supermercados ult_Supermercado;

    ArchivoSupermercados Archivo;

    int cantReg = Archivo.contarRegistros();

    new_Supermercado.CargarSupermercados();

    ArchivoProvincias arch_provincias;
    ArchivoLocalidades arch_localidades;


    Provincias SelectProvincia = SeleccionarProvincias();
    Localidades tempLocalidad = SeleccionarLocalidades(SelectProvincia.getIdProvincia());

    new_Supermercado.setIdProvincia(SelectProvincia.getIdProvincia());
    new_Supermercado.setIdLocalidad(tempLocalidad.getIdLocalidad());

    if (cantReg > 0)
    {

        ult_Supermercado = Archivo.leerRegistro(cantReg - 1);
        new_Supermercado.setIdSupermercado(ult_Supermercado.getIdSupermercado() + 1);
    }
    else
    {
        new_Supermercado.setIdSupermercado(1);
    }

    bool escribio=Archivo.grabarRegistro(new_Supermercado);

    system("clear");
    if (escribio==true)
    {

        cout << "Supermercado creado correctamente." << endl;
        waitForKey();
    }



    return new_Supermercado;
}


Supermercados BuscarNombre()
{
    Supermercados supermercado;
    ArchivoSupermercados Archivo;
    char nombreSupermercado[50];
    int cantreg = Archivo.contarRegistros();
    int opcion;



    system("clear");
    cout << "SUPERMERCADO BUSQUEDA POR NOMBRE: " << endl << endl;
    cout << "INGRESE el nombre: ";
    cin>>nombreSupermercado;

    if(cantreg < 1)
    {
        cout << "NO SE HA ENCONTRADO NINGUN SUPERMERCADO." << endl;
        waitForKey();
        return Supermercados();
    }
    else
    {
        bool valida = false;
        bool encontro_coincidencia=false;
        while(!valida)
        {
            int contador=0;

            system("clear");
            cout << "SELECCIONE EL SUPERMERCADO: " << endl << endl;
            for(int i = 0; i < cantreg; i++)
            {
                char nombreSupermercado_obj[30];
                Supermercados tempSupermercado = Archivo.leerRegistro(i);


                strcpy(nombreSupermercado_obj, tempSupermercado.getNombre());

                tolower_string(nombreSupermercado);
                tolower_string(nombreSupermercado_obj);

                const char* encontrado = strstr(nombreSupermercado_obj, nombreSupermercado);


                if (encontrado!=nullptr)
                {
                    encontro_coincidencia=true;
                    cout << tempSupermercado.getIdSupermercado() << ") --- " << nombreSupermercado_obj << endl;
                    contador++;
                }
            }
            if (encontro_coincidencia==false)
            {
                system("clear");
                cout<<"NO SE ENCONTRARON SUPERMERCADOS QUE COINCIDAN CON EL TEXTO INGRESADO POR TECLADO"<<endl;
                waitForKey();
                return Supermercados();
            }
            else
            {
                int asignar=0;
                cout<<endl;
                cout<<"INGRESE SU ELECCION:"<<endl;


                Supermercados *vec;
                vec = new Supermercados [contador];
                if (vec==nullptr)
                {
                    cout<<"NO SE PUDO ASIGNAR LOS RECURSOS NECESARIOS PARA EL PROCESO, CONTACTARSE CON SOPORTE:"<<endl<<" sofia.campos@alumnos.frgp.utn.edu.ar o con julian.negrete@alumnos.frgp.utn.edu.ar"<<endl;
                    exit (-240);
                }
                else
                {
                    for(int i = 0; i < cantreg; i++)
                    {
                        char nombreSupermercado_obj[30];
                        Supermercados tempSupermercado = Archivo.leerRegistro(i);


                        strcpy(nombreSupermercado_obj, tempSupermercado.getNombre());

                        tolower_string(nombreSupermercado);
                        tolower_string(nombreSupermercado_obj);

                        const char* encontrado = strstr(nombreSupermercado_obj, nombreSupermercado);


                        if (encontrado!=nullptr)
                        {
                            encontro_coincidencia=true;
                            vec[asignar++]=tempSupermercado.getIdSupermercado();
                        }
                    }

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
                            if (opcion==vec[i].getIdSupermercado())
                            {
                                supermercado = Archivo.leerRegistro(opcion-1);
                                valida = true;
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

                    delete []vec;
                }
            }

        }

        return supermercado;

    }



}


Supermercados BuscarProvincia()
{
    Supermercados supermercado;
    ArchivoSupermercados Archivo;



    Provincias provincia_obj = SeleccionarProvincias();

    if (provincia_obj.getIdProvincia()==-1)
    {
        return Supermercados();
    }
    else
    {

        int cantreg = Archivo.contarRegistros();
        if(cantreg < 1)
        {
            cout << "NO SE HA ENCONTRADO NINGUNA PROVINCIA." << endl;
            waitForKey();
            return Supermercados();
        }

        else
        {
            int contador=0;
            bool opcionValida = false;
            while(!opcionValida)
            {
                system("clear");
                int opcion;
                cout << "SELECCIONE UN SUPERMERCADO: " << endl << endl;
                for (int i = 0; i < cantreg; i++)
                {
                    Supermercados temp_supermercado = Archivo.leerRegistro(i);
                    if(temp_supermercado.getIdProvincia() == provincia_obj.getIdProvincia())
                    {
                        cout << temp_supermercado.getIdSupermercado() << ") -- " << temp_supermercado.getNombre() << endl;
                        contador++;
                    }

                }

                if (contador<=0)
                {
                    system("clear");
                    cout<<"NO SE ENCONTRARON SUPERMERCADOS REGISTRADOS PARA LA PROVINCIA SELECCIONADA"<<endl;
                    waitForKey();
                    return Supermercados();
                }
                else
                {


                    if (contador>0)
                    {
                        ///Vector dinamico para poder validar las opciones a elegir comparando la eleccion del usuario
                        Supermercados *vec;
                        vec = new Supermercados [contador];
                        if (vec==nullptr)
                        {
                            cout<<"NO SE PUDO ASIGNAR LOS RECURSOS NECESARIOS PARA EL PROCESO, CONTACTARSE CON SOPORTE:"<<endl<<" sofia.campos@alumnos.frgp.utn.edu.ar o con julian.negrete@alumnos.frgp.utn.edu.ar"<<endl;
                            exit (-240);
                        }
                        else
                        {
                            int asignar=0;

                            for (int i = 0; i < cantreg; i++)
                            {
                                Supermercados temp_supermercado = Archivo.leerRegistro(i);
                                if(temp_supermercado.getIdProvincia() == provincia_obj.getIdProvincia())
                                {
                                    vec[asignar++]=temp_supermercado.getIdSupermercado();
                                }

                            }

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
                                    if (opcion==vec[i].getIdSupermercado())
                                    {
                                        supermercado = Archivo.leerRegistro(opcion-1);
                                        opcionValida = true;

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
            return supermercado;
        }

    }

}


Supermercados BuscarLocalidad()
{
    Supermercados supermercado;
    ArchivoSupermercados Archivo;

    Provincias provincia_obj = SeleccionarProvincias();
    if (provincia_obj.getIdProvincia()==-1)
    {
        return Supermercados();
    }
    Localidades localidad_obj = SeleccionarLocalidades(provincia_obj.getIdProvincia());

    if (localidad_obj.getIdLocalidad()==-1)
    {
        return Supermercados();
    }
    int cantreg = Archivo.contarRegistros();
    bool opcionValida = false;


    if(cantreg < 1)
    {
        cout << "NO SE HA ENCONTRADO NINGUN SUPERMERCADO EN LA LOCALIDAD SELECCIONADA." << endl;
        waitForKey();
        return Supermercados();
    }
    else
    {
        int contador=0;
        bool bandera=false;

        while(!opcionValida)
        {
            system("clear");
            int opcion;
            for (int i = 0; i < cantreg; i++)
            {
                Supermercados temp_supermercado = Archivo.leerRegistro(i);
                if((temp_supermercado.getIdProvincia() == provincia_obj.getIdProvincia()) && (temp_supermercado.getIdLocalidad() == localidad_obj.getIdLocalidad()))
                {
                    if (bandera==false)
                    {
                        cout << "SELECCIONE UN SUPERMERCADO: " << endl << endl;
                        bandera=true;
                    }
                    cout << temp_supermercado.getIdSupermercado() << ") -- " << temp_supermercado.getNombre() << endl;
                    contador++;
                }

            }
            if (contador==0)
            {

                system("clear");
                cout<<"NO SE ENCONTRARON SUPERMERCADOS REGISTRADOS PARA LA LOCALIDAD SELECCIONADA"<<endl;
                waitForKey();
                return Supermercados();
            }
            else if (contador>0)
            {
                Supermercados *vec;
                vec = new Supermercados [contador];
                if (vec==nullptr)
                {
                    cout<<"NO SE PUDO ASIGNAR LOS RECURSOS NECESARIOS PARA EL PROCESO, CONTACTARSE CON SOPORTE:"<<endl<<" sofia.campos@alumnos.frgp.utn.edu.ar o con julian.negrete@alumnos.frgp.utn.edu.ar"<<endl;
                    waitForKey();
                    exit (-240);
                }
                else
                {
                    int asignar=0;

                    for (int i = 0; i < cantreg; i++)
                    {
                        Supermercados temp_supermercado = Archivo.leerRegistro(i);
                        if((temp_supermercado.getIdProvincia()) == (provincia_obj.getIdProvincia()) && (temp_supermercado.getIdLocalidad()==localidad_obj.getIdLocalidad()))
                        {
                            vec[asignar++]=temp_supermercado.getIdSupermercado();
                        }

                    }
                    cout<<endl;
                    cout<<"INGRESE SU ELECCION"<<endl;
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
                            if (opcion==vec[i].getIdSupermercado())
                            {
                                supermercado = Archivo.leerRegistro(opcion-1);
                                opcionValida = true;

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
        return  supermercado;
    }





}


Supermercados BuscarSupermercado()
{

    Supermercados supermercado;

    ArchivoSupermercados Archivo;

    int opcion;

    system("clear");

    cout << "SUPERMERCADO BUSQUEDA: " << endl << endl;
    cout << "1) NOMBRE " << endl;
    cout << "2) PROVINCIA " << endl;
    cout << "3) LOCALIDAD " << endl;
    cout << "9) BACK" << endl;

    cin >> opcion;
    bool valida = false;

    while(!valida)
    {

        switch(opcion)
        {

        case 1:
            supermercado = BuscarNombre();
            if (supermercado.getIdSupermercado()==-1)
            {
                valida=true;
                break;
            }
            valida = true;
            break;

        case 2:
            supermercado = BuscarProvincia();

            if (supermercado.getIdSupermercado()==-1)
            {
                valida=true;
                break;
            }

            valida = true;
            break;

        case 3:
            supermercado = BuscarLocalidad();
            valida = true;
            break;
        case 9:
            return Supermercados();

        default:
            system("clear");
            cout << "ERROR: elija una opcion valida." <<  endl;
            waitForKey();
            break;


        }

        return supermercado;

    }

    return Supermercados();

    }


Supermercados favSupermercados(Usuarios user)
{

    ArchivoFavoritos Archivo;

    ArchivoSupermercados Archivo_supermercado;
    Supermercados supermercado_obj;

    int cantreg = Archivo.contarRegistros();
    int cantreg_super = Archivo_supermercado.contarRegistros();
    if(cantreg < 1)
    {
        cout << "NO SE HA ENCONTRADO NINGUN SUPERMERCADO." << endl;
        waitForKey();
        return Supermercados();
    }
    else
    {

        bool valida = false;

        while(!valida)
        {

            int opcion;
            int contador=0;
            system("clear");
            cout << "FAVORITOS SELECCIONAR SUPERMERCADO: " << endl << endl;

            for(int i = 0; i < cantreg; i++)
            {

                Favoritos tempFavorito = Archivo.leerRegistro(i);
                if(tempFavorito.getIdUsuario() == user.getIdUsuario() )
                {

                    for(int j = 0; j < cantreg_super; j++)
                    {

                        Supermercados tempSuper = Archivo_supermercado.leerRegistro(j);
                        if(tempFavorito.getIdSupermercado() == tempSuper.getIdSupermercado())
                        {
                            cout << tempSuper.getIdSupermercado() << ") -- " << tempSuper.getNombre() << endl;
                            contador++;
                        }
                    }

                }
            }

            if (contador>0)
            {
                Supermercados *vec;
                vec = new Supermercados [contador];

                if (vec==nullptr)
                {
                    cout<<"NO SE PUDO ASIGNAR LOS RECURSOS NECESARIOS PARA EL PROCESO, CONTACTARSE CON SOPORTE:"<<endl<<"  julian.negrete@alumnos.frgp.utn.edu.ar"<<endl;
                    waitForKey();
                    exit (-240);
                }
                else
                {
                    int asignar=0;
                    for(int i = 0; i < cantreg; i++)
                    {

                        Favoritos tempFavorito = Archivo.leerRegistro(i);
                        if(tempFavorito.getIdUsuario() == user.getIdUsuario() )
                        {

                            for(int j = 0; j < cantreg_super; j++)
                            {

                                Supermercados tempSuper = Archivo_supermercado.leerRegistro(j);
                                if(tempFavorito.getIdSupermercado() == tempSuper.getIdSupermercado())
                                {
                                   vec[asignar++]=tempSuper.getIdSupermercado();
                                }
                            }

                        }
                    }
                    cout<<endl;
                    cout<<"INGRESE SU ELECCION:"<<endl;
                    cin >> opcion;

                    if(opcion > cantreg_super || opcion < 1 )
                    {
                        system("clear");
                        cout << "ERROR: ELIJA UNA OPCION VALIDA." << endl;
                        waitForKey();
                    }
                    else
                    {

                            for(int i = 0; i < cantreg; i++)
                            {

                                Favoritos tempFavorito = Archivo.leerRegistro(i);
                                if(tempFavorito.getIdUsuario() == user.getIdUsuario() )
                                {

                                    for(int j = 0; j < cantreg_super; j++)
                                    {

                                        Supermercados tempSuper = Archivo_supermercado.leerRegistro(j);
                                        if(tempFavorito.getIdSupermercado() == tempSuper.getIdSupermercado())
                                        {
                                           if (opcion==vec[i].getIdSupermercado()){
                                                supermercado_obj = Archivo_supermercado.leerRegistro(opcion-1);
                                                valida = true;

                                           }
                                           else if (i==contador-1){
                                            system("clear");
                                            cout << "ERROR: Por favor seleccione una opcion valida." <<  endl;
                                            waitForKey();
                                           }
                                        }
                                    }

                                }
                            }



                    }
                    delete[]vec;
                }
            }



        }

    return supermercado_obj;
    }





}


void menuSupermercado(Usuarios User)
{

    int opcion;
    bool valida = false;
    Supermercados supermercado_obj;

    while(!valida)
    {

        system("clear");
        cout << "SUPERMERCADOS" << endl << endl;

        cout << "1) SELECCIONAR" << endl;
        cout << "2) AGREGAR" << endl;
        cout << "3) BUSCAR" << endl;
        cout << "4) FAVORITOS" << endl;
        cout << "9) BACK" << endl;
        cin >> opcion;

        switch(opcion)
        {

        case 1:
            supermercado_obj = SeleccionarSupermercado();
            cout << "Se selecciono el supermercado: " << supermercado_obj.getNombre() << endl;
            waitForKey();
            valida = true;
            break;



        case 2:
            supermercado_obj = AgregarSupermercado();
            cout << "Se creo el supermercado: " << supermercado_obj.getNombre() << endl;
            waitForKey();
            valida = true;
            break;


        case 3:
            supermercado_obj = BuscarSupermercado();

            if (supermercado_obj.getIdSupermercado() == -1)
            {
                break;
            }
            valida = true;
            break;

        case 4:
            supermercado_obj = favSupermercados(User);
            if (supermercado_obj.getIdSupermercado()>0)
            {
                valida = true;
            }
            break;

        case 9:
            return;

        default:
            system("clear");
            cout << "ERROR: elija una opcion valida." <<  endl;
            waitForKey();
            break;
        }

        if (valida)
        {
            menuProductos_super(User, supermercado_obj);
            valida = false;
        }


    }

}
