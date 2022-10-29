#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "chofer.h"

int mostrarChoferes(eChofer choferes[], int tam)
{
    int todoOk = 0;

    if(choferes != NULL && tam > 0)
    {
        system("cls");
        printf("   ID       Empresa\n");
        printf("-----------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("  %02d      %-10s  \n", choferes[i].id, choferes[i].nombre);

        }
        todoOk = 1;

    }

    return todoOk;
}

int validarIdChofer(int id, eChofer choferes[], int tam)
{
    int todoOk = 0;

    if(choferes != NULL && tam > 0 && id > 0)
    {

        for(int i=0; i < tam; i++)
        {
            if(choferes[i].id == id)
                {
                    todoOk = 1;
                    break;
                }

        }

    }

    return todoOk;
}

int cargarNombreChofer(eChofer choferes[],int tam,int idChofer, char nombreChofer[])
{

    int todoOk = 0;
    int flag = 1;

    if(choferes != NULL && tam > 0 && nombreChofer != NULL)
    {
        todoOk = 1;
        for(int i=0; i < tam; i++)
        {
            if(choferes[i].id == idChofer)
                {
                    strcpy(nombreChofer, choferes[i].nombre);
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
