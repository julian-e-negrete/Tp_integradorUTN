#include "Cliente.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

Cliente::Cliente()
: Persona(){
    strcpy(_telefonoCliente, " ");
    strcpy(_mailCliente, " ");
}

Cliente::Cliente(int idPersona, char* nombrePersona, char* apellidoPersona, char* telefonoCliente, char* mailCliente)
: Persona(idPersona, nombrePersona, apellidoPersona){
    _idPersona = idPersona;
    strcpy(_nombrePersona, nombrePersona);
    strcpy(_apellidoPersona, apellidoPersona);
    strcpy(_telefonoCliente, telefonoCliente);
    strcpy(_mailCliente, mailCliente);
}

//GETTERS
char* Cliente::getTelefonoCliente(){
    return _telefonoCliente;
}
char* Cliente::getMailCliente(){
    return _mailCliente;
}

//SETTERS
void Cliente::setTelefonoCliente(char* telefonoCliente){
    strcpy(_telefonoCliente, telefonoCliente);
}
void Cliente::setMailCliente(char* mailCliente){
    strcpy(_mailCliente, mailCliente);
}

void Cliente::cargarCliente(int idPersona){
    _idPersona = idPersona;
    cout << "Nombre del cliente: ";
    cin >> _nombrePersona;
    cout << "Apellido: ";
    cin >> _apellidoPersona;
    cout << "Telefono: ";
    cin >> _telefonoCliente;
    cout << "Mail: ";
    cin >> _mailCliente;
    _estadoPersona = true;
}

std::string Cliente::toCSV(){

    std::string strCl = std::to_string((int)_idPersona) + "," + _nombrePersona + "," + _apellidoPersona + "," + _telefonoCliente + "," + _mailCliente;
    return strCl;
}

