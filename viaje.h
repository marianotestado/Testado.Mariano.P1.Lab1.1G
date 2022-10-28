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

int inicializarViajes(eViaje viajes[], int tamV);
int buscarLibreViaje(eViaje viajes[], int tamV);
int altaViaje(eViaje viajes[],int tamV, eMicro lista[], int tam, int* pIdViaje, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD,eTipo tipos[], int* flag);
void mostrarViaje(eViaje viajes, eDestino destinos[], int tamD);
int mostrarViajes(eViaje viajes[], int tamV, eMicro lista[], int tam, eEmpresa empresas[],int tamE, eDestino destinos[], int tamD);
