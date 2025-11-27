#include "Favoritos.h"

int Favoritos::getIdFavorito()
{
    return id_favorito;
}
int Favoritos::getIdUsuario()
{
    return id_usuario;
}
int Favoritos::getIdSupermercado()
{
    return id_supermercado;
}

void Favoritos::setIdFavorito(int par_id)
{
    id_favorito = par_id;
}
void Favoritos::setIdUsuario(int par_id)
{
    id_usuario = par_id;
}
void Favoritos::setIdSupermercado(int par_id)
{
    id_supermercado = par_id;
}
