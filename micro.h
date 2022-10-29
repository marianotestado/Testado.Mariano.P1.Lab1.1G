#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED
#include "empresa.h"
#include "tipo.h"
#include "chofer.h"


typedef struct
{
    int id;
    int idEmpresa;
    int idTipo;
    int idChofer;
    int capacidad;
    int isEmpty;


}eMicro;

#endif // MICRO_H_INCLUDED

/** \brief
 *
 * \param lista[] eMicro pide la direccion de memoria del array de estructura para poder inicializar los valores.
 * \param tam int pide el tamanio del array.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int inicializarMicros(eMicro lista[], int tam);
/** \brief
 *
 * \return int retorna la opcion elegida por el usuario
 *
 */
int menu();
/** \brief
 *
 * \param lista[] eMicro pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eMicro.
 * \param pId int* pide el id autoincremental declarado en main por puntero para poder sobreescribirlo en caso de dar un alta.
 * \param empresas[] eEmpresa pide la direccion de memoria del array de estructura.
 * \param tamLoc int pide el tamanio del array de eEmpresa.
 * \param tipos[] eTipo pide la direccion de memoria del array de estructura.
 * \param flagM int* pide el flag por puntero.
 * \return int int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int altaMicro(eMicro lista[], int tam, int* pId,eEmpresa empresas[], int tamLoc, eTipo tipos[], int* flag, eChofer choferes[]);
/** \brief
 *
 * \param r char* pide el valor de la variable que confirma la salida por puntero.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int confirmaSalida(char* r);
/** \brief
 *
 * \param lista[] eMicro pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eMicro.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int buscarLibre(eMicro lista[], int tam);
/** \brief
 *
 * \param p eMicro pide la direccion de memoria de estructura.
 * \param empresas[] eEmpresa
 * \param tam int pide el tamanio del array de eMicro.
 * \param tipos[] eTipo
 * \param capacidad int
 * \return void
 *
 */
void mostrarMicro(eMicro p, eEmpresa empresas[], int tam, eTipo tipos[], int capacidad, eChofer choferes[]);
/** \brief
 *
 * \param lista[] eMicro pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eMicro.
 * \param empresas[] eEmpresa
 * \param tipos[] eTipo
 * \param tamLoc int
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int mostrarMicros(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc, eChofer choferes[]);
/** \brief
 *
 * \param lista[] eMicro pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eMicro.
 * \param empresas[] eEmpresa
 * \param tipos[] eTipo
 * \param tamLoc int pide el tamanio del array de eEmpresa.
 * \param flag int*
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int bajaMicro(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc, int* flag, eChofer choferes[]);
/** \brief
 *
 * \param lista[] eMicro pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eMicro.
 * \param empresas[] eEmpresa pide el tamanio del array de eEmpresa.
 * \param tipos[] eTipo pide la direccion de memoria del array de estructura.
 * \param tamLoc int pide el tamanio del array de eEmpresa.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int modificarMicros(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc, eChofer choferes[]);
/** \brief
 *
 * \return int retorna el valor elegido por el usuario.
 *
 */
int menuModificacion();
/** \brief
 *
 * \param lista[] eMicro pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eMicro.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int ordenarMicros(eMicro lista[], int tam);

// informes

int menuInformes();
int mostrarMicrosIdEmpresa(int id,eMicro lista[], int tam, eEmpresa empresas[], int tamLoc, eTipo tipos[], eChofer choferes[]);
int mostrarMicrosEmpresa(eMicro lista[], int tam, eEmpresa empresas[], int tamLoc, eTipo tipos[], eChofer  choferes[]);
int mostrarMicrosAllEmpresas(eMicro lista[], int tam, eEmpresa empresas[], int tamLoc,eTipo tipos[],eChofer choferes[]);
int mostrarMayorCapacidad(eMicro lista[], int tam, eEmpresa empresas[], int tamLoc, eTipo tipos[]);
int empresaMenorCantMicros(eMicro lista[], int tam, eEmpresa empresas[], int tamLoc, eTipo tipos[]);

