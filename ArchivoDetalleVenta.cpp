#include "ArchivoDetalleVenta.h"

ArchivoDetalleVenta::ArchivoDetalleVenta(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoDetalleVenta::Guardar_DV(DetalleVenta detalleVenta){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&detalleVenta, sizeof(DetalleVenta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoDetalleVenta::Guardar_DV(DetalleVenta detalleVenta, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(DetalleVenta) * posicion, SEEK_SET);
    bool ok = fwrite(&detalleVenta, sizeof(DetalleVenta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoDetalleVenta::Buscar_DV(int idDetalleVenta){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    DetalleVenta detalleVenta;
    int i = 0;
    while(fread(&detalleVenta, sizeof(DetalleVenta), 1, pArchivo)){
        if(detalleVenta.getIDVenta_DV() == idDetalleVenta){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

DetalleVenta ArchivoDetalleVenta::Leer_DV(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return DetalleVenta();
    }
    DetalleVenta detalleVenta;
    fseek(pArchivo, sizeof(DetalleVenta) * posicion, SEEK_SET);
    fread(&detalleVenta, sizeof(DetalleVenta), 1, pArchivo);
    fclose(pArchivo);
    return detalleVenta;
}

int ArchivoDetalleVenta::CantidadRegistros_DV(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(DetalleVenta);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoDetalleVenta::Leer_DV(int cantidadRegistros, DetalleVenta *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(DetalleVenta), 1, pArchivo);
    }
    fclose(pArchivo);
}

