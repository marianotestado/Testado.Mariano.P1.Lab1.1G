#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "viaje.h"
#include "fecha.h"
#include "micro.h"
#include "tipo.h"
#include "empresa.h"
#include "destino.h"


int inicializarViajes(eViaje viajes[], int tamV)
{

    int todoOk = 0;

    if(viajes != NULL && tamV > 0)
    {
        for(int i=0; i < tamV; i++)
        {
            viajes[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;



}

int buscarLibreViaje(eViaje viajes[], int tamV)
{
    int indice = -1;
    for(int i=0 ; i < tamV; i++)
    {
        if(viajes[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;



}

int altaViaje(eViaje viajes[],int tamV, eMicro lista[], int tam, int* pIdViaje, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD,eTipo tipos[], int* flag)
{


    int todoOk = 0;
    int indice;
    eViaje auxViaje;

    if(lista != NULL && tam > 0 && viajes != NULL && tamV > 0 && empresas != NULL && tamE > 0 && destinos != NULL && tamD > 0 && pIdViaje != NULL)
    {
        system("cls");
        printf("         Alta Viaje       \n\n");
        printf("--------------------------\n\n");

        indice = buscarLibreViaje(viajes,tamV);
        if(indice == -1)
        {
            printf("No hay lugar.");
        }
        else
        {

            auxViaje.id = *pIdViaje;
            (*pIdViaje)++;

            mostrarDestinos(destinos, tamD);
            printf("Ingrese id destino: ");
            scanf("%d", &auxViaje.idDestino);

            while(!validarIdDestino(auxViaje.idDestino, destinos, tamD))
            {
                mostrarDestinos(destinos, tamD);
                printf("Ingrese id destino valida: ");
                scanf("%d", &auxViaje.idDestino);
            }

            mostrarMicros(lista, tam, empresas, tipos, tamE);
            printf("Ingrese id micro: ");
            scanf("%d", &auxViaje.idMicro);


            while(!buscarMicroId(lista, tam, auxViaje.idMicro))
            {
                mostrarMicros(lista, tam, empresas, tipos, tamE);
                printf("Ingrese id micro valida: ");
                scanf("%d", &auxViaje.idMicro);
            }

            printf("Ingrese Fecha:");
            scanf("%d/%d/%d",&auxViaje.fecha.dia,
                             &auxViaje.fecha.mes,
                             &auxViaje.fecha.anio);

            while(auxViaje.fecha.dia < 1 || auxViaje.fecha.dia > 31 ||
                  auxViaje.fecha.mes < 1 || auxViaje.fecha.mes > 12 ||
                  auxViaje.fecha.anio < 2022 || auxViaje.fecha.anio > 2030)
            {
                printf("Ingrese una Fecha valida:");
                scanf("%d/%d/%d",&auxViaje.fecha.dia,
                                 &auxViaje.fecha.mes,
                                 &auxViaje.fecha.anio);
            }


            auxViaje.isEmpty = 0;

            viajes[indice] = auxViaje;

            *flag = 1;

        }


        todoOk = 1;
    }

    return todoOk;


}

void mostrarViaje(eViaje viajes, eDestino destinos[], int tamD)
{

    char descDestino[20];

    if(cargarDescripcionDestino(destinos, tamD, viajes.idDestino, descDestino)==1)
    {
        printf("  %02d     %-10s      %02d      %02d/%02d/%d \n",  viajes.id,
                                                               descDestino,
                                                               viajes.idMicro,
                                                               viajes.fecha.dia,
                                                               viajes.fecha.mes,
                                                               viajes.fecha.anio
                                                              );
    }




}

int mostrarViajes(eViaje viajes[], int tamV, eMicro lista[], int tam, eEmpresa empresas[],int tamE, eDestino destinos[], int tamD)
{

    int todoOk = 0;


    if(lista != NULL && tam > 0 && viajes != NULL && tamV > 0 && empresas != NULL && tamE > 0 && destinos != NULL && tamD > 0)
    {

        system("cls");
        printf("                      Lista de Viajes    \n");
        printf("---------------------------------------------------------------\n");
        printf("    ID            Destino            Micro        Fecha                       \n\n");
        printf("---------------------------------------------------------------\n");

        for(int i=0; i < tam ; i++)
        {
            if(!viajes[i].isEmpty)
            {
                mostrarViaje(viajes[i], destinos, tamD);
            }

        }

        todoOk = 1;
    }

    return todoOk;


}
