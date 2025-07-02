#include "Persona.h"
#include <cstring>

// CONSTRUCTORES
Persona::Persona(){
    _idPersona = 0;
    strcpy(_nombrePersona, " ");
    strcpy(_apellidoPersona, " ");
    _estadoPersona = true;
}

Persona::Persona(int idPersona, char* nombrePersona, char* apellidoPersona){
    _idPersona = idPersona;
    strcpy(_nombrePersona, nombrePersona);
    strcpy(_apellidoPersona, apellidoPersona);
    _estadoPersona = true;
}

//GETTERS
int Persona::getIDPersona(){
    return _idPersona;
}
char* Persona::getNombrePersona(){
    return _nombrePersona;
}
char* Persona::getApellidoPersona(){
    return _apellidoPersona;
}
bool Persona::getEstadoPersona(){
    return _estadoPersona;
}


//SETTERS
void Persona::setIDPersona(int idPersona){
    _idPersona = idPersona;
}
void Persona::setNombrePersona(char* nombrePersona){
    strcpy(_nombrePersona, nombrePersona);
}
void Persona::setApellidoPersona(char* apellidoPersona){
    strcpy(_apellidoPersona, apellidoPersona);
}
void Persona::setEstadoPersona(bool estadoPersona){
    _estadoPersona = estadoPersona;
}
