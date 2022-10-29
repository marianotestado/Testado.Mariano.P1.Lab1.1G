#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED


/** \brief
 *
 * \param tipos[] eTipo pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eTipo.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 *
 */
int mostrarTipos(eTipo tipos[], int tam);
/** \brief
 *
 * \param id int pidel el id que se encuentra dentro de eTipo para poder mostrarlo.
 * \param tipos[] eTipo pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eTipo.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int validarIdTipo(int id, eTipo tipos[], int tam);
/** \brief
 *
 * \param tipos[] eTipo eTipo pide la direccion de memoria del array de estructura.
 * \param tam int  pide el tamanio del array de eTipo.
 * \param idTipo int pide un id para poder cargar la descripcion correspondiente.
 * \param descripcionTipo[] char pide la descripcion que se encuentra en eTipo.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int cargarDescripcionTipo(eTipo tipos[],int tam,int idTipo, char descripcionTipo[]);
