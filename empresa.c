#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "empresa.h"
#include "tipo.h"


int mostrarEmpresas(eEmpresa empresas[], int tam)
{
    int todoOk = 0;

    if(empresas != NULL && tam > 0)
    {
        system("cls");
        printf("   ID       Empresa\n");
        printf("-----------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("  %02d      %-10s  \n", empresas[i].id, empresas[i].descripcion);

        }
        todoOk = 1;

    }

    return todoOk;
}

int validarIdEmpresa(int id, eEmpresa empresas[], int tam)
{
    int todoOk = 0;

    if(empresas != NULL && tam > 0 && id > 0)
    {

        for(int i=0; i < tam; i++)
        {
            if(empresas[i].id == id)
                {
                    todoOk = 1;
                    break;
                }

        }

    }

    return todoOk;
}

int cargarDescripcionEmpresa(eEmpresa empresas[],int tam,int idEmpresa, char descripcionEmpresa[])
{

    int todoOk = 0;
    int flag = 1;

    if(empresas != NULL && tam > 0 && descripcionEmpresa != NULL)
    {
        todoOk = 1;
        for(int i=0; i < tam; i++)
        {
            if(empresas[i].id == idEmpresa)
                {
                    strcpy(descripcionEmpresa, empresas[i].descripcion);
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
