#include "Compras.h"
#include <cstring>
#include <iostream>

using namespace std;

int Compras::getIdCompra() const { return id_compra; }
int Compras::getIdUsuario() const { return id_usuario; }
int Compras::getIdSupermercado() const { return id_supermercado; }
int Compras::getIdProducto() const { return id_producto; }
float Compras::getPrecio() const { return precio; }
const char* Compras::getFecha() const { return fecha; }

void Compras::setIdCompra(int id) { id_compra = id; }
void Compras::setIdUsuario(int id) { id_usuario = id; }
void Compras::setIdSupermercado(int id) { id_supermercado = id; }
void Compras::setIdProducto(int id) { id_producto = id; }
void Compras::setPrecio(float p) { precio = p; }
void Compras::setFecha(const char *f) {
    if (f != nullptr) {
        strncpy(fecha, f, 10);
        fecha[10] = '\0';
    } else {
        fecha[0] = '\0';
    }
}

void mostrarCompra(const Compras &c) {
    cout << "Compra #" << c.getIdCompra() << ": usuario=" << c.getIdUsuario()
         << ", supermercado=" << c.getIdSupermercado()
         << ", producto=" << c.getIdProducto()
         << ", precio=$" << c.getPrecio()
         << ", fecha=" << c.getFecha() << endl;
}

#include "Productos.h"
#include "ArchivoCompras.h"
#include "ArchivoSupermercado_Producto.h"
#include "ArchivoProductos.h"
#include "utils.h"
#include <iostream>

void registrarCompra(Usuarios user, Supermercados supermercado)
{
    // seleccionar producto del supermercado
    Productos prod = SeleccionarProducto_Supermercado(supermercado);
    if (prod.getIdProducto() == 0) {
        // no se eligió producto válido
        return;
    }

    // buscar precio correspondiente
    ArchivoSupermercado_Producto archSP("supermercado_producto.dat");
    int nsp = archSP.contarRegistros();
    float precio = 0.0f;
    for (int i = 0; i < nsp; i++) {
        Supermercado_Producto sp = archSP.leerRegistro(i);
        if (sp.getIdSupermercado() == supermercado.getIdSupermercado() &&
            sp.getIdProducto() == prod.getIdProducto()) {
            precio = sp.getPrecio();
            break;
        }
    }

    // crear registro de compra
    ArchivoCompras archC("compras.dat");
    Compras comp;
    int nc = archC.contarRegistros();
    if (nc > 0) {
        Compras ult = archC.leerRegistro(nc - 1);
        comp.setIdCompra(ult.getIdCompra() + 1);
    } else {
        comp.setIdCompra(1);
    }
    comp.setIdUsuario(user.getIdUsuario());
    comp.setIdSupermercado(supermercado.getIdSupermercado());
    comp.setIdProducto(prod.getIdProducto());
    comp.setPrecio(precio);
    char fecha[11];
    obtenerFechaActual(fecha, sizeof(fecha));
    comp.setFecha(fecha);

    archC.grabarRegistro(comp);
    system("clear");
    cout << "COMPRA REGISTRADA: producto " << prod.getNombre() << " por $" << precio << " el " << fecha << endl;
    waitForKey();
}
