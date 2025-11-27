#ifndef EXPORTAR_H_INCLUDED
#define EXPORTAR_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "ArchivoSupermercados.h"
#include "ArchivoProvincias.h"
#include "ArchivoLocalidades.h"
#include "ArchivoCategorias.h"
#include "ArchivoProductos.h"
#include "ArchivoSupermercado_Producto.h"


using namespace std;
///case 1
ArchivoSupermercados ExportarSupermercados()
{
    ArchivoSupermercados archivo_;
    ArchivoProvincias archivo_prov;
    ArchivoLocalidades archivo_loc;

    int cantReg=0;
    int cantReg_prov=0;
    int cantReg_loc=0;

    ofstream archivo("listadoSupermercados_Historico.csv");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo. Intentando crearlo..." << endl;
        waitForKey();
        archivo.open("listadoSupermercados_Historico.csv");
        if (!archivo.is_open())
        {
            cout << "ERROR: No se pudo crear el archivo." << endl;
            waitForKey();
            exit(-10);
        }
    }
    else
    {

        cantReg = archivo_.contarRegistros();
        cantReg_prov=archivo_prov.contarRegistros();
        cantReg_loc=archivo_loc.contarRegistros();

        for (int i = 0; i < cantReg; i++)
        {

            Supermercados tempSupermercado= archivo_.leerRegistro(i);

            ///grabar en excel el supermercado
            archivo<<"NOMBRE;";
            archivo<<tempSupermercado.getNombre()<<"\t"<<"\n";

            for (int j=0; j<cantReg_prov; j++)
            {
                Provincias tempProvincia=archivo_prov.leerRegistro(j);

                ///encuentro coincidencias y grabo el nombre de la prov
                if (tempProvincia.getIdProvincia()==tempSupermercado.getIdProvincia())
                {

                    archivo<<"PROVINCIA;";
                    archivo     << tempProvincia.getNombre()<< "\t"<<"\n";
                }

            }

            for (int k=0; k<cantReg_loc; k++)
            {
                Localidades tempLocalidad=archivo_loc.leerRegistro(k);
                if (tempSupermercado.getIdLocalidad()==tempLocalidad.getIdLocalidad())
                {

                    archivo << "LOCALIDAD;";
                    archivo<< tempLocalidad.getNombre() << "\t"<< "\n";
                }

            }

            archivo << "\n" << "\n";
        }

    archivo.close();
    cout << "SE HA EXPORTADO EL LISTADO CORRECTAMENTE" << endl;
    waitForKey();

    }
    return archivo_;

}

///case 2
ArchivoCategorias ExportarCategorias()
{
    ArchivoCategorias archivo_;

    ofstream archivo("listadoCategorias_Historico.csv");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo. Intentando crearlo..." << endl;
        waitForKey();
        archivo.open("listadoCategorias_Historico.csv");
        if (!archivo.is_open())
        {
            cout << "ERROR: No se pudo crear el archivo." << endl;
            waitForKey();
            exit(-10);
        }
    }
    else
    {
        int cantReg = archivo_.contarRegistros();

        for (int i = 0; i < cantReg; i++)
        {

            Categoria tempCategoria= archivo_.leerRegistro(i);

            ///grabar en excel el supermercado
            archivo<<"NOMBRE;";
            archivo<<tempCategoria.getNombre()<<"\t"<<"\n";
            archivo << "\n" << "\n";
        }

    archivo.close();
    cout << "SE HA EXPORTADO EL LISTADO CORRECTAMENTE" << endl;
    waitForKey();
    }
    return archivo_;
}

///case 3
ArchivoProductos ExportarProductos()
{

    ArchivoProductos archivo_;
    ArchivoSupermercado_Producto archivo_sup_prod;

    ofstream archivo("listadoProductos_Historico.csv");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo. Intentando crearlo..." << endl;
        waitForKey();
        archivo.open("listadoProductos_Historico.csv");
        if (!archivo.is_open())
        {
            cout << "ERROR: No se pudo crear el archivo." << endl;
            waitForKey();
            exit(-10);
        }

    }
    else
    {

        int cantReg = archivo_.contarRegistros();
        int cantReg_1 = archivo_sup_prod.contarRegistros();

        for (int i = 0; i < cantReg; i++)
        {
            Productos tempProducto = archivo_.leerRegistro(i);

            archivo << "NOMBRE;";
            archivo << tempProducto.getNombre()<< "\t"<<"\n";
            archivo << "CATEGORIA;";
            archivo     << tempProducto.getIdCategoria() << "\t"<<"\n";
            archivo << "ID PRODUCTO;";
            archivo<< tempProducto.getIdProducto() << "\t"<< "\n";
            for (int j=0; j<cantReg_1; j++)
            {
                Supermercado_Producto tempSupermercado_producto=archivo_sup_prod.leerRegistro(j);
                if (tempProducto.getIdProducto()==tempSupermercado_producto.getIdProducto())
                {
                    archivo << "PRECIO;";
                    archivo<< tempSupermercado_producto.getPrecio() << "\t"<< "\n";
                    archivo << "\n" << "\n";
                }

            }
        }

    archivo.close();
    cout << "SE HA EXPORTADO EL LISTADO CORRECTAMENTE" << endl;
    waitForKey();

    }
    return archivo_;
}

///case 4
ArchivoSupermercados ExportarSupermercados_y_Categorias()
{
    ArchivoSupermercados archivo_sup;
    ArchivoSupermercado_Producto archivo_sup_prod;
    ArchivoProductos archivo_prod;
    ArchivoCategorias archivo_cat;

    ofstream archivo("listadoSupermercadosyCategorias_Historico.csv");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo. Intentando crearlo..." << endl;
        waitForKey();
        archivo.open("listadoSupermercadosyCategorias_Historico.csv");
        if (!archivo.is_open())
        {
            cout << "ERROR: No se pudo crear el archivo." << endl;
            waitForKey();
            exit(-10);
        }
    }
    else
    {

        int cantReg = archivo_sup.contarRegistros();
        int cantReg_sup_prod=archivo_sup_prod.contarRegistros();
        int cantReg_prod=archivo_prod.contarRegistros();
        int cantReg_cat=archivo_cat.contarRegistros();

        ///SUPERMERCADOS Y SUS CATEGORIAS REGISTRADAS
        for (int i = 0; i < cantReg; i++)
        {
            ///leemos el registro de sup
            Supermercados tempSupermercado= archivo_sup.leerRegistro(i);

            ///grabar en excel el supermercado
            archivo<<"NOMBRE;";
            archivo<<tempSupermercado.getNombre()<<"\t"<<"\n";

            for (int j=0; j<cantReg_sup_prod; j++)
            {
                ///leemos registro de supermercado producto
                Supermercado_Producto tempSupermercadoProducto=archivo_sup_prod.leerRegistro(j);

                ///encuentro coincidencias y puedo obtener el id del producto, para poder saber la categoria
                if (tempSupermercadoProducto.getIdSupermercado()==tempSupermercado.getIdSupermercado())
                {
                    for (int l=0; l<cantReg_prod; l++)
                    {
                        ///leemos los registros de los productos para encontrar su categoria
                        Productos tempProductos=archivo_prod.leerRegistro(l);

                        ///si coinciden ambos id del producto, podemos obtener el nombre de la categoria a la que pertenece
                        if (tempSupermercadoProducto.getIdProducto()==tempProductos.getIdProducto())
                        {


                            for (int m=0; m<cantReg_cat; m++)
                            {
                                Categoria tempCategoria=archivo_cat.leerRegistro(m);
                                ///cuando coinciden los id de categoria, podemos acceder al nombre de categoria correcto
                                if (tempProductos.getIdCategoria()==tempCategoria.getIdCategoria())
                                {
                                    ///grabamos en el excel el nombre de la categoria
                                    archivo<<"CATEGORIA;";
                                    archivo<<tempCategoria.getNombre()<<"\t"<<"\n";
                                }
                            }

                        }

                    }
                }

            }

            archivo << "\n" << "\n";
        }

    archivo.close();
    cout << "SE HA EXPORTADO EL LISTADO CORRECTAMENTE" << endl;
    waitForKey();
    }
    return archivo_sup;
}

///case 5
///SUPERMERCADOS Y SUS PRODUCTOS
ArchivoSupermercados ExportarSupermercados_y_Productos()
{
    ArchivoSupermercados archivo_sup;
    ArchivoSupermercado_Producto archivo_sup_prod;
    ArchivoProductos archivo_prod;

    ofstream archivo("listadoSupermercadosyProductos_Historico.csv");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo. Intentando crearlo..." << endl;
        waitForKey();
        archivo.open("listadoSupermercadosyProductos_Historico.csv");
        if (!archivo.is_open())
        {
            cout << "ERROR: No se pudo crear el archivo." << endl;
            waitForKey();
            exit(-10);
        }
    }
    else
    {

        int cantReg = archivo_sup.contarRegistros();
        int cantReg_sup_prod=archivo_sup_prod.contarRegistros();
        int cantReg_prod=archivo_prod.contarRegistros();

        bool tieneProductos=false;

        ///SUPERMERCADOS Y SUS CATEGORIAS REGISTRADAS
        for (int i = 0; i < cantReg; i++)
        {
            ///leemos el registro de sup
            Supermercados tempSupermercado= archivo_sup.leerRegistro(i);

            ///grabar en excel el supermercado
            archivo<<"NOMBRE;";
            archivo<<tempSupermercado.getNombre()<<"\t"<<"\n";

            for (int j=0; j<cantReg_sup_prod; j++)
            {
                ///leemos registro de supermercado producto
                Supermercado_Producto tempSupermercadoProducto=archivo_sup_prod.leerRegistro(j);

                ///encuentro coincidencias y puedo obtener el id del producto, para poder saber el nombre del mismo
                if (tempSupermercadoProducto.getIdSupermercado()==tempSupermercado.getIdSupermercado())
                {
                    for (int l=0; l<cantReg_prod; l++)
                    {
                        ///leemos los registros de los productos para encontrar su nombre
                        Productos tempProductos=archivo_prod.leerRegistro(l);

                        ///si coinciden ambos id del producto, podemos obtener el nombre
                        if (tempSupermercadoProducto.getIdProducto()==tempProductos.getIdProducto())
                        {
                            if (tieneProductos==false)
                            {
                                archivo<<"PRODUCTOS REGISTRADOS:";
                                archivo<<"\n";
                                tieneProductos=true;
                            }
                            archivo<<"\n";
                            archivo<<"PRODUCTO;";
                            archivo<<tempProductos.getNombre()<<"\t"<<"\n";
                            archivo<<"PRECIO;";
                            archivo<<tempSupermercadoProducto.getPrecio()<<"\n";

                        }

                    }
                }

            }

            archivo << "\n" << "\n";
        }

    archivo.close();
    cout << "SE HA EXPORTADO EL LISTADO CORRECTAMENTE" << endl;
    waitForKey();
    }
    return archivo_sup;
}

///case 6
///SUPERMERCADOS CON SUS CATEGORIAS Y PRODUCTOS REGISTRADOS
ArchivoSupermercados ExportarSupermercadosCategoriasyProductos()
{
    ArchivoSupermercados archivo_sup;
    ArchivoSupermercado_Producto archivo_sup_prod;
    ArchivoProductos archivo_prod;
    ArchivoCategorias archivo_cat;

    ofstream archivo("listadoSupermercadosProductosyCategorias_Historico.csv");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo. Intentando crearlo..." << endl;
        waitForKey();
        archivo.open("listadoSupermercadosProductosyCategorias_Historico.csv");
        if (!archivo.is_open())
        {
            cout << "ERROR: No se pudo crear el archivo." << endl;
            waitForKey();
            exit(-10);
        }
    }
    else
    {

        int cantReg = archivo_sup.contarRegistros();
        int cantReg_sup_prod=archivo_sup_prod.contarRegistros();
        int cantReg_prod=archivo_prod.contarRegistros();
        int cantReg_cat=archivo_cat.contarRegistros();

        bool tieneProductos=false;

        ///SUPERMERCADOS Y SUS CATEGORIAS REGISTRADAS
        for (int i = 0; i < cantReg; i++)
        {
            ///leemos el registro de sup
            Supermercados tempSupermercado= archivo_sup.leerRegistro(i);

            ///grabar en excel el supermercado
            archivo<<"NOMBRE;";
            archivo<<tempSupermercado.getNombre()<<"\t"<<"\n";

            for (int j=0; j<cantReg_sup_prod; j++)
            {
                ///leemos registro de supermercado producto
                Supermercado_Producto tempSupermercadoProducto=archivo_sup_prod.leerRegistro(j);

                ///encuentro coincidencias y puedo obtener el id del producto, para poder saber el nombre del mismo
                if (tempSupermercadoProducto.getIdSupermercado()==tempSupermercado.getIdSupermercado())
                {
                    for (int l=0; l<cantReg_prod; l++)
                    {
                        ///leemos los registros de los productos para encontrar su nombre
                        Productos tempProductos=archivo_prod.leerRegistro(l);
                        for (int m=0; m<cantReg_cat; m++)
                        {

                            Categoria tempCategoria=archivo_cat.leerRegistro(m);
                            ///si coinciden ambos id del producto, podemos obtener el nombre
                            if (tempSupermercadoProducto.getIdProducto()==tempProductos.getIdProducto())
                            {
                                if (tempProductos.getIdCategoria()==tempCategoria.getIdCategoria())
                                {

                                    if (tieneProductos==false)
                                    {

                                        archivo<<"PRODUCTOS REGISTRADOS:";
                                        archivo<<"\n";
                                        tieneProductos=true;

                                    }

                                    archivo<<"\n";
                                    archivo<<"PRODUCTO;";
                                    archivo<<tempProductos.getNombre()<<"\t"<<"\n";
                                    archivo<<"PRECIO;";
                                    archivo<<tempSupermercadoProducto.getPrecio()<<"\n";
                                    archivo<<"CATEGORIA;";
                                    archivo<<tempCategoria.getNombre()<<"\n";


                                }
                            }


                        }

                    }
                }

            }

            archivo << "\n" << "\n";
        }

        archivo.close();
        cout << "SE HA EXPORTADO EL LISTADO CORRECTAMENTE" << endl;
        waitForKey();
    }
        return archivo_sup;
}



void menuExportar()
{
    bool valida=true;
    int eleccion;

    while (valida!=false)
    {
        system("clear");
        cout<<"     EXPORTAR        "<<endl;
        cout<<endl;
        cout<<"�QUE DATO/S DESEA EXPORTAR?"<<endl;
        cout<<endl;
        cout<<"1) SUPERMERCADOS REGISTRADOS"<<endl;
        cout<<"2) CATEGORIAS REGISTRADAS"<<endl;
        cout<<"3) PRODUCTOS REGISTRADOS"<<endl;
        cout<<endl;
        cout<<"4) SUPERMERCADOS Y SUS CATEGORIAS REGISTRADAS"<<endl;
        cout<<"5) SUPERMERCADOS Y SUS PRODUCTOS"<<endl;
        cout<<endl;
        cout<<"6) SUPERMERCADOS CON SUS CATEGORIAS Y PRODUCTOS REGISTRADOS"<<endl;
        cout<<endl;
        cout<<"9) BACK"<<endl;
        cin>>eleccion;

        switch (eleccion)
        {

        case 1:
            ExportarSupermercados();
            break;

        case 2:
            ExportarCategorias();
            break;

        case 3:
            ExportarProductos();
            break;
        case 4:
            ExportarSupermercados_y_Categorias();
            break;
        case 5:
            ExportarSupermercados_y_Productos();
            break;
        case 6:
            ExportarSupermercadosCategoriasyProductos();
            break;

        case 9:
            return;
        }

    }

}


#endif // EXPORTAR_H_INCLUDED
