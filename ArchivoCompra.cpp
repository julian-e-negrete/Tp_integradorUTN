#include "ArchivoCompra.h"

ArchivoCompra::ArchivoCompra(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoCompra::Guardar_C(Compra compra){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&compra, sizeof(Compra), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoCompra::Guardar_C(Compra compra, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Compra) * posicion, SEEK_SET);
    bool ok = fwrite(&compra, sizeof(Compra), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoCompra::Buscar_C(int idCompra){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Compra compra;
    int i = 0;
    while(fread(&compra, sizeof(Compra), 1, pArchivo)){
        if(compra.getIDCompra() == idCompra){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Compra ArchivoCompra::Leer_C(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Compra();
    }
    Compra compra;
    fseek(pArchivo, sizeof(Compra) * posicion, SEEK_SET);
    fread(&compra, sizeof(Compra), 1, pArchivo);
    fclose(pArchivo);
    return compra;
}

int ArchivoCompra::CantidadRegistros_C(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Compra);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoCompra::Leer_C(int cantidadRegistros, Compra *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Compra), 1, pArchivo);
    }
    fclose(pArchivo);
}

