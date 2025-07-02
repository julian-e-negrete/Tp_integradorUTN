#include "ArchivoCategoria.h"

ArchivoCategoria::ArchivoCategoria(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoCategoria::Guardar_CA(Categoria categoria){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&categoria, sizeof(Categoria), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoCategoria::Guardar_CA(Categoria categoria, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Categoria) * posicion, SEEK_SET);
    bool ok = fwrite(&categoria, sizeof(Categoria), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoCategoria::Buscar_CA(int idCategoria){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Categoria categoria;
    int i = 0;
    while(fread(&categoria, sizeof(Categoria), 1, pArchivo)){
        if(categoria.getIDCategoria() == idCategoria){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Categoria ArchivoCategoria::Leer_CA(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Categoria();
    }
    Categoria categoria;
    fseek(pArchivo, sizeof(Categoria) * posicion, SEEK_SET);
    fread(&categoria, sizeof(Categoria), 1, pArchivo);
    fclose(pArchivo);
    return categoria;
}

int ArchivoCategoria::CantidadRegistros_CA(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Categoria);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoCategoria::Leer_CA(int cantidadRegistros, Categoria *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Categoria), 1, pArchivo);
    }
    fclose(pArchivo);
}

