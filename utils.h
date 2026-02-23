#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Categoria.h"

void cargarCadena(char *pal, int tam);
void waitForKey(const char* msg = "Presione ENTER para continuar...");

void tolower_string(char *str);

// obtiene la fecha actual en formato "YYYY-MM-DD" y la copia en el buffer (tam incluido)
void obtenerFechaActual(char *buffer, int tam);

#endif // UTILS_H
