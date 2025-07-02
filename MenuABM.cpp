#include <iostream>
using namespace std;
#include "Menu.h"

// ----------- ABM PRODUCTOS ---------------
bool Menu::menuGuardarProducto(){
    ArchivoProducto archivoProducto("productos.dat");
    Producto nuevoProducto;
    int idProducto;

    cout << "Ingrese el ID del nuevo producto: ";
    cin >> idProducto;
    nuevoProducto.cargarProducto(idProducto);

    archivoProducto.Guardar_P(nuevoProducto);
    return true;
}

bool Menu::menuRemoverProducto(){
    ArchivoProducto archivoProducto("productos.dat");
    Producto registro;
    int idProducto;

    cout << "Ingrese el ID del producto que quiere remover: ";
    cin >> idProducto;
    int encontro = archivoProducto.Buscar_P(idProducto);
    registro = archivoProducto.Leer_P(encontro);
    registro.setEstadoProducto(false);
    bool ok = archivoProducto.Guardar_P(registro, encontro);

    return ok;
}

bool Menu::menuRecuperarProducto(){
    ArchivoProducto archivoProducto("productos.dat");
    Producto registro;
    int idProducto;

    cout << "Ingrese el ID del producto que quiere recuperar: ";
    cin >> idProducto;
    int encontro = archivoProducto.Buscar_P(idProducto);
    registro = archivoProducto.Leer_P(encontro);
    registro.setEstadoProducto(true);
    bool ok = archivoProducto.Guardar_P(registro, encontro);

    return ok;
}

// ------------- ABM CLIENTES ---------------
bool Menu::menuGuardarCliente(){
    ArchivoCliente archivoCliente("clientes.dat");
    Cliente nuevoCliente;
    int idPersona;

    cout << "Ingrese el ID del nuevo cliente: ";
    cin >> idPersona;
    nuevoCliente.cargarCliente(idPersona);

    archivoCliente.Guardar_CL(nuevoCliente);
    return true;
}

bool Menu::menuRemoverCliente(){
    ArchivoCliente archivoCliente("clientes.dat");
    Cliente registro;
    int idPersona;

    cout << "Ingrese el ID del cliente que quiere remover: ";
    cin >> idPersona;
    int encontro = archivoCliente.Buscar_CL(idPersona);
    registro = archivoCliente.Leer_CL(encontro);
    registro.setEstadoPersona(false);
    bool ok = archivoCliente.Guardar_CL(registro, encontro);

    return ok;
}

bool Menu::menuRecuperarCliente(){
    ArchivoCliente archivoCliente("clientes.dat");
    Cliente registro;
    int idPersona;

    cout << "Ingrese el ID del cliente que quiere recuperar: ";
    cin >> idPersona;
    int encontro = archivoCliente.Buscar_CL(idPersona);
    registro = archivoCliente.Leer_CL(encontro);
    registro.setEstadoPersona(true);
    bool ok = archivoCliente.Guardar_CL(registro, encontro);

    return ok;
}

// ------------ ABM COMPRAS ----------------
bool Menu::menuGuardarCompra(){
    ArchivoCompra archivoCompra("compras.dat");
    Compra nuevaCompra;
    int idPersona;

    cout << "Ingrese el ID de la nueva compra: ";
    cin >> idPersona;
    nuevaCompra.cargarCompra(idPersona);

    archivoCompra.Guardar_C(nuevaCompra);
    return true;
}

bool Menu::menuRemoverCompra(){
    ArchivoCompra archivoCompra("compras.dat");
    Compra registro;
    int idCompra;

    cout << "Ingrese el ID de la compra que quiere remover: ";
    cin >> idCompra;
    int encontro = archivoCompra.Buscar_C(idCompra);
    registro = archivoCompra.Leer_C(encontro);
    registro.setEstadoCompra(false);
    bool ok = archivoCompra.Guardar_C(registro, encontro);

    return ok;
}

bool Menu::menuRecuperarCompra(){
    ArchivoCompra archivoCompra("compras.dat");
    Compra registro;
    int idCompra;

    cout << "Ingrese el ID de la compra que quiere recuperar: ";
    cin >> idCompra;
    int encontro = archivoCompra.Buscar_C(idCompra);
    registro = archivoCompra.Leer_C(encontro);
    registro.setEstadoCompra(true);
    bool ok = archivoCompra.Guardar_C(registro, encontro);

    return ok;
}

// --------- ABM VENTAS ----------------
bool Menu::menuGuardarVenta(){
    ArchivoVenta archivoVenta("ventas.dat");
    Venta nuevaVenta;
    int idVenta;

    cout << "Ingrese el ID de la nueva venta: ";
    cin >> idVenta;
    nuevaVenta.cargarVenta(idVenta);

    archivoVenta.Guardar_V(nuevaVenta);
    return true;
}

bool Menu::menuRemoverVenta(){
    ArchivoVenta archivoVenta("ventas.dat");
    Venta registro;
    int idVenta;

    cout << "Ingrese el ID de la venta que quiere remover: ";
    cin >> idVenta;
    int encontro = archivoVenta.Buscar_V(idVenta);
    registro = archivoVenta.Leer_V(encontro);
    registro.setEstadoVenta(false);
    bool ok = archivoVenta.Guardar_V(registro, encontro);

    return ok;
}

bool Menu::menuRecuperarVenta(){
    ArchivoVenta archivoVenta("ventas.dat");
    Venta registro;
    int idVenta;

    cout << "Ingrese el ID de la venta que quiere recuperar: ";
    cin >> idVenta;
    int encontro = archivoVenta.Buscar_V(idVenta);
    registro = archivoVenta.Leer_V(encontro);
    registro.setEstadoVenta(true);
    bool ok = archivoVenta.Guardar_V(registro, encontro);

    return ok;
}
