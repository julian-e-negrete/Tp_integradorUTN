#include <string>
#include "ArchivoProducto.h"
#include "Producto.h"
#include "ArchivoCliente.h"
#include "Cliente.h"
#include "ArchivoCompra.h"
#include "Compra.h"
#include "ArchivoVenta.h"
#include "Venta.h"

class Menu{

public:
    //ABM
    bool menuGuardarProducto();
    bool menuRemoverProducto();
    bool menuRecuperarProducto();
    bool menuGuardarCliente();
    bool menuRemoverCliente();
    bool menuRecuperarCliente();
    bool menuGuardarCompra();
    bool menuRemoverCompra();
    bool menuRecuperarCompra();
    bool menuGuardarVenta();
    bool menuRemoverVenta();
    bool menuRecuperarVenta();

    //LISTADOS
    void menuListadoProductos();
    void menuListadoPxCategoria();
    void menuListadoPxProveedor();

    void menuListadoClientes();

    void menuListadoProveedores();

    void menuListadoCompras();
    void menuListadoComprasxTotal();

    void menuListadoVentas();
    void menuListadoVentasxTotal();

    //CONSULTAS
};
