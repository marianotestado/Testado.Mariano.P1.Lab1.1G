#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
}eDestino;

#endif // DESTINO_H_INCLUDED


/** \brief
 *
 * \param destinos[] eDestino pide los valores de la estructura eDestino.
 * \param tam int pidel el valor del tamanio del array.
 * \return int devuelve 1 si esta todo ok o 0 si surgio un error.
 *
 */
int mostrarDestinos(eDestino destinos[], int tam);
/** \brief
 *
 * \param id int pide el id ingresado por el usuario para validarlo
 * \param destinos[] eDestino pide los datos del array de estructura eDestino.
 * \param tamD int pide el tamanio del array.
 * \return int devuelve 1 si esta todo ok o 0 si surgio un error.
 *
 */
int validarIdDestino(int id, eDestino destinos[], int tamD);
/** \brief
 *
 * \param destinos[] eDestino pide los datos del array de estructura eDestino.
 * \param tamD int int pide el tamanio del array.
 * \param idDestino int pide el id del destino cuya descripcion se quiere cargar.
 * \param descripcion[] char pide el array de string auxiliar para sobreescribirlo.
 * \return int
 *
 */
int cargarDescripcionDestino(eDestino destinos[],int tamD,int idDestino, char descripcion[]);
