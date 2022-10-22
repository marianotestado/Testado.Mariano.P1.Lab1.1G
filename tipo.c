#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "empresa.h"
#include "tipo.h"


int mostrarTipos(eTipo tipos[], int tam)
{
    int todoOk = 0;

    if(tipos != NULL && tam > 0)
    {
        system("cls");
        printf("   ID       Tipos de micro\n");
        printf("-----------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("  %02d      %-10s  \n", tipos[i].id, tipos[i].descripcion);

        }
        todoOk = 1;

    }

    return todoOk;
}

int validarIdTipo(int id, eTipo tipos[], int tam)
{
    int todoOk = 0;

    if(tipos != NULL && tam > 0 && id > 0)
    {

        for(int i=0; i < tam; i++)
        {
            if(tipos[i].id == id)
                {
                    todoOk = 1;
                    break;
                }

        }

    }

    return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[],int tam,int idTipo, char descripcionTipo[])
{

    int todoOk = 0;
    int flag = 1;

    if(tipos != NULL && tam > 0 && descripcionTipo != NULL)
    {
        todoOk = 1;
        for(int i=0; i < tam; i++)
        {
            if(tipos[i].id == idTipo)
                {
                    strcpy(descripcionTipo, tipos[i].descripcion);
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
