#include "ArchivoProducto.h"

ArchivoProducto::ArchivoProducto(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoProducto::Guardar_P(Producto producto){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoProducto::Guardar_P(Producto producto, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Producto) * posicion, SEEK_SET);
    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoProducto::Buscar_P(int idProducto){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Producto producto;
    int i = 0;
    while(fread(&producto, sizeof(Producto), 1, pArchivo)){
        if(producto.getIDProducto() == idProducto){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Producto ArchivoProducto::Leer_P(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Producto();
    }
    Producto producto;
    fseek(pArchivo, sizeof(Producto) * posicion, SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pArchivo);
    fclose(pArchivo);
    return producto;
}

int ArchivoProducto::CantidadRegistros_P(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Producto);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoProducto::Leer_P(int cantidadRegistros, Producto *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Producto), 1, pArchivo);
    }
    fclose(pArchivo);
}
