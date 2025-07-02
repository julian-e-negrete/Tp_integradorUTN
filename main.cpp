#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    Menu opcion;

    cout << "1 - Alta/Baja"<<endl;
    cout << "2 - Recuperar registro borrado"<<endl;
    cout << "3 - Listados" <<endl;

    int opc=0;

    cout << "Seleccione una opcion: " <<endl;
    cin >> opc;
    system("cls");

    switch(opc){
        case 1:
            system("cls"); // --------- ALTAS ---------------
            cout <<"1 - Alta"<<endl;
            cout <<"2 - Baja"<<endl;
            cout << "Seleccione una opcion: ";
            cin >> opc;
            switch(opc){
                case 1:
                    system("cls");
                    cout<<"1 - Agregar un producto"<<endl;
                    cout<<"2 - Agregar un cliente"<<endl;
                    cout<<"3 - Agregar una compra"<<endl;
                    cout<<"4 - Agregar una venta"<<endl;
                    cout<<"Seleccione una opcion: ";
                    cin>>opc;

                    switch(opc){
                        case 1:
                            system("cls");
                            opcion.menuGuardarProducto();
                            break;
                        case 2:
                            system("cls");
                            opcion.menuGuardarCliente();
                            break;
                        case 3:
                            system("cls");
                            opcion.menuGuardarCompra();
                            break;
                        case 4:
                            system("cls");
                            opcion.menuGuardarVenta();
                            break;
                    }
                    break;

                case 2: // ---------- BAJAS --------------
                    system("cls");
                    cout<<"1 - Eliminar un producto"<<endl;
                    cout<<"2 - Eliminar un cliente"<<endl;
                    cout<<"3 - Eliminar una compra"<<endl;
                    cout<<"4 - Eliminar una venta"<<endl;
                    cout<<"Seleccione una opcion: ";
                    cin>>opc;

                    switch(opc){
                        case 1:
                            system("cls");
                            opcion.menuRemoverProducto();
                            break;
                        case 2:
                            system("cls");
                            opcion.menuRemoverCliente();
                            break;
                        case 3:
                            system("cls");
                            opcion.menuRemoverCompra();
                            break;
                        case 4:
                            system("cls");
                            opcion.menuRemoverVenta();
                            break;
                    }
                    break;
            }
            break;
        case 2: // -------- RECUPERAR REGISTRO ------------
            system("cls");
            cout<<"1 - Recuperar producto"<<endl;
            cout<<"2 - Recuperar cliente"<<endl;
            cout<<"3 - Recuperar compra"<<endl;
            cout<<"4 - Recuperar venta"<<endl;
            cout<<"Seleccione una opcion: ";
            cin>>opc;

            switch(opc){
                case 1:
                    opcion.menuRecuperarProducto();
                    break;
                case 2:
                    opcion.menuRecuperarCliente();
                    break;
                case 3:
                    opcion.menuRecuperarCompra();
                    break;
                case 4:
                    opcion.menuRecuperarVenta();
                    break;
            }
            break;
        case 3: // --------- LISTADOS -------------
            system("cls");
            cout<<"1 - Listados de productos"<<endl;
            cout<<"2 - Listado de clientes"<<endl;
            cout<<"3 - Listado de proveedores"<<endl;
            cout<<"4 - Listados de compras/ventas"<<endl;
            cout<<"Seleccione una opcion: ";
            cin>>opc;

            switch(opc){
                case 1:
                    system("cls");
                    cout<<"PRODUCTOS"<<endl;
                    cout<<"1 - Listado normal"<<endl;
                    cout<<"2 - Listado ordenado por categorias"<<endl;
                    cout<<"3 - Listado ordenado por proveedores"<<endl;
                    cout<<"Seleccione una opcion: ";
                    cin>>opc;
                    switch(opc){
                        case 1:
                            system("cls");
                            opcion.menuListadoProductos();
                            break;
                        case 2:
                            system("cls");
                            opcion.menuListadoPxCategoria();
                            break;
                        case 3:
                            system("cls");
                            opcion.menuListadoPxProveedor();
                            break;
                    }
                    break;
                case 2:
                    system("cls");
                    opcion.menuListadoClientes();
                    break;
                case 3:
                    system("cls");
                    opcion.menuListadoProveedores();
                    break;
                case 4:
                    system("cls");
                    cout<<"COMPRAS Y VENTAS"<<endl;
                    cout<<"1 - Listado de compras normal"<<endl;
                    cout<<"2 - Listado de compras ordenados por total"<<endl;
                    cout<<"3 - Listado de ventas normal"<<endl;
                    cout<<"4 - Listado de ventas ordenados por total"<<endl;
                    cin>>opc;
                    switch(opc){
                        case 1:
                            system("cls");
                            opcion.menuListadoCompras();
                            break;
                        case 2:
                            system("cls");
                            opcion.menuListadoComprasxTotal();
                            break;
                        case 3:
                            system("cls");
                            opcion.menuListadoVentas();
                            break;
                        case 4:
                            system("cls");
                            opcion.menuListadoVentasxTotal();
                            break;
                    }
                    break;

            }
            break;
        default:
            cout << "error";
    }

    return 0;
}
