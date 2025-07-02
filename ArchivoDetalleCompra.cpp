#include "ArchivoDetalleCompra.h"

ArchivoDetalleCompra::ArchivoDetalleCompra(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoDetalleCompra::Guardar_DC(DetalleCompra detalleCompra){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&detalleCompra, sizeof(DetalleCompra), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoDetalleCompra::Guardar_DC(DetalleCompra detalleCompra, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(DetalleCompra) * posicion, SEEK_SET);
    bool ok = fwrite(&detalleCompra, sizeof(DetalleCompra), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoDetalleCompra::Buscar_DC(int idDetalleCompra){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    DetalleCompra detalleCompra;
    int i = 0;
    while(fread(&detalleCompra, sizeof(DetalleCompra), 1, pArchivo)){
        if(detalleCompra.getIDCompra_DC() == idDetalleCompra){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

DetalleCompra ArchivoDetalleCompra::Leer_DC(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return DetalleCompra();
    }
    DetalleCompra detalleCompra;
    fseek(pArchivo, sizeof(DetalleCompra) * posicion, SEEK_SET);
    fread(&detalleCompra, sizeof(DetalleCompra), 1, pArchivo);
    fclose(pArchivo);
    return detalleCompra;
}

int ArchivoDetalleCompra::CantidadRegistros_DC(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(DetalleCompra);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoDetalleCompra::Leer_DC(int cantidadRegistros, DetalleCompra *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(DetalleCompra), 1, pArchivo);
    }
    fclose(pArchivo);
}

