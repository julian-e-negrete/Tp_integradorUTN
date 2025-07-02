#include "Persona.h"
#pragma once

class Cliente: public Persona{
private:
    char _telefonoCliente[20];
    char _mailCliente[20];
public:
    Cliente();
    Cliente(int idPersona, char* nombrePersona, char* apellidoPersona, char* telefonoCliente, char* mailCliente);

    char* getTelefonoCliente();
    char* getMailCliente();

    void setTelefonoCliente(char*);
    void setMailCliente(char*);

    void cargarCliente(int idPersona);
    std::string toCSV();
};

