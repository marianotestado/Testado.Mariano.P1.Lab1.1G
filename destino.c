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
        printf("   ID       Empresa\n");
        printf("-----------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("  %02d      %-10s  \n", destinos[i].id, destinos[i].descripcion);

        }
        todoOk = 1;

    }

    return todoOk;
}
