#include <cstring>
#include <iostream>
#include "ArchivoCategorias.h"
#include "ArchivoProductos.h"
#include "ArchivoSupermercado_Producto.h"
#include "ArchivoSupermercados.h"

#include "utils.h"

#include "Productos.h"
#include "Supermercados.h"
#include "Favoritos.h"




using namespace std;

int Productos::getIdProducto()
{
    return id_producto;
}
const char* Productos::getNombre() const
{
    return nombre;
}
int Productos::getIdCategoria()
{
    return id_categoria;
}

void Productos::setIdProducto(int par_id)
{
    id_producto = par_id;
}
void Productos::setNombre(const char* nom)
{
    strncpy(nombre, nom, sizeof(nombre));
    nombre[sizeof(nombre)-1] = '\0';
}
void Productos::setIdCategoria(int par_id)
{
    id_categoria = par_id;
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
            int superID = tempSuperProd.getIdSupermercado();
            ArchivoSupermercados Archivo_super;
            Supermercados supermercado_obj = Archivo_super.leerRegistro(superID);
            cout << producto_obj.getNombre() << ": $" << tempSuperProd.getPrecio() << endl;
            supermercado_obj.Mostrar_Supermercado(); 
            
        }
    }
}



Productos SeleccionarProductos()
{

    Categoria categoria_obj = SeleccionarCategoria();

    if (categoria_obj.getIdCategoria()==0)
    {
        return Productos();
    }

    Productos producto_obj;
    ArchivoProductos  Archivo_prod;


    int opcion;
    int cantreg=0;
    cantreg = Archivo_prod.contarRegistros();
    bool valida = false;

    if(cantreg < 1)
    {
        cout << "NO SE HA ENCONTRADO NINGUN PRODUCTO." << endl;
        waitForKey();
        return Productos();
    }
    else
    {
        int contador=0;
        while(!valida)
        {
            system("clear");

            for (int i = 0; i < cantreg; i++)
            {
                Productos tempProducto = Archivo_prod.leerRegistro(i);

                if(tempProducto.getIdCategoria() == categoria_obj.getIdCategoria() )
                {
                    cout << tempProducto.getIdProducto() << ") -- " << tempProducto.getNombre() << endl;
                    contador++;
                }
            }
            if (contador==0)
            {
                cout << "NO SE HA ENCONTRADO NINGUN PRODUCTO EN LA CATEGORIA SELECCIONADA." << endl;
                waitForKey();
                return Productos();
            }
            else if (contador>0)
            {

                Productos *vec;
                vec = new Productos[contador];
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
                        Productos tempProducto = Archivo_prod.leerRegistro(i);

                        if(tempProducto.getIdCategoria() == categoria_obj.getIdCategoria() )
                        {
                            vec[asignar++]=tempProducto;
                        }
                    }
                    cout<<endl;
                    cout<<"INGRESE SU ELECCION"<<endl;
                    cin >> opcion;
                    system("clear");

                    if (opcion > cantreg || opcion < 1)
                    {
                        system("clear");
                        cout << "ERROR: ELIJA UNA OPCION VALIDA." << endl;
                        waitForKey();
                    }
                    else
                    {
                        for (int i = 0; i < contador; i++)
                        {

                            if(opcion==vec[i].getIdProducto())
                            {
                                producto_obj = Archivo_prod.leerRegistro(opcion-1);
                                mostrarProducto(producto_obj);
                                waitForKey();
                                valida = true;
                                break;
                            }
                            else if (i==contador-1)
                            {
                                system("clear");
                                cout << "ERROR: ELIJA UNA OPCION VALIDA." << endl;
                                waitForKey();
                            }
                        }

                    }


                    delete []vec;
                }


            }


        }
        return producto_obj;
    }





}


Productos CrearProductos(Supermercados supermercado_obj)
{

    Productos producto_obj;
    Categoria categoria_obj = SeleccionarCategoria();

    if (categoria_obj.getIdCategoria()==0)
    {
        return producto_obj;
    }
    else
    {
        ArchivoProductos  Archivo_prod;
        int cantreg = Archivo_prod.contarRegistros();
        char nombre[30];


        cout << "INGRESE EL NOMBRE DEL PRODUCTO: ";
        cargarCadena(nombre, 30);

        /// Producto
        if (cantreg > 0)
        {
            Productos ult_producto = Archivo_prod.leerRegistro(cantreg - 1);
            producto_obj.setIdProducto(ult_producto.getIdProducto() + 1);
        }
        else
        {
            producto_obj.setIdProducto(1);  /// Asigno 1 si no existe otro supermercado
        }

        producto_obj.setNombre(nombre);
        producto_obj.setIdCategoria(categoria_obj.getIdCategoria());

        /// relacion supermercado Producto
        ArchivoSupermercado_Producto Archivo_super_prod;
        Supermercado_Producto super_prod_obj;

        super_prod_obj.setIdProducto(producto_obj.getIdProducto());
        super_prod_obj.setIdSupermercado(supermercado_obj.getIdSupermercado());

        float precio;

        cout << "INGRESE EL PRECIO DEL PRODUCTO: ";
        cin >> precio;

        super_prod_obj.setPrecio(precio);

        Archivo_super_prod.grabarRegistro(super_prod_obj);


        bool escribio=Archivo_prod.grabarRegistro(producto_obj);
        if (escribio==true)
        {
            cout<<"EL PRODUCTO SE HA REGISTRADO CORRECTAMENTE"<<endl;
            waitForKey();
        }
        return producto_obj;

    }



}


Productos BuscarNombreProducto()
{

    Productos producto_obj;
    ArchivoProductos Archivo;
    int cantreg = Archivo.contarRegistros();

    bool valida = false;
    char nombre[30];

    system("clear");

    cout << "BUSCAR POR NOMBRE " << endl << endl;
    cout << "INGRESE EL NOMBRE: ";
    cin >> nombre;

    system("clear");

    if(cantreg < 1)
    {
        cout << "NO SE A ENCONTRADO NINGUN PRODUCTO." << endl;
        waitForKey();
        return Productos();
    }

    else {
        bool encontro_coincidencia=false;
        int opcion;
        while(!valida)
        {
            int contador=0;
            system("clear");
            cout << "SELECCIONE PRODUCTO: " << endl << endl;
            for(int i = 0; i < cantreg; i++)
            {
                char nombreProducto_obj[30];
                Productos tempProducto = Archivo.leerRegistro(i);


                strcpy(nombreProducto_obj, tempProducto.getNombre());

                tolower_string(nombre);
                tolower_string(nombreProducto_obj);

                const char* encontrado = strstr(nombreProducto_obj, nombre);

                if (encontrado!=nullptr)
                {
                    encontro_coincidencia=true;
                    cout << tempProducto.getIdProducto() << ") --- " << nombreProducto_obj << endl;
                    contador++;
                }
            }

            if (encontro_coincidencia==false){
                system("clear");
                cout<<"NO SE ENCONTRARON PRODUCTOS QUE COINCIDAN CON EL TEXTO INGRESADO POR TECLADO"<<endl;
                waitForKey();
                return Productos();

            }

            else {
                int asignar=0;


                Productos *vec;
                vec=new Productos[contador];
                if (vec==nullptr){

                    cout<<"NO SE PUDO ASIGNAR LOS RECURSOS NECESARIOS PARA EL PROCESO, CONTACTARSE CON SOPORTE:"<<endl<<" sofia.campos@alumnos.frgp.utn.edu.ar o con julian.negrete@alumnos.frgp.utn.edu.ar"<<endl;
                    waitForKey();
                    exit (-240);

                }
                else {

                    for(int i = 0; i < cantreg; i++)
            {
                char nombreProducto_obj[30];
                Productos tempProducto = Archivo.leerRegistro(i);


                strcpy(nombreProducto_obj, tempProducto.getNombre());

                tolower_string(nombre);
                tolower_string(nombreProducto_obj);

                const char* encontrado = strstr(nombreProducto_obj, nombre);

                if (encontrado!=nullptr)
                {
                    encontro_coincidencia=true;
                    vec[asignar++]=tempProducto;
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
                         for(int i = 0; i < contador; i++)
                        {

                            if (opcion==vec[i].getIdProducto())
                            {
                                producto_obj = Archivo.leerRegistro(opcion-1);
                                valida = true;
                                break;
                            }
                            else if (i==contador-1){
                                system("clear");
                                cout << "ERROR: Por favor seleccione una opcion valida." <<  endl;
                                waitForKey();

                            }
                        }


                    }

                }


                delete[]vec;
            }

        }

        return producto_obj;

    }



}


Productos BuscarCategoria()
{
    Productos producto_obj;
    ArchivoProductos Archivo;

    Categoria categoria_obj = SeleccionarCategoria();

    int cantreg = Archivo.contarRegistros();



    if(cantreg < 1)
    {
        cout << "NO SE HA ENCONTRADO NINGUN PRODUCTO." << endl;
        waitForKey();
        return Productos();
    }
    else
    {

        int contador=0;
        bool bandera=false;

        system("clear");
        int opcion;
        bool valida = false;
        while(!valida)
        {
            for(int i = 0; i < cantreg; i++)
            {

                Productos tempProducto = Archivo.leerRegistro(i);
                if(tempProducto.getIdCategoria() == categoria_obj.getIdCategoria())
                {
                    if (bandera==false)
                    {
                        system("clear");
                        cout << "SELECCIONE PRODUCTO: " << endl << endl;
                        bandera=true;
                    }
                    cout << i << ") --- " << tempProducto.getNombre() << endl;
                    contador++;
                }
            }

            if (contador==0)
            {
                system("clear");
                cout<<"NO SE ENCONTRARON PRODUCTOS EN LA CATEGORIA SELECCIONADA"<<endl;
                waitForKey();
                return Productos();
            }


            cin >> opcion;

            if(opcion > cantreg)
            {
                system("clear");
                cout << "ERROR: ELiJA UNA OPCION VALIDA." << endl;
                waitForKey();
            }
            else
            {
                producto_obj = Archivo.leerRegistro(opcion);
                valida = true;
                return producto_obj;
            }

            }

        }

    
    return Productos();

    }


Productos BuscarPrecio()
{
    ArchivoProductos Archivo;
    ArchivoSupermercado_Producto Archivo_Super_prod;

    Productos  producto_obj;


    int cantreg = Archivo.contarRegistros();
    int cantreg_super = Archivo_Super_prod.contarRegistros();

    float precio1, precio2;

    system("clear");
    cout << "Ingresar Precio desde : ";
    cin >> precio1;
    cout << " Hasta : ";
    cin >> precio2;

    int opcion;
    bool valida = false;

    if(cantreg_super < 1)
    {
        cout << "NO SE HA ENCONTRADO NINGUN PRODUCTO." << endl;
        waitForKey();
        return Productos();
    }
    else
    {
        int contador=0;
        bool bandera=false;

        while(!valida)
        {

            for (int i = 0; i < cantreg_super; i++)
            {
                Supermercado_Producto tempSuperProd = Archivo_Super_prod.leerRegistro(i);
                if( (tempSuperProd.getPrecio() >= precio1 && tempSuperProd.getPrecio() <= precio2))
                {
                    if (bandera==false)
                    {
                        system("clear");
                        cout << "SELECCIONAR PRODUCTO: " << endl << endl;
                        bandera=true;
                    }
                    for(int j = 0; j < cantreg; j++)
                    {
                        Productos tempProd = Archivo.leerRegistro(j);
                        if((tempSuperProd.getIdProducto() == tempProd.getIdProducto() ))
                        {
                            cout << j << ") -- " << tempProd.getNombre() << ": $ " << tempSuperProd.getPrecio() << endl;
                            contador++;
                        }

                    }
                }
            }

            if (contador==0)
            {
                system("clear");
                cout<<"NO SE HAN ENCONTRADO PRODUCTOS DENTRO DEL RANGO DE PRECIOS INGRESADOS"<<endl;
                waitForKey();
                return Productos();
            }


            cin >> opcion;

            if(opcion > cantreg)
            {
                system("clear");
                cout << "ERROR: ELiJA UNA OPCION VALIDA." << endl;
                waitForKey();
            }
            else
            {
                producto_obj = Archivo.leerRegistro(opcion);
                valida = true;
                return producto_obj;
            }

        }
    }


}


Productos SeleccionarProducto_Supermercado(Supermercados supermercado_obj)
{
    Productos producto_obj;

    ArchivoProductos Archivo;
    ArchivoSupermercado_Producto  Archivo_Prod_super;

    int cantreg_super = Archivo_Prod_super.contarRegistros();
    int cantreg = Archivo.contarRegistros();

    if(cantreg_super < 1)
    {
        cout << "NO SE HA ENCONTRADO NINGUN PRODUCTO." << endl;
        waitForKey();
        return Productos();
    }
    else
    {
        int contador=0;
        bool bandera=false;

        int opcion;
        bool valida = false;
        while(!valida)
        {

            for (int i = 0; i < cantreg_super; i++)
            {
                Supermercado_Producto  tempSuperProd = Archivo_Prod_super.leerRegistro(i);

                if(supermercado_obj.getIdSupermercado() == tempSuperProd.getIdSupermercado())
                {
                    for(int j = 0; j < cantreg; j++)
                    {
                        Productos tempProd = Archivo.leerRegistro(j);

                        if(tempProd.getIdProducto() == tempSuperProd.getIdProducto())
                        {
                            if (bandera==false)
                            {
                                system("clear");
                                cout << "PRODUCTOS REGISTRADOS: " << endl << endl;
                                bandera=true;

                            }
                            cout << j << ") -- " << tempProd.getNombre() << ": $" << tempSuperProd.getPrecio() << endl;
                            contador++;
                        }
                    }
                    if (bandera==true)
                    {

                        valida=true;
                        return producto_obj;
                    }
                }
            }

            if (contador==0)
            {
                system("clear");
                cout<<"NO SE ENCONTRARON PRODUCTOS REGISTRADOS EN EL SUPERMERCADO: "<<supermercado_obj.getNombre()<<endl;
                waitForKey();
                return Productos();
            }

        }


    }

}


Productos BuscarProductos()
{
    Productos producto_obj;
    int opcion;
    bool valida = false;
    while(!valida)
    {
        system("clear");
        cout << "BUSCAR PRODUCTOS: " << endl << endl;

        cout << "1) NOMBRE" << endl;
        cout << "2) CATEGORIA " << endl;
        cout << "3) PRECIO " << endl;
        cout << "4) SUPERMERCADO " << endl;
        cout << "9) BACK " << endl;
        cin >> opcion;

        switch(opcion)
        {

        case 1:
            producto_obj = BuscarNombreProducto();
            valida = true;
            break;

        case 2:
            producto_obj = BuscarCategoria();
            valida = true;
            break;

        case 3:
            producto_obj = BuscarPrecio();
            valida = true;
            break;

        case 4:
        {
            Supermercados supermercado_obj  = SeleccionarSupermercado();
            producto_obj = SeleccionarProducto_Supermercado(supermercado_obj);
            valida = true;
            break;
        }


        case 9:
            return Productos();
        default:
            system("clear");
            cout << "ERROR: ELIJA UNA OPCION VALIDA." << endl;
            waitForKey();
            break;

        }
    }

    return producto_obj;


}



void listarProductosSuper(Supermercados supermercado_obj)
{

    ArchivoProductos Archivo;
    ArchivoSupermercado_Producto  Archivo_Prod_super;

    int cantreg_super = Archivo_Prod_super.contarRegistros();
    int cantreg = Archivo.contarRegistros();

    bool encontro=false;


    system("clear");
    for (int i = 0; i < cantreg_super; i++)
    {
        Supermercado_Producto  tempSuperProd = Archivo_Prod_super.leerRegistro(i);

        if(supermercado_obj.getIdSupermercado() == tempSuperProd.getIdSupermercado())
        {
            for(int j = 0; j < cantreg; j++)
            {
                Productos tempProd = Archivo.leerRegistro(j);

                if(tempProd.getIdProducto() == tempSuperProd.getIdProducto())
                {
                    cout << j << ") -- " << tempProd.getNombre() << ": $" << tempSuperProd.getPrecio() << endl;
                    encontro=true;
                }
            }

        }
    }
    if (encontro==false)
    {
        cout << "NO SE HA ENCONTRADO NINGUN PRODUCTO." << endl;
        waitForKey();
        return;
    }

    waitForKey();


}


void menuProductos(Usuarios user)
{
    Productos producto_obj;
    int opcion;
    bool valida = false;
    while(!valida)
    {
        system("clear");
        cout << "PRODUCTOS: " << endl << endl;

        cout << "1) SELECCIONAR" << endl;
        cout << "2) CREAR " << endl;
        cout << "3) BUSCAR " << endl;
        cout << "9) BACK " << endl;
        cin >> opcion;

        switch(opcion)
        {

        case 1:
        {
            producto_obj = SeleccionarProductos();
            system("clear");
            break;

        }


        case 2:
        {
            Supermercados supermercado_obj  = SeleccionarSupermercado();
            producto_obj = CrearProductos(supermercado_obj);
            valida = true;
            break;
        }


        case 3:
            producto_obj = BuscarProductos();
            if (producto_obj.getIdProducto() == 0)
            {
                break;
            }
            else
            {
                mostrarProducto(producto_obj);
                waitForKey();
                break;
            }


    return;

        case 9:
            return;

        default:
            system("clear");
            cout << "ERROR: ELIJA UNA OPCION VALIDA." << endl;
            waitForKey();
            break;
        }

    }
}


void menuProductos_super(Usuarios user, Supermercados supermercado)
{
    Productos producto_obj;
    int opcion;
    bool valida = false;
    while(!valida)
    {
        system("clear");


        cout << "SUPERMERCADO: " << supermercado.getNombre() << endl << endl;
        cout << "1) AGREGAR PRODUCTOS" << endl;
        cout << "2) AGREGAR A FAVORITOS" << endl;
        cout << "3) LISTAR PRODUCTOS " << endl;
        cout << "9) BACK" << endl;

        cin >> opcion;



        switch(opcion)
        {

        case 1:
            producto_obj = CrearProductos(supermercado);
            break;

        case 2:
            AgregarFavorito(user, supermercado.getIdSupermercado());
            break;

        case 3:
            listarProductosSuper(supermercado);
            break;

        case 9:
            return;

        default:
            system("clear");
            cout << "ERROR: ELIJA UNA OPCION VALIDA." << endl;
            waitForKey();
            break;

        }


    }

}





