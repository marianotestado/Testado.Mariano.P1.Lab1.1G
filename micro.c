#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "micro.h"
#include "empresa.h"
#include "tipo.h"
#include "chofer.h"
#include "viaje.h"



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
    printf("         ABM Micros      \n\n");
    printf("A- Alta Micro\n");
    printf("B- Modificar Micro\n");
    printf("C- Baja Micro\n");
    printf("D- Listar Micros\n");
    printf("E- Listar Empresas\n");
    printf("F- Listar Tipos\n");
    printf("G- Listar Destinos\n");
    printf("H- Alta Viaje\n");
    printf("I- Listar Viajes\n");;
    printf("J- Informes.\n");
    printf("K- Salir\n");
    printf("Ingrese Opcion: ");
    opcion = tolower(getchar());\

    return opcion;
}

int altaMicro(eMicro lista[], int tam, int* pId,eEmpresa empresas[], int tamLoc, eTipo tipos[], int* flag, eChofer choferes[])
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

            printf("Ingrese Chofer: ");
            mostrarChoferes(choferes, tamLoc);
            fflush(stdin);
            scanf("%d", &auxMicro.idChofer);
            while(!validarIdChofer(auxMicro.idChofer, choferes, tamLoc))
            {
                mostrarChoferes(choferes, tamLoc);
                printf("Ingrese id chofer valida: ");
                scanf("%d", &auxMicro.idChofer);
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

void mostrarMicro(eMicro p, eEmpresa empresas[], int tam, eTipo tipos[], int capacidad, eChofer choferes[])
{

    char descEmpresa[20];
    char descTipo[20];
    char nombreChofer[20];

    if(cargarDescripcionEmpresa(empresas, tam, p.idEmpresa, descEmpresa)==1 &&
       cargarDescripcionTipo(tipos, tam, p.idTipo, descTipo) == 1 &&
       cargarNombreChofer(choferes, tam, p.idChofer, nombreChofer) == 1)
    {
        printf("  %02d     %-10s   %-10s   %02d     %-10s                              \n", p.id,
                                                                           descEmpresa,
                                                                           descTipo,
                                                                           capacidad,
                                                                           nombreChofer
                                                                           );
    }




}

int mostrarMicros(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc, eChofer choferes[])
{

    int todoOk = 0;



    if(lista != NULL && tam > 0)
    {
        ordenarMicros(lista,tam);

        system("cls");
        printf("                      Lista de Micros    \n");
        printf("---------------------------------------------------------------\n");
        printf("  ID       Empresa       Tipo      Capacidad     Chofer\n\n");
        printf("---------------------------------------------------------------\n");

        for(int i=0; i < tam ; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarMicro(lista[i], empresas, tamLoc, tipos , lista[i].capacidad,choferes);
            }

        }

        todoOk = 1;
    }

    return todoOk;


}

int bajaMicro(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc, int* flag, eChofer choferes[])
{
    int todoOk = 0;
    int indice;
    int id;
    int flagVacio = 0;
    char confirma;
    if(lista != NULL && tam > 0)
    {
        mostrarMicros(lista, tam, empresas, tipos, tamLoc, choferes);
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
            mostrarMicro(lista[indice], empresas, tamLoc, tipos, lista[indice].capacidad, choferes);

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

int modificarMicros(eMicro lista[], int tam, eEmpresa empresas[],eTipo tipos[], int tamLoc, eChofer choferes[])
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    int auxEmpresa;
    int auxTipo;
    int auxCapacidad;
    int auxChofer;

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
            mostrarMicro(lista[indice], empresas, tamLoc, tipos, lista[indice].capacidad, choferes);
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
                case 4:
                    printf("Ingrese Chofer: ");
                    fflush(stdin);
                    mostrarChoferes(choferes, tamLoc);
                    scanf("%d",&auxChofer);

                    while(!validarIdChofer(auxChofer, choferes, tamLoc))
                    {
                        mostrarChoferes(choferes, tamLoc);
                        printf("Ingrese id de chofer valida: ");
                        scanf("%d", &auxChofer);
                    }
                    lista[indice].idChofer = auxChofer;
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
    printf("4-Chofer\n");

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


//    Informes

int menuInformes()
{
    int opcion;
    system("cls");
    printf("         Informes      \n\n");
    printf("1- Mostrar micros de una empresa.\n");
    printf("2- Mostrar micros de un tipo.\n");
    printf("3- Promedios de micros VIP.\n");
    printf("4- Listado de micros por empresa.\n");
    printf("5- Empresa con mayor capacidad.\n");
    printf("6- Empresa con menor cantidad de micros.\n");
    printf("7- Cantidad de viajes de un micro.\n");
    printf("8- Costo de los viajes de un micro.\n");
    printf("9- Micros que viajaron a un destino.\n");;
    printf("10- Viajes por fecha.\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int mostrarMicrosIdEmpresa(int id,eMicro lista[], int tam, eEmpresa empresas[], int tamLoc, eTipo tipos[], eChofer choferes[])
{

    int flag = 1;
    int todoOk = 0;

    if(id > 0 && lista != NULL && tam>0 && empresas != NULL && tamLoc > 0)
    {


        printf("                      Lista de Micros    \n");
        printf("---------------------------------------------------------------\n");
        printf("  ID       Empresa       Tipo      Capacidad     Nombre Chofer\n\n");
        printf("---------------------------------------------------------------\n");
        for(int i=0; i < tam ; i++)
        {
            if(!lista[i].isEmpty)
                {
                    if(!lista[i].isEmpty && id == lista[i].idEmpresa)
                    {
                        mostrarMicro(lista[i],empresas,tam,tipos, lista[i].capacidad, choferes);;
                        flag = 0;
                    }
                }

        }

        if(flag)
        {
            printf("\nNo hay micros de esa empresa.\n");
        }
        todoOk = 1;
    }

    return todoOk;
}

int mostrarMicrosEmpresa(eMicro lista[], int tam, eEmpresa empresas[], int tamLoc, eTipo tipos[], eChofer  choferes[])
{


    int idEmpresa;
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {

        system("cls");
        printf("                      Micros de la empresa    \n");

        mostrarEmpresas(empresas, tamLoc);
        printf("Ingrese id empresa: ");
        scanf("%d", &idEmpresa);

        while(!validarIdEmpresa(idEmpresa, empresas, tamLoc))
        {
            mostrarEmpresas(empresas, tamLoc);
            printf("Ingrese id empresa valida: ");
            scanf("%d", &idEmpresa);
        }
        system("cls");
        mostrarMicrosIdEmpresa(idEmpresa, lista, tam, empresas, tamLoc, tipos, choferes);

        todoOk = 1;
    }

    return todoOk;


}

int mostrarMicrosIdTipo(int id,eMicro lista[], int tam, eTipo tipos[], int tamLoc, eEmpresa empresas[], eChofer choferes[])
{

    int flag = 1;
    int todoOk = 0;

    if(id > 0 && lista != NULL && tam>0 && empresas != NULL && tamLoc > 0)
    {


        printf("                      Lista de Micros    \n");
        printf("---------------------------------------------------------------\n");
        printf("  ID       Empresa       Tipo      Capacidad     Nombre Chofer \n\n");
        printf("---------------------------------------------------------------\n");
        for(int i=0; i < tam ; i++)
        {
            if(!lista[i].isEmpty)
                {
                    if(!lista[i].isEmpty && id == lista[i].idTipo)
                    {
                        mostrarMicro(lista[i],empresas,tam,tipos, lista[i].capacidad, choferes);;
                        flag = 0;
                    }
                }

        }

        if(flag)
        {
            printf("\nNo hay micros de ese tipo.\n");
        }
        todoOk = 1;
    }

    return todoOk;
}

int mostrarMicrosTipo(eMicro lista[], int tam, eTipo tipos[], int tamLoc, eEmpresa empresas[], eChofer choferes[])
{


    int idTipo;
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {

        system("cls");
        printf("                      Micros del tipo    \n");

        mostrarTipos(tipos, tamLoc);
        printf("Ingrese id tipo: ");
        scanf("%d", &idTipo);

        while(!validarIdTipo(idTipo, tipos, tamLoc))
        {
            mostrarTipos(tipos, tamLoc);
            printf("Ingrese id tipo valida: ");
            scanf("%d", &idTipo);
        }
        system("cls");
        mostrarMicrosIdTipo(idTipo, lista, tam, tipos, tamLoc, empresas, choferes);

        todoOk = 1;
    }

    return todoOk;


}


int informarPromedioVipEmpresa(eMicro lista[], int tam, eTipo tipos[], int tamLoc, eEmpresa empresas[])
{
    int todoOk = 0;
    int idEmpresa;
    int contadorTotal = 0;
    int contadorVip = 0;
    float promedio;
    if(lista != NULL && tam > 0 && tipos != NULL && tamLoc > 0)
    {
        system("cls");

        mostrarEmpresas(empresas, tamLoc);
        printf("Ingrese id empresa: ");
        scanf("%d", &idEmpresa);

        while(!validarIdEmpresa(idEmpresa, empresas, tamLoc))
        {
            mostrarEmpresas(empresas, tamLoc);
            printf("Ingrese id empresa valida: ");
            scanf("%d", &idEmpresa);
        }

        for(int i=0; i < tamLoc; i++)
        {

            for(int j=0; j < tam ; j++)
            {
                if(!lista[j].isEmpty && lista[j].idTipo == tipos[i].id)
                {
                    if(lista[j].idEmpresa == idEmpresa)
                    {
                        contadorTotal++;
                        if(lista[j].idTipo == 5003)
                        {
                            contadorVip++;
                        }
                    }

                }

            }



        }

        if(contadorVip > 0)
        {
            promedio = (float) (contadorVip * 100) / contadorTotal;
            printf("Porcentaje de micros VIP: %.2f\n\n", promedio);
        }
        else
        {
            printf("No existen micros VIP para esa empresa.\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int mostrarMicrosAllEmpresas(eMicro lista[], int tam, eEmpresa empresas[], int tamLoc,eTipo tipos[],eChofer choferes[])
{


    int todoOk = 0;

    system("cls");
    printf("Micros de cada empresa   \n");
    if(lista != NULL && tam > 0)
    {

        for(int i=0; i < tamLoc; i++ )
        {
            printf("---------------------------------------------------------------\n");
            printf("%10s                              \n", empresas[i].descripcion);
            printf("---------------------------------------------------------------\n");
            mostrarMicrosIdEmpresa(empresas[i].id, lista, tam, empresas, tamLoc, tipos, choferes);
            printf("\n\n");
        }

        todoOk = 1;
    }

    return todoOk;



}

int mostrarMayorCapacidad(eMicro lista[], int tam, eEmpresa empresas[], int tamLoc, eTipo tipos[])
{
    int todoOk = 0;
    int acumuladores[tamLoc];
    int mayor;

    for(int i=0; i < tamLoc; i++)
        {
            for(int j=0; j < tam ; j++)
            {

                acumuladores[i] = 0;
            }
        }


    if(lista != NULL && tam > 0 && empresas != NULL && tamLoc > 0)
    {
        system("cls");
        printf("      Empresa con mayor capacidad.\n");
        printf("================================================\n\n");
        for(int i=0; i < tamLoc; i++)
        {
            for(int j=0; j < tam ; j++)
            {
                if(!lista[j].isEmpty && lista[j].idEmpresa == empresas[i].id)
                {
                    acumuladores[i]+= lista[i].capacidad;
                }

            }


        }
        for(int i=0; i<tamLoc ; i++)
            {
                if(i==0 || acumuladores[i] > mayor)
                {
                    mayor = acumuladores[i];
                }
            }
            for(int i=0; i < tamLoc ; i++)
            {
                if(acumuladores[i] == mayor)
                {
                    printf("%s con %d espacios de capacidad total.\n\n",empresas[i].descripcion, acumuladores[i]);
                }
            }
        todoOk = 1;
    }
    return todoOk;
}


int empresaMenorCantMicros(eMicro lista[], int tam, eEmpresa empresas[], int tamLoc, eTipo tipos[])
{
    int todoOk = 0;
    int contadores[tamLoc];
    int menor;

    for(int i=0; i < tamLoc; i++)
        {
            for(int j=0; j < tam ; j++)
            {

                contadores[i] = 0;
            }
        }


    if(lista != NULL && tam > 0 && empresas != NULL && tamLoc > 0)
    {
        system("cls");
        printf("      Empresa con menos cantidad de micros.\n");
        printf("================================================\n\n");
        for(int i=0; i < tamLoc; i++)
        {
            for(int j=0; j < tam ; j++)
            {
                if(!lista[j].isEmpty && lista[j].idEmpresa == empresas[i].id)
                {
                    contadores[i]++;
                }

            }


        }
        for(int i=0; i<tamLoc ; i++)
            {
                if(i==0 || contadores[i] < menor)
                {
                    menor = contadores[i];
                }
            }
            for(int i=0; i<tamLoc ; i++)
            {
                if(contadores[i] == menor)
                {
                    printf("%s con %d cantidad de micros.\n\n",empresas[i].descripcion, contadores[i]);
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
