#include "ArchivoProveedores.h"

ArchivoProveedores::ArchivoProveedores(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoProveedores::Guardar_PR(Proveedor proveedor){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoProveedores::Guardar_PR(Proveedor proveedor, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Proveedor) * posicion, SEEK_SET);
    bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoProveedores::Buscar_PR(int idProveedor){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Proveedor proveedor;
    int i = 0;
    while(fread(&proveedor, sizeof(Proveedor), 1, pArchivo)){
        if(proveedor.getIDProveedor() == idProveedor){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Proveedor ArchivoProveedores::Leer_PR(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Proveedor();
    }
    Proveedor proveedor;
    fseek(pArchivo, sizeof(Proveedor) * posicion, SEEK_SET);
    fread(&proveedor, sizeof(Proveedor), 1, pArchivo);
    fclose(pArchivo);
    return proveedor;
}

int ArchivoProveedores::CantidadRegistros_PR(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Proveedor);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoProveedores::Leer_PR(int cantidadRegistros, Proveedor *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Proveedor), 1, pArchivo);
    }
    fclose(pArchivo);
}

