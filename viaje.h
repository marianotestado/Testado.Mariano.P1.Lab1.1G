#include "fecha.h"
#include "micro.h"
#include "destino.h"
#include "tipo.h"
#include "empresa.h"

#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED

typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;

}eViaje;

#endif // VIAJES_H_INCLUDED

/** \brief
 *
 * \param viajes[] eViaje pide la direccion de memoria del array de estructura.
 * \param tamV int pide el tamanio del array de eViaje.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int inicializarViajes(eViaje viajes[], int tamV);
/** \brief
 *
 * \param viajes[] eViaje pide la direccion de memoria del array de estructura.
 * \param tamV int pide el tamanio del array de eViaje.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int buscarLibreViaje(eViaje viajes[], int tamV);
/** \brief
 *
 * \param viajes[] eViaje pide la direccion de memoria del array de estructura.
 * \param tamV int pide el tamanio del array de eViaje.
 * \param lista[] eMicro pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eMicro.
 * \param pIdViaje int* pide por puntero el id autoincremental para sobreescribirlo con cada alta.
 * \param empresas[] eEmpresa pide la direccion de memoria del array de estructura.
 * \param tamE int pide el tamanio del array de eEmpresa.
 * \param destinos[] eDestino pide la direccion de memoria del array de estructura.
 * \param tamD int pide el tamanio del array de eDestino.
 * \param tipos[] eTipo pide la direccion de memoria del array de estructura.
 * \param flag int* pide por puntero la direccion de memoria del flag de main.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int altaViaje(eViaje viajes[],int tamV, eMicro lista[], int tam, int* pIdViaje, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD,eTipo tipos[], int* flag, eChofer choferes[]);
/** \brief
 *
 * \param viajes eViaje pide la direccion de memoria del array de estructura.
 * \param destinos[] eDestino pide la direccion de memoria del array de estructura.
 * \param tamD int pide el tamanio del array de eDestino.
 * \return void
 *
 */
void mostrarViaje(eViaje viajes, eDestino destinos[], int tamD);
/** \brief
 *
 * \param viajes[] eViaje pide la direccion de memoria del array de estructura.
 * \param tamV int pide el tamanio del array de eViaje.
 * \param lista[] eMicro pide la direccion de memoria del array de estructura.
 * \param tam int pide el tamanio del array de eMicro.
 * \param empresas[] eEmpresa pide la direccion de memoria del array de estructura.
 * \param tamE int pide el tamanio del array de eEmpresa.
 * \param destinos[] eDestino pide la direccion de memoria del array de estructura.
 * \param tamD int pide el tamanio del array de eDestino.
 * \return int si esta todo Ok retorna 1, si surge un error retorna 0.
 *
 */
int mostrarViajes(eViaje viajes[], int tamV, eMicro lista[], int tam, eEmpresa empresas[],int tamE, eDestino destinos[], int tamD);
