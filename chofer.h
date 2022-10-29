#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}eChofer;

#endif // CHOFER_H_INCLUDED


/** \brief
 *
 * \param choferes[] eChofer pide la direccion de memoria del array de estructura.
 * \param tam int ide el tamanio del array de eChofer.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int mostrarChoferes(eChofer choferes[], int tam);
/** \brief
 *
 * \param id int pide el id del chofer para mostrarlo.
 * \param choferes[] eChofer pide la direccion de memoria del array de estructura.
 * \param tam int  pide el tamanio del array de eChofer.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int validarIdChofer(int id, eChofer choferes[], int tam);
/** \brief
 *
 * \param choferes[] eChofer pide la direccion de memoria del array de estructura.
 * \param tam int  pide el tamanio del array de eChofer.
 * \param idChofer int pide el id del chofer.
 * \param nombreChofer[] char pide un array para cargar el nombre del chofer.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int cargarNombreChofer(eChofer choferes[],int tam,int idChofer, char nombreChofer[]);
