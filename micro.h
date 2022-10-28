#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED
#include "empresa.h"
#include "tipo.h"


typedef struct
{
    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int isEmpty;


}eMicro;

#endif // MICRO_H_INCLUDED

int inicializarMicros(eMicro lista[], int tam);
int menu();
int altaMicro(eMicro lista[], int tam, int* pId,eEmpresa empresas[], int tamLoc, eTipo tipos[], int* flagM);
int confirmaSalida(char* r);
int buscarLibre(eMicro lista[], int tam);
void mostrarMicro(eMicro p, eEmpresa empresas[], int tam, eTipo tipos[], int capacidad);
int mostrarMicros(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc);
int bajaMicro(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc, int* flag);
int modificarMicros(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc);
int menuModificacion();
int ordenarMicros(eMicro lista[], int tam);
