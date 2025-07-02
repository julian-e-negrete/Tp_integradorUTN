#include "ArchivoVenta.h"

ArchivoVenta::ArchivoVenta(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoVenta::Guardar_V(Venta venta){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&venta, sizeof(Venta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoVenta::Guardar_V(Venta venta, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Venta) * posicion, SEEK_SET);
    bool ok = fwrite(&venta, sizeof(Venta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoVenta::Buscar_V(int idVenta){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Venta venta;
    int i = 0;
    while(fread(&venta, sizeof(Venta), 1, pArchivo)){
        if(venta.getIDVenta() == idVenta){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Venta ArchivoVenta::Leer_V(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Venta();
    }
    Venta venta;
    fseek(pArchivo, sizeof(Venta) * posicion, SEEK_SET);
    fread(&venta, sizeof(Venta), 1, pArchivo);
    fclose(pArchivo);
    return venta;
}

int ArchivoVenta::CantidadRegistros_V(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Venta);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoVenta::Leer_V(int cantidadRegistros, Venta *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Venta), 1, pArchivo);
    }
    fclose(pArchivo);
}

