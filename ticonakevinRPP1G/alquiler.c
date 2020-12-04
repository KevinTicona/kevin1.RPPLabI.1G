#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "alquiler.h"
#include "cliente.h"
#include "equipos.h"
#include "validaciones.h"

int altaAquiler(eAlquiler listAlquiler[], int tamA, int id, eCliente listCliente[], int tamC, eEquipo listEquipo[], int tamE)
{
    eAlquiler newAlquiler;

    int validIdCliente;
    int validIdEquipo;

    if(listAlquiler != NULL && tamA > 0 && listCliente != NULL && tamC > 0 && listEquipo != NULL && tamE > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            if(listCliente[i].isEmpty == 1)
            {
                newAlquiler.isEmpty = 0;
                newAlquiler.id = id;

                mostrarClientes(listCliente,tamC);
                printf("\nIngrese el Id del Cliente: ");
                fflush(stdin);
                scanf("%d",&newAlquiler.idCliente);
                validIdCliente=findClienteById(listCliente,tamC,newAlquiler.idCliente);
                while(validIdCliente < 0)
                {
                    printf("\nDato invalido. Ingrese el ID del Cliente: ");
                    fflush(stdin);
                    scanf("%d",&newAlquiler.idCliente);
                    validIdCliente=findClienteById(listCliente,tamC,newAlquiler.idCliente);
                }

                mostrarEquipos(listEquipo,tamE);
                printf("\nIngrese el Id del Equipo que desea alquilar: ");
                fflush(stdin);
                scanf("%d",&newAlquiler.idEquipo);
                validIdEquipo = findEquipoById(listEquipo,tamE,newAlquiler.idEquipo);
                while(validIdEquipo < 0)
                {
                    printf("\nDato invalido. Ingrese el Id del Equipo que desea alquilar: ");
                    fflush(stdin);
                    scanf("%d",&newAlquiler.idEquipo);
                    validIdEquipo = findEquipoById(listEquipo,tamE,newAlquiler.idEquipo);
                }
                //tiempo
                printf("Ingrese el tiempo que desea alquilarlo:");
                fflush(stdin);
                scanf("%d",&newAlquiler.tiempo);

                printf("\nIngrese el Operario: ");
                fflush(stdin);
                gets(newAlquiler.operador);
                formatName(newAlquiler.operador);
                while(strlen(newAlquiler.operador) ==0 || strlen(newAlquiler.operador)> 20 )
                {
                    printf("\nNo ingreso ningun dato. Ingrese el Operario: ");
                    fflush(stdin);
                    gets(newAlquiler.operador);
                    formatName(newAlquiler.operador);
                }


                listAlquiler[i] = newAlquiler;
                return 0;
            }
            // printf("\nNo hay lugar para otra Cliente...\n");
        }
        printf("\nNo hay lugar para otro Trabajo...\n");
    }
    return -1;
}

int inicializar_Alquiler(eAlquiler list[], int len)
{
    if(list != NULL && len > 0 && len <= 100)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        return 0;
    }

    return -1;
}


void mostrarAlquiler(eAlquiler listAlquiler, eCliente listCliente[], int tamC, eEquipo listEquipo[], int tamE)
{
    char descCliente[50];
    char descEquipo[50];

    obtenerDescripcionCliente(listCliente, tamC,listAlquiler.idCliente,descCliente);
    obtenerDescripcionEquipo(listEquipo, tamE, listAlquiler.idEquipo, descEquipo);
    printf(" %d      %15s       %15s         %5d         %15s     \n",listAlquiler.id, descCliente, descEquipo, listAlquiler.tiempo, listAlquiler.operador);
}

int mostrarAlquileres(eAlquiler listAlquiler[], int len, eCliente listCliente[], int tamC, eEquipo listEquipo[], int tamE)
{
    int error = -1;
    if(listAlquiler != NULL && len > 0)
    {
        printf("                                      Alquiler         \n"     );
        printf("------------------------------------------------------------------------------------\n");
        printf("   Id           Cliente           Equipo           Tiempo          Operador         \n");
        printf("------------------------------------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            mostrarAlquiler(listAlquiler[i],listCliente,tamC,listEquipo,tamE);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int obtenerDescripcionAlquiler(eAlquiler lista[], int len, int isEmpty, char descripcion[])
{
    int error = -1;

    if(lista != NULL && descripcion != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                strcpy(descripcion,"Alquilado");
                error = 0;
                break;
            }
            else if(lista[i].isEmpty == 1)
            {
                strcpy(descripcion,"Finalizado");
                error = 0;
                break;
            }
        }
    }

    return error;
}

int bajaAlquiler(eAlquiler* listAlquiler, int tamA, eCliente listCliente[], int tamC, eEquipo listEquipo[], int tamE)
{
    int error = -1;
    int id;
    int indice;
    char confirmation;

    //La función podría devolver 3 enteros (0 - ok, -1 error, 1 ok pero no borró a nadie
    if(listAlquiler != NULL && tamA > 0 && tamA <= 100 )
    {
        mostrarAlquileres(listAlquiler,tamA, listCliente, tamC, listEquipo, tamE);
        printf("\nIngrese el Id del alquiler que desea dar Finalizado: ");
        fflush(stdin);
        scanf("%d", &id);
        indice = findAlquilerById(listAlquiler, tamA, id);
        if(indice == -1)
        {
            printf("No hay un Alquiler con ese ID\n");
        }
        else
        {
            system("cls");
        printf("------------------------------------------------------------------------------------\n");
        printf("   Id           Cliente           Equipo           Tiempo          Operador         \n");
        printf("------------------------------------------------------------------------------------\n");
            mostrarAlquiler(listAlquiler[indice], listCliente, tamC, listEquipo, tamE);
            printf("Confirmar baja? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmation);
            confirmation = tolower(confirmation);
            while(confirmation != 's' && confirmation != 'n')
            {
                printf("Opción invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmation);
                confirmation = tolower(confirmation);
            }

            if(confirmation == 's')
            {
                listAlquiler[indice].isEmpty = 1;
                error = 0;
            }
            else if(confirmation == 'n')
            {
                error = 1;
            }
        }

    }

    return error;
}


int findAlquilerById(eAlquiler list[], int len,int id)
{
    int indice = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
