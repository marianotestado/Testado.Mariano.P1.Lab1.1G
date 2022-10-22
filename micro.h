#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED
#include "empresa.h"
#include "tipo.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

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
int altaMicro(eMicro lista[], int tam, int* pId,eEmpresa empresas[], int tamLoc, eTipo tipos[]);
int confirmaSalida(char* r);
int buscarLibre(eMicro lista[], int tam);
int modificarMicros(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc);
int menuModificacion();
int ordenarMicros(eMicro lista[], int tam);
