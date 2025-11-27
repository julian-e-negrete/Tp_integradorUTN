#ifndef PROYECTO_H
#define PROYECTO_H

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

void waitForKey(const char* msg = "Presione ENTER para continuar...")
{
    cout << msg;
    std::string tmp;
    std::getline(cin, tmp);
    if (tmp.size() == 0)
    {
        std::getline(cin, tmp);
    }
}

// completa
class Usuarios
{
private:
    int id_usuario; // PK
    char nombre[30];
    char correo_electronico[30];
    char contrasena[30];

public:
    // Getters
    int getIdUsuario()
    {
        return id_usuario;
    }
    const char* getNombre() const
    {
        return nombre;
    }
    const char* getCorreo() const
    {
        return correo_electronico;
    }
    const char* getContrasena() const
    {
        return contrasena;
    }


    // Setters
    void setIdUsuario(int par_id)
    {
        id_usuario = par_id;
    }
    void setNombre(const char* nom)
    {
        strncpy(nombre, nom, sizeof(nombre));
        nombre[sizeof(nombre)-1] = '\0';
    }
    void setCorreo(const char* par_correo)
    {
        strncpy(correo_electronico, par_correo, sizeof(correo_electronico));
        correo_electronico[sizeof(correo_electronico)-1] = '\0';
    }
    void setContrasena(const char* par_contrasena)
    {
        strncpy(contrasena, par_contrasena, sizeof(contrasena));
        contrasena[sizeof(contrasena)-1] = '\0';
    }


    void Cargar_N_Usuario()
    {
        cout << "INGRESE EL NOMBRE DEL USUARIO: " << endl;
        cargarCadena(nombre, 30);
        cout << "INGRESE EL CORREO ELECTRONICO: " << endl;
        cargarCadena(correo_electronico, 30);
        cout << "INGRESE LA CONTRASE�A: " << endl;
        cargarCadena(contrasena, 30);
    };

    void MostrarUsuario()
    {
        cout << "ID DEL USUARIO: " << id_usuario << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "CORREO: " << correo_electronico << endl;
    };

    // sets
    // gets
};


// completa
class Favoritos
{
private:
    int id_favorito;
    int id_usuario;
    int id_supermercado;

public:
    // gets
    int getIdFavorito()
    {
        return id_favorito;
    }
    int getIdUsuario()
    {
        return id_usuario;
    }
    int getIdSupermercado()
    {
        return id_supermercado;
    }

    // sets
    void setIdFavorito(int par_id)
    {
        id_favorito = par_id;
    }
    void setIdUsuario(int par_id)
    {
        id_usuario = par_id;
    }
    void setIdSupermercado(int par_id)
    {
        id_supermercado = par_id;
    }

};

// COMPLETA
class Supermercados
{
private:
    int id_supermercado;
    char nombre[30];
    int id_provincia;
    int id_localidad;
    char direccion[30];

public:
    Supermercados(int idsupermercado=-1)
    {
        id_supermercado=idsupermercado;
    }
    ~Supermercados() {}

    // GETTERS
    int getIdSupermercado()
    {
        return id_supermercado;
    }
    const char* getNombre() const
    {
        return nombre;
    }
    int getIdProvincia()
    {
        return id_provincia;
    }
    int getIdLocalidad()
    {
        return id_localidad;
    }
    const char* getDireccion() const
    {
        return direccion;
    }

    // SETTERS
    void setIdSupermercado(int par_id)
    {
        id_supermercado = par_id;
    }

    void setNombre(const char* nom)
    {
        strncpy(nombre, nom, sizeof(nombre));
        nombre[sizeof(nombre)-1] = '\0';
    }
    void setIdLocalidad(int par_local)
    {
        id_localidad = par_local;
    }
    void setIdProvincia(int par_prov)
    {
        id_provincia = par_prov;
    }

    void CargarSupermercados()
    {
        cout << "INGRESE NOMBRE: " << endl;
        cargarCadena(nombre, 30);

        cout << "INGRESE DIRECCION: " << endl;
        cargarCadena(direccion, 30);

    };
    void Mostrar_Supermercado()
    {
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"DIRECCION: "<<direccion<<endl;
    }

};


// COMPLETA
class Supermercado_Producto
{
private:
    int id_supermercado;
    int id_producto;
    float precio;

public:


    // GETTERS

    int getIdSupermercado()
    {
        return id_supermercado;
    }
    int getIdProducto()
    {
        return id_producto;
    }
    float getPrecio ()
    {
        return precio;
    }


    // SETTERs
    void setIdSupermercado(int par_id)
    {
        id_supermercado = par_id;
    }
    void setIdProducto(int par_id)
    {
        id_producto = par_id;
    }
    void setPrecio (float par_precio)
    {
        precio = par_precio;
    }


};


// COMPLETA
class Productos
{
private:
    int id_producto;
    char nombre[30];
    int id_categoria;

public:
    // GETTERS
    int getIdProducto()
    {
        return id_producto;
    }
    const char* getNombre() const
    {
        return nombre;
    }
    int getIdCategoria()
    {
        return id_categoria;
    }

    // SETTERS
    void setIdProducto(int par_id)
    {
        id_producto = par_id;
    }
    void setNombre(const char* nom)
    {
        strncpy(nombre, nom, sizeof(nombre));
        nombre[sizeof(nombre)-1] = '\0';
    }
    void setIdCategoria(int par_id)
    {
        id_categoria = par_id;
    }
};


// COMPLETA
class Categoria
{
private:
    int id_categoria;
    char nombre[30];

public:
    ///CONSTRUCTOR
    Categoria()
    {
        id_categoria = 0;
    }
    ~Categoria(){}
    //GETTERS
    int getIdCategoria()
    {
        return id_categoria;
    }
    const char* getNombre() const
    {
        return nombre;
    }

    // SETTERS
    void setIdCategoria(int par_id)
    {
        id_categoria = par_id;
    }
    void setNombre(const char* nom)
    {
        strncpy(nombre, nom, sizeof(nombre));
        nombre[sizeof(nombre)-1] = '\0';
    }
};


// COMPLETA
class Provincias
{
private:
    int id_provincia;
    char nombre[30];

public:
    Provincias(int idprovincia=-1)
    {
        id_provincia=idprovincia;
    }
    ~Provincias() {}


    // GETTERS
    int getIdProvincia()
    {
        return id_provincia;
    }
    const char* getNombre() const
    {
        return nombre;
    }

    // SETTERS
    void setIdProvincia(int par_id)
    {
        id_provincia = par_id;
    }
    void setNombre(const char* nom)
    {
        strncpy(nombre, nom, sizeof(nombre));
        nombre[sizeof(nombre)-1] = '\0';
    }

};


// COMPLETA
class Localidades
{
private:
    int id_localidad;
    int id_provincia;
    char nombre[30];

public:
    Localidades(int idlocalidad=-1)
    {
        id_localidad=idlocalidad;
    }
    ~Localidades() {}
    // GETTERS
    int getIdLocalidad()
    {
        return id_localidad;
    }
    int getIdProvincia()
    {
        return id_provincia;
    }
    const char* getNombre() const
    {
        return nombre;
    }

    // SETTERS
    void setIdLocalidad (int par_id )
    {
        id_localidad = par_id;
    }
    void setIdProvincia (int par_id)
    {
        id_provincia = par_id;
    }
    void setNombre(const char* nom)
    {
        strncpy(nombre, nom, sizeof(nombre));
        nombre[sizeof(nombre)-1] = '\0';
    }
};



// ARCHIVOS
class ArchivoUsuarios
{
private:
    char nombre[30];
public:
    ArchivoUsuarios(const char *n = "usuarios.dat")
    {
        strcpy(nombre, n);
    }
    Usuarios leerRegistro(int pos)
    {
        Usuarios reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Usuarios);
    }
    bool grabarRegistro(Usuarios reg)
    {
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoSupermercados
{
private:
    char nombre[30];
public:
    ArchivoSupermercados(const char *n = "supermercados.dat")
    {
        strcpy(nombre, n);
    }
    Supermercados leerRegistro(int pos)
    {
        Supermercados reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Supermercados);
    }
    bool grabarRegistro(Supermercados reg)
    {
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }

};




class ArchivoProvincias
{
private:
    char nombre[30];
public:
    ArchivoProvincias(const char *n = "provincias.dat")
    {
        strcpy(nombre, n);
    }
    Provincias leerRegistro(int pos)
    {
        Provincias reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Provincias);
    }
    bool grabarRegistro(Provincias reg)
    {
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoLocalidades
{
private:
    char nombre[30];
public:
    ArchivoLocalidades(const char *n = "localidades.dat")
    {
        strcpy(nombre, n);
    }
    Localidades leerRegistro(int pos)
    {
        Localidades reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Localidades);
    }
    bool grabarRegistro(Localidades reg)
    {
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoFavoritos
{
private:
    char nombre[30];
public:
    ArchivoFavoritos(const char *n = "favoritos.dat")
    {
        strcpy(nombre, n);
    }
    Favoritos leerRegistro(int pos)
    {
        Favoritos reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Favoritos);
    }
    bool grabarRegistro(Favoritos reg)
    {
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoProductos
{
private:
    char nombre[30];
public:
    ArchivoProductos(const char *n = "productos.dat")
    {
        strcpy(nombre, n);
    }
    Productos leerRegistro(int pos)
    {
        Productos reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Productos);
    }
    bool grabarRegistro(Productos reg)
    {
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoCategorias
{
private:
    char nombre[30];
public:
    ArchivoCategorias(const char *n = "categorias.dat")
    {
        strcpy(nombre, n);
    }
    Categoria leerRegistro(int pos)
    {
        Categoria reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Categoria);
    }
    bool grabarRegistro(Categoria reg)
    {
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoSupermercado_Producto
{
private:
    char nombre[30];
public:
    ArchivoSupermercado_Producto(const char *n = "supermercado_producto.dat")
    {
        strcpy(nombre, n);
    }
    Supermercado_Producto leerRegistro(int pos)
    {
        Supermercado_Producto reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Supermercado_Producto);
    }
    bool grabarRegistro(Supermercado_Producto reg)
    {
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};






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


#endif // PROYECTO_H
