#include "ArchivoCliente.h"

ArchivoCliente::ArchivoCliente(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoCliente::Guardar_CL(Cliente cliente){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoCliente::Guardar_CL(Cliente cliente, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Cliente) * posicion, SEEK_SET);
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoCliente::Buscar_CL(int idCliente){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Cliente cliente;
    int i = 0;
    while(fread(&cliente, sizeof(Cliente), 1, pArchivo)){
        if(cliente.getIDPersona() == idCliente){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Cliente ArchivoCliente::Leer_CL(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Cliente();
    }
    Cliente cliente;
    fseek(pArchivo, sizeof(Cliente) * posicion, SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return cliente;
}

int ArchivoCliente::CantidadRegistros_CL(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Cliente);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoCliente::Leer_CL(int cantidadRegistros, Cliente *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Cliente), 1, pArchivo);
    }
    fclose(pArchivo);
}

