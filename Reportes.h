#ifndef REPORTES_H
#define REPORTES_H

// encabezados de clases usadas en los informes
#include "Supermercados.h"
#include "Usuarios.h"
#include "Productos.h"
#include "Categoria.h"
#include "Favoritos.h"
#include "Supermercado_Producto.h"
#include "Compras.h"

// prototipos de funciones de reporte
void informeInventarioPorSupermercado();          // similar a "recaudaci\u00f3n anual" (valor total de productos)
void informeFavoritosPorUsuario();               // parecido a "recaudaci\u00f3n por cliente" (cantidad de favoritos)
void informePrecioPromedioPorCategoria();        // parecido a "recaudaci\u00f3n por t\u00edtulo" (precio promedio)
void informeProductosPorCategoria();             // como "libros vendidos por g\u00e9nero" (cantidad por categor\u00eda)

// compras: nuevo conjunto de informes
void informeComprasPorUsuario();                // cu\u00e1nto gast\u00f3 cada usuario
void informeDetalleCompras();                   // listar cada compra con supermercado, producto y precio
void informeRecaudacionAnual();                 // monto total facturado por a\u00f1o (usa fecha)
void informeGastoPorSupermercado();            // monto gastado en cada supermercado

// menu que agrupa los informes
void menuReportes();

#endif // REPORTES_H
