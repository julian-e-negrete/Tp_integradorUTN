#include "ArchivoSupermercado_Producto.h"
#include <cstdio>
#include <cstring>

ArchivoSupermercado_Producto::ArchivoSupermercado_Producto(const char *n)
{
    strcpy(nombre, n);
}
Supermercado_Producto ArchivoSupermercado_Producto::leerRegistro(int pos)
{
    Supermercado_Producto reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return reg;
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}
int ArchivoSupermercado_Producto::contarRegistros()
{
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Supermercado_Producto);
}
bool ArchivoSupermercado_Producto::grabarRegistro(Supermercado_Producto reg)
{
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    int escribio=fwrite(&reg, sizeof reg,1, p);
    fclose(p);
    return escribio;
}
