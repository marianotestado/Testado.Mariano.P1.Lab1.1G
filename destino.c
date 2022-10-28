#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "destino.h"
#include "empresa.h"
#include "tipo.h"


int mostrarDestinos(eDestino destinos[], int tam)
{
    int todoOk = 0;

    if(destinos != NULL && tam > 0)
    {
        system("cls");
        printf("   ID       Destino\n");
        printf("-----------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("  %02d      %-10s  \n", destinos[i].id, destinos[i].descripcion);

        }
        todoOk = 1;

    }

    return todoOk;
}

int validarIdDestino(int id, eDestino destinos[], int tamD)
{
    int todoOk = 0;

    if(destinos != NULL && tamD > 0 && id > 0)
    {

        for(int i=0; i < tamD; i++)
        {
            if(destinos[i].id == id)
                {
                    todoOk = 1;
                    break;
                }

        }

    }

    return todoOk;
}

int cargarDescripcionDestino(eDestino destinos[],int tamD,int idDestino, char descripcion[])
{

    int todoOk = 0;
    int flag = 1;

    if(destinos != NULL && tamD > 0 && descripcion != NULL && idDestino > 0)
    {
        todoOk = 1;
        for(int i=0; i < tamD; i++)
        {
            if(destinos[i].id == idDestino)
                {
                    strcpy(descripcion, destinos[i].descripcion);
                    flag = 0;
                    break;
                }

        }


        if(flag)
        {
            todoOk = -1;
        }

    }

    return todoOk;

}

