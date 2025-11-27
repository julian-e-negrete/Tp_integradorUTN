#include "ArchivoFavoritos.h"
#include <cstdio>
#include <cstring>

ArchivoFavoritos::ArchivoFavoritos(const char *n)
{
    strcpy(nombre, n);
}
Favoritos ArchivoFavoritos::leerRegistro(int pos)
{
    Favoritos reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return reg;
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}
int ArchivoFavoritos::contarRegistros()
{
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Favoritos);
}
bool ArchivoFavoritos::grabarRegistro(Favoritos reg)
{
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    int escribio=fwrite(&reg, sizeof reg,1, p);
    fclose(p);
    return escribio;
}
