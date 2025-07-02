#include <string>
#pragma once

class Persona{
protected:
    int _idPersona;
    char _nombrePersona[20], _apellidoPersona[20];
    bool _estadoPersona;
public:
    Persona();
    Persona(int idPersona, char* nombrePersona, char* apellidoPersona);

    int getIDPersona();
    char* getNombrePersona();
    char* getApellidoPersona();
    bool getEstadoPersona();

    void setIDPersona(int);
    void setNombrePersona(char*);
    void setApellidoPersona(char*);
    void setEstadoPersona(bool);
};
