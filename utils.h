#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Categoria.h"
#include "ArchivoCategorias.h"
#include "Supermercados.h"
#include "ArchivoSupermercados.h"
#include "Provincias.h"
#include "ArchivoProvincias.h"
#include "Localidades.h"
#include "ArchivoLocalidades.h"
#include "Productos.h"
#include "ArchivoSupermercado_Producto.h"

void cargarCadena(char *pal, int tam);
void waitForKey(const char* msg = "Presione ENTER para continuar...");

Categoria SeleccionarCategoria();
Supermercados SeleccionarSupermercado();
Provincias SeleccionarProvincias();
Localidades SeleccionarLocalidades(int id_provincia);
void tolower_string(char *str);
void mostrarProducto(Productos producto_obj);

#endif // UTILS_H
