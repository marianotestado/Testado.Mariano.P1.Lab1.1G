#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "micro.h"
#include "empresa.h"
#include "tipo.h"


int inicializarMicros(eMicro lista[], int tam)
{

    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;



}

int menu()
{
    char opcion;
    system("cls");
    printf("         ABM Personas      \n\n");
    printf("A- Alta Micro\n");
    printf("B- Modificar Micro\n");
    printf("C- Baja Micro\n");
    printf("D- Listar Micros\n");
    printf("E- Listar Empresas\n");
    printf("F- Listar Tipos\n");
    printf("G- Listar Destinos\n");
    printf("H- Alta Viaje\n");
    printf("I- Listar Viajes\n");;
    printf("J- Salir\n");
    printf("Ingrese Opcion: ");
    opcion = tolower(getchar());\

    return opcion;
}

int altaMicro(eMicro lista[], int tam, int* pId,eEmpresa empresas[], int tamLoc, eTipo tipos[], int* flag)
{


    int todoOk = 0;
    int indice;
    eMicro auxMicro;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("         Alta Persona       \n\n");

        indice = buscarLibre(lista,tam);
        if(indice == -1)
        {
            printf("No hay lugar.");
        }
        else
        {

            auxMicro.id = *pId;
            (*pId)++;
            printf("Ingrese Empresa: ");
            fflush(stdin);
            mostrarEmpresas(empresas, tamLoc);
            scanf("%d",&auxMicro.idEmpresa);

            while(!validarIdEmpresa(auxMicro.idEmpresa, empresas, tamLoc))
            {
                mostrarEmpresas(empresas, tamLoc);
                printf("Ingrese id empresa valida: ");
                scanf("%d", &auxMicro.idEmpresa);
            }

            printf("Ingrese Tipo: ");
            mostrarTipos(tipos, tamLoc);
            fflush(stdin);
            scanf("%d", &auxMicro.idTipo);
            while(!validarIdTipo(auxMicro.idTipo, tipos, tamLoc))
            {
                mostrarTipos(tipos, tamLoc);
                printf("Ingrese id tipo valida: ");
                scanf("%d", &auxMicro.idTipo);
            }

            system("cls");
            printf("Ingrese capacidad: ");
            scanf("%d", &auxMicro.capacidad);
            while(auxMicro.capacidad < 0 || auxMicro.capacidad >= 51)
            {
                system("cls");
                printf("Ingrese una capacidad entre 0 y 50: ");
                scanf("%d", &auxMicro.capacidad);
            }



            auxMicro.isEmpty = 0;

            lista[indice] = auxMicro;

            *flag = 1;

        }
        todoOk = 1;
    }

    return todoOk;


}

int confirmaSalida(char* r)
{

    int respuesta = 0;
    char salir;


    if(r != NULL)
    {
        printf("Desea continuar? (s/n)\n");
        fflush(stdin);
        salir = tolower(getchar());
        if(salir == 'n' || salir == 'N')
        {
            *r = 'n';

        }


        respuesta = 1;

    }
    return respuesta;

}

int buscarLibre(eMicro lista[], int tam)
{
    int indice = -1;
    for(int i=0 ; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;



}

void mostrarMicro(eMicro p, eEmpresa empresas[], int tam, eTipo tipos[], int capacidad)
{

    char descEmpresa[20];
    char descTipo[20];

    if(cargarDescripcionEmpresa(empresas, tam, p.idEmpresa, descEmpresa)==1 &&
       cargarDescripcionTipo(tipos, tam, p.idTipo, descTipo) == 1)
    {
        printf("  %02d     %-10s   %-10s   %02d                              \n", p.id,
                                                                           descEmpresa,
                                                                           descTipo,
                                                                           capacidad
                                                                           );
    }




}

int mostrarMicros(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc)
{

    int todoOk = 0;



    if(lista != NULL && tam > 0)
    {
        ordenarMicros(lista,tam);

        system("cls");
        printf("                      Lista de Micros    \n");
        printf("---------------------------------------------------------------\n");
        printf("  ID       Empresa       Tipo      Capacidad\n\n");
        printf("---------------------------------------------------------------\n");

        for(int i=0; i < tam ; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarMicro(lista[i], empresas, tamLoc, tipos , lista[i].capacidad);
            }

        }

        todoOk = 1;
    }

    return todoOk;


}

int bajaMicro(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc, int* flag)
{
    int todoOk = 0;
    int indice;
    int id;
    int flagVacio = 0;
    char confirma;
    if(lista != NULL && tam > 0)
    {
        mostrarMicros(lista, tam, empresas, tipos, tamLoc);
        printf("-------------------------------------------------\n");
        printf("     Baja Micro     ");
        printf("|  Ingrese ID: ");
         scanf("%d", &id);
        printf("-------------------------------------------------\n");




        indice = buscarMicroId(lista, tam, id);

        if(indice == -1)
        {
            printf("El id: %d no esta en el sistema.\n", id);
        }
        else
        {
            mostrarMicro(lista[indice], empresas, tamLoc, tipos, lista[indice].capacidad);

            printf("Confirma baja? (s para confirmar): ");
            fflush(stdin);
            confirma = tolower(getchar());

            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("baja cancelada por el usuario.\n");
            }
        }
        for(int i=0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                flagVacio = 1;
            }
            *flag = flagVacio;
        }


    }

    return todoOk;

}

int buscarMicroId(eMicro lista[], int tam, int id)
{
    int indice = -1;
    for(int i=0 ; i < tam; i++)
    {
        if(!lista[i].isEmpty && lista[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;

}

int modificarMicros(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    int auxEmpresa;
    int auxTipo;
    int auxCapacidad;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("     Modificar Micro     \n\n");
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = buscarMicroId(lista, tam, id);

        if(indice == -1)
        {
            printf("El id: %d no esta en el sistema.\n", id);
        }
        else
        {
            mostrarMicro(lista[indice], empresas, tamLoc, tipos, lista[indice].capacidad);
            printf("Confirma modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                switch(menuModificacion())
                {
                case 1:
                    printf("Ingrese Empresa: ");
                    fflush(stdin);
                    mostrarEmpresas(empresas, tamLoc);
                    scanf("%d",&auxEmpresa);

                    while(!validarIdEmpresa(auxEmpresa, empresas, tamLoc))
                    {
                        mostrarEmpresas(empresas, tamLoc);
                        printf("Ingrese id de empresa valida: ");
                        scanf("%d", &auxEmpresa);
                    }
                    lista[indice].idEmpresa = auxEmpresa;
                    break;
                case 2:
                    printf("Ingrese Tipo: ");
                    fflush(stdin);
                    mostrarTipos(tipos, tamLoc);
                    scanf("%d",&auxTipo);

                    while(!validarIdTipo(auxTipo, tipos, tamLoc))
                    {
                        mostrarTipos(tipos, tamLoc);
                        printf("Ingrese id de tipo valida: ");
                        scanf("%d", &auxTipo);
                    }
                    lista[indice].idTipo = auxTipo;
                    break;

                case 3:
                    printf("Ingrese nueva capacidad: ");
                    fflush(stdin);
                    scanf("%d", &auxCapacidad);
                    lista[indice].capacidad = auxCapacidad;
                    break;


                default:
                    printf("Opcion Invalida.\n");



                }
                todoOk = 1;
            }
            else
            {
                printf("Modificacion cancelada.\n");
            }
        }

    }

    return todoOk;
}

int menuModificacion()
{
    int opcion;
    printf("         Que desea modificar?     \n");
    printf("----------------------------------\n\n");
    printf("1-Empresa\n");
    printf("2-Tipo\n");
    printf("3-Capacidad\n");

    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int ordenarMicros(eMicro lista[], int tam)
{

    int todoOk= 0;
    eMicro auxMicro;

    if(lista != NULL && tam > 0)
    {

        for(int i=0; i < tam; i++)
        {
            for(int j=i+1; j < tam; j++)
            {
                if((lista[i].idEmpresa > lista[j].idEmpresa) ||
                   (lista[i].idEmpresa == lista[j].idEmpresa &&
                    lista[i].capacidad >  lista[j].capacidad
                    )
                   )
                {
                    auxMicro = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMicro;
                }

            }
        }


        todoOk =1;
    }

    return todoOk;
}


