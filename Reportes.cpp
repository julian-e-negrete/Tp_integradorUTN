#include "Reportes.h"
#include "ArchivoSupermercado_Producto.h"
#include "ArchivoSupermercados.h"
#include "ArchivoFavoritos.h"
#include "ArchivoUsuarios.h"
#include "ArchivoProductos.h"
#include "ArchivoCategorias.h"
#include "ArchivoCompras.h"
#include "utils.h"

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

void informeInventarioPorSupermercado() {
    ArchivoSupermercado_Producto archSP("supermercado_producto.dat");
    ArchivoSupermercados archS("supermercados.dat");

    int totalSP = archSP.contarRegistros();
    map<int, float> acumulado; // id_supermercado -> total precio

    for (int i = 0; i < totalSP; i++) {
        Supermercado_Producto sp = archSP.leerRegistro(i);
        acumulado[sp.getIdSupermercado()] += sp.getPrecio();
    }

    system("clear");
    cout << "Valor total de los productos listados por supermercado:\n\n";
    // cabecera
    cout << left << setw(30) << "SUPERMERCADO" << right << setw(12) << "TOTAL" << "\n";
    cout << string(42, '-') << "\n";
    for (auto &p : acumulado) {
        int id = p.first;
        float total = p.second;
        string nombre = "(sin nombre)";
        int nS = archS.contarRegistros();
        for (int j = 0; j < nS; j++) {
            Supermercados tmp = archS.leerRegistro(j);
            if (tmp.getIdSupermercado() == id) {
                nombre = tmp.getNombre();
                break;
            }
        }
        cout << left << setw(30) << nombre << right << setw(12) << fixed << setprecision(2) << total << "\n";
    }
    waitForKey();
}

void informeFavoritosPorUsuario() {
    ArchivoFavoritos archF("favoritos.dat");
    ArchivoUsuarios archU("usuarios.dat");

    int nF = archF.contarRegistros();
    map<int, int> cuenta; // id_usuario -> cantidad de favoritos

    for (int i = 0; i < nF; i++) {
        Favoritos f = archF.leerRegistro(i);
        cuenta[f.getIdUsuario()]++;
    }

    system("clear");
    cout << "Cantidad de supermercados marcados como favoritos por usuario:\n\n";
    cout << left << setw(20) << "USUARIO" << setw(30) << "CORREO" << right << setw(10) << "CANT" << "\n";
    cout << string(60, '-') << "\n";
    int nU = archU.contarRegistros();
    for (auto &p : cuenta) {
        int id = p.first;
        int cant = p.second;
        string nombre = "(desconocido)";
        string correo = "";
        for (int j = 0; j < nU; j++) {
            Usuarios u = archU.leerRegistro(j);
            if (u.getIdUsuario() == id) {
                nombre = u.getNombre();
                correo = u.getCorreo();
                break;
            }
        }
        cout << left << setw(20) << nombre << setw(30) << correo << right << setw(10) << cant << "\n";
    }
    waitForKey();
}

void informePrecioPromedioPorCategoria() {
    ArchivoSupermercado_Producto archSP("supermercado_producto.dat");
    ArchivoProductos archP("productos.dat");
    ArchivoCategorias archC("categorias.dat");

    int nSP = archSP.contarRegistros();
    map<int, pair<float,int>> datos; // id_categoria -> {sumaPrecios, cantidad}

    for (int i = 0; i < nSP; i++) {
        Supermercado_Producto sp = archSP.leerRegistro(i);
        int idProd = sp.getIdProducto();
        int idCat = 0;
        int nP = archP.contarRegistros();
        for (int j = 0; j < nP; j++) {
            Productos tmp = archP.leerRegistro(j);
            if (tmp.getIdProducto() == idProd) {
                idCat = tmp.getIdCategoria();
                break;
            }
        }
        if (idCat != 0) {
            datos[idCat].first += sp.getPrecio();
            datos[idCat].second += 1;
        }
    }

    system("clear");
    cout << "Precio promedio de los productos por categor\u00eda:\n\n";
    cout << left << setw(30) << "CATEGORIA" << right << setw(12) << "PROMEDIO" << setw(8) << "CANT" << "\n";
    cout << string(50, '-') << "\n";
    int nC = archC.contarRegistros();
    for (auto &p : datos) {
        int idCat = p.first;
        float sum = p.second.first;
        int cnt = p.second.second;
        float prom = (cnt > 0) ? sum / cnt : 0;
        string nombre = "(sin categor\u00eda)";
        for (int j = 0; j < nC; j++) {
            Categoria tmp = archC.leerRegistro(j);
            if (tmp.getIdCategoria() == idCat) {
                nombre = tmp.getNombre();
                break;
            }
        }
        cout << left << setw(30) << nombre
             << right << setw(12) << fixed << setprecision(2) << prom
             << setw(8) << cnt << "\n";
    }
    waitForKey();
}

void informeProductosPorCategoria() {
    ArchivoProductos archP("productos.dat");
    ArchivoCategorias archC("categorias.dat");

    int nP = archP.contarRegistros();
    map<int, int> cuenta; // id_categoria -> cantidad de productos

    for (int i = 0; i < nP; i++) {
        Productos prod = archP.leerRegistro(i);
        cuenta[prod.getIdCategoria()]++;
    }

    system("clear");
    cout << "Cantidad de productos registrados en cada categor\u00eda:\n\n";
    cout << left << setw(30) << "CATEGORIA" << right << setw(10) << "CANT" << "\n";
    cout << string(40, '-') << "\n";
    int nC = archC.contarRegistros();
    for (auto &p : cuenta) {
        int idCat = p.first;
        int cnt = p.second;
        string nombre = "(sin categor\u00eda)";
        for (int j = 0; j < nC; j++) {
            Categoria tmp = archC.leerRegistro(j);
            if (tmp.getIdCategoria() == idCat) {
                nombre = tmp.getNombre();
                break;
            }
        }
        cout << left << setw(30) << nombre << right << setw(10) << cnt << "\n";
    }
    waitForKey();
}

void informeComprasPorUsuario() {
    ArchivoCompras archC("compras.dat");
    ArchivoUsuarios archU("usuarios.dat");
    
    int nC = archC.contarRegistros();
    map<int, float> gasto; // id_usuario -> monto total

    for (int i = 0; i < nC; i++) {
        Compras c = archC.leerRegistro(i);
        gasto[c.getIdUsuario()] += c.getPrecio();
    }

    system("clear");
    cout << "Monto total gastado por usuario:\n\n";
    cout << left << setw(20) << "USUARIO" << setw(30) << "CORREO" << right << setw(12) << "TOTAL" << "\n";
    cout << string(62, '-') << "\n";
    int nU = archU.contarRegistros();
    for (auto &p : gasto) {
        int id = p.first;
        float monto = p.second;
        string nombre = "(desconocido)";
        string correo = "";
        for (int j = 0; j < nU; j++) {
            Usuarios u = archU.leerRegistro(j);
            if (u.getIdUsuario() == id) {
                nombre = u.getNombre();
                correo = u.getCorreo();
                break;
            }
        }
        cout << left << setw(20) << nombre << setw(30) << correo << right << setw(12) << fixed << setprecision(2) << monto << "\n";
    }
    waitForKey();
}

void informeDetalleCompras() {
    ArchivoCompras archC("compras.dat");
    ArchivoUsuarios archU("usuarios.dat");
    ArchivoProductos archP("productos.dat");
    ArchivoSupermercados archS("supermercados.dat");

    int nC = archC.contarRegistros();
    system("clear");
    cout << "Detalle de todas las compras:\n\n";
    // encabezado amplio
    cout << left << setw(6) << "ID" << setw(20) << "USUARIO" << setw(30) << "CORREO"
         << setw(30) << "PRODUCTO" << setw(20) << "SUPERMERCADO" << right << setw(10) << "PRECIO" << setw(12) << "FECHA" << "\n";
    cout << string(128, '-') << "\n";
    for (int i = 0; i < nC; i++) {
        Compras c = archC.leerRegistro(i);
        string nombreU = "(usu.)";
        string correo = "";
        for (int j = 0; j < archU.contarRegistros(); j++) {
            Usuarios u = archU.leerRegistro(j);
            if (u.getIdUsuario() == c.getIdUsuario()) {
                nombreU = u.getNombre();
                correo = u.getCorreo();
                break;
            }
        }
        string nombreP = "(prod.)";
        for (int j = 0; j < archP.contarRegistros(); j++) {
            Productos ptemp = archP.leerRegistro(j);
            if (ptemp.getIdProducto() == c.getIdProducto()) {
                nombreP = ptemp.getNombre();
                break;
            }
        }
        string nombreS = "(super)";
        for (int j = 0; j < archS.contarRegistros(); j++) {
            Supermercados st = archS.leerRegistro(j);
            if (st.getIdSupermercado() == c.getIdSupermercado()) {
                nombreS = st.getNombre();
                break;
            }
        }
        cout << left << setw(6) << c.getIdCompra()
             << setw(20) << nombreU << setw(30) << correo
             << setw(30) << nombreP << setw(20) << nombreS
             << right << setw(10) << fixed << setprecision(2) << c.getPrecio()
             << setw(12) << c.getFecha() << "\n";
    }
    waitForKey();
}

void informeGastoPorSupermercado() {
    ArchivoCompras archC("compras.dat");
    ArchivoSupermercados archS("supermercados.dat");
    int nC = archC.contarRegistros();
    map<int, float> gasto; // id_supermercado -> monto
    for (int i = 0; i < nC; i++) {
        Compras c = archC.leerRegistro(i);
        gasto[c.getIdSupermercado()] += c.getPrecio();
    }
    system("clear");
    cout << "Monto gastado en cada supermercado:\n\n";
    cout << left << setw(30) << "SUPERMERCADO" << right << setw(12) << "TOTAL" << "\n";
    cout << string(42, '-') << "\n";
    int nS = archS.contarRegistros();
    for (auto &p : gasto) {
        int id = p.first;
        float total = p.second;
        string nombre = "(desconocido)";
        for (int j = 0; j < nS; j++) {
            Supermercados s = archS.leerRegistro(j);
            if (s.getIdSupermercado() == id) {
                nombre = s.getNombre();
                break;
            }
        }
        cout << left << setw(30) << nombre << right << setw(12) << fixed << setprecision(2) << total << "\n";
    }
    waitForKey();
}

void informeRecaudacionAnual() {
    ArchivoCompras archC("compras.dat");
    int nC = archC.contarRegistros();
    map<int, float> porAnio; // año -> total

    for (int i = 0; i < nC; i++) {
        Compras c = archC.leerRegistro(i);
        // fecha en formato YYYY-MM-DD
        int anio = 0;
        if (strlen(c.getFecha()) >= 4) {
            // atoi stops at first non-digit, so "2026-02-23" -> 2026
            anio = atoi(c.getFecha());
        }
        porAnio[anio] += c.getPrecio();
    }

    system("clear");
    cout << "Recaudacion por año:\n\n";
    cout << left << setw(6) << "ANIO" << right << setw(12) << "TOTAL" << "\n";
    cout << string(18, '-') << "\n";
    for (auto &p : porAnio) {
        cout << left << setw(6) << p.first << right << setw(12) << fixed << setprecision(2) << p.second << "\n";
    }
    waitForKey();
}

void menuReportes() {
    int opcion;
    bool salir = false;
    while (!salir) {
        system("clear");
        cout << "=== INFORMES ===\n";
        cout << "1) Valor inventario por supermercado\n";
        cout << "2) Precio promedio por categor\u00eda\n";
        cout << "3) Cantidad de productos por categor\u00eda\n";
        cout << "4) Compras por usuario\n";
        cout << "5) Detalle de compras\n";
        cout << "6) Recaudacion anual\n";
        cout << "7) Gasto por supermercado\n";
        cout << "9) VOLVER\n";
        cin >> opcion;
        switch (opcion) {
            case 1: informeInventarioPorSupermercado(); break;
            case 2: informePrecioPromedioPorCategoria(); break;
            case 3: informeProductosPorCategoria(); break;
            case 4: informeComprasPorUsuario(); break;
            case 5: informeDetalleCompras(); break;
            case 6: informeRecaudacionAnual(); break;
            case 7: informeGastoPorSupermercado(); break;
            case 9: salir = true; break;
            default:
                cout << "Opcion invalida" << endl;
                waitForKey();
        }
    }
}
