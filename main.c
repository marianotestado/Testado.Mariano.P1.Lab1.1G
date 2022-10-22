#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "micro.h"
#include "destino.h"
#include "empresa.h"
#include "tipo.h"


#define TAM 10
#define TAM_EMPTIP 4








int main()
{

    char seguir = 's';
    int nextId = 10000;
    eMicro lista[TAM];


    eDestino destinos[4] = {
        {20000,"Calafate: $22250"},
        {20001,"Bariloche: $103000"},
        {20002,"Salta: $84400"},
        {20003,"Mendoza: $95600"},

    };

    eEmpresa empresas[4] = {
        {1000,"Plusmar"},
        {1001,"Flecha Bus"},
        {1002,"Tas"},
        {1003,"El Rapido"},

    };

    eTipo tipos[4] = {
        {5000,"Comun"},
        {5001,"CocheCama"},
        {5002,"Doble"},
        {5003,"Vip"},

    };

    if( !inicializarMicros(lista, TAM))
    {
        printf("Problema al inicializar.\n");
    }


    do
    {
        fflush(stdin);
        switch(menu())
        {
            case 'a':
                if(!altaMicro(lista,TAM,&nextId, empresas, TAM_EMPTIP, tipos))
                {
                    system("cls");
                    printf("No se pudo realizar el alta.\n");
                }
                else
                {
                    system("cls");
                    printf("Alta Exitosa.\n");
                }
                break;
            case 'b':
                if(!modificarMicros(lista,TAM,empresas,tipos, TAM_EMPTIP))
                {
                    system("cls");
                    printf("No se pudo realizar la modificacion.");
                }
                else
                {   system("cls");
                    printf("Modificacion Exitosa.\n");
                }
                break;
            case 'c':
                if(!bajaMicro(lista, TAM, empresas,tipos, TAM_EMPTIP))
                {
                    system("cls");
                    printf("No se pudo realizar la baja.");
                }
                else
                {
                    system("cls");
                    printf("Baja Exitosa.\n");
                }
                break;
            case 'd':
                mostrarMicros(lista, TAM, empresas,tipos, TAM_EMPTIP);
                break;
            case 'e':
                 mostrarEmpresas(empresas, TAM_EMPTIP);
                 break;
            case 'f':
                mostrarTipos(tipos, TAM_EMPTIP);
                break;
            case 'g':
                mostrarDestinos(destinos, TAM_EMPTIP);
                break;
            case 'j':
                confirmaSalida(&seguir);
                break;

            default:
                printf("Opcion Invalida!!!\n");
                break;


        }
        system("pause");

    }while(seguir == 's');


    return 0;
}
