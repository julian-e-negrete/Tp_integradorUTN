#ifndef FAVORITOS_H
#define FAVORITOS_H

#include "Usuarios.h"

class Favoritos
{
private:
    int id_favorito;
    int id_usuario;
    int id_supermercado;

public:
    // gets
    int getIdFavorito();
    int getIdUsuario();
    int getIdSupermercado();

    // sets
    void setIdFavorito(int par_id);
    void setIdUsuario(int par_id);
    void setIdSupermercado(int par_id);
};

void  AgregarFavorito(Usuarios User, int id_supermercado);
#endif // FAVORITOS_H
