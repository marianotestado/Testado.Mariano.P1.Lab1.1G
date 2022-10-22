#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
}eDestino;

#endif // DESTINO_H_INCLUDED


int mostrarDestinos(eDestino destinos[], int tam);
