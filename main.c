#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "micro.h"
#include "destino.h"
#include "empresa.h"
#include "tipo.h"
#include "viaje.h"


#define TAM 10
#define TAM_EMPTIP 4
#define TAM_V 10








int main()
{

    char seguir = 's';
    int nextId = 10000;
    int nextIdViaje = 100000;
    int flagAltaMicro = 0;
    int flagAltaViaje = 0;
    eMicro lista[TAM];
    eViaje viajes[TAM_V];


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

    if(!inicializarMicros(lista, TAM))
    {
        printf("Problema al inicializar Micros.\n");
    }

    if(!inicializarViajes(viajes, TAM_V))
    {
        printf("Problema al inicializar Viajes.\n");
    }


    do
    {
        fflush(stdin);
        switch(menu())
        {
            case 'a':
                if(!altaMicro(lista,TAM,&nextId, empresas, TAM_EMPTIP, tipos, &flagAltaMicro))
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
                if(flagAltaMicro == 1)
                {

                    if(!modificarMicros(lista,TAM,empresas,tipos, TAM_EMPTIP))
                    {
                        system("cls");
                        printf("No se pudo realizar la modificacion.");
                    }
                    else
                    {   system("cls");
                        printf("Modificacion Exitosa.\n");
                    }

                }
                else
                {
                    system("cls");
                    printf("Error, no existen micros dados de alta.\n");
                }

                break;
            case 'c':
                if(flagAltaMicro == 1)
                {
                    if(!bajaMicro(lista, TAM, empresas,tipos, TAM_EMPTIP, &flagAltaMicro))
                    {
                        system("cls");
                        printf("No se pudo realizar la baja.");
                    }
                    else
                    {
                        system("cls");
                        printf("Baja Exitosa.\n");
                    }
                }
                else
                {
                    system("cls");
                    printf("Error, no existen micros dados de alta.\n");
                }

                break;
            case 'd':
                if(flagAltaMicro == 1)
                {
                   mostrarMicros(lista, TAM, empresas,tipos, TAM_EMPTIP);
                }
                else
                {
                    system("cls");
                    printf("Error, no existen micros dados de alta.\n");
                }
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
            case 'h':
                if(flagAltaMicro == 1)
                {
                   altaViaje(viajes,TAM_V,lista, TAM, &nextIdViaje,empresas, TAM_EMPTIP,destinos, TAM_EMPTIP,tipos, &flagAltaViaje);
                }
                else
                {
                    system("cls");
                    printf("Error, no existen micros dados de alta.\n");
                }

                break;
            case 'i':
                if(flagAltaViaje == 1)
                {
                    mostrarViajes(viajes, TAM_V,lista,TAM,empresas,TAM_EMPTIP, destinos, TAM_EMPTIP);
                }
                else
                {
                    system("cls");
                    printf("No existen viajes dados de alta.\n");
                }

                break;
            case 'j':
                confirmaSalida(&seguir);
                break;

            default:
                printf("Opcion Invalida.\n");
                break;


        }
        printf("Hola mundo.");
        system("pause");

    }while(seguir == 's');


    return 0;
}
