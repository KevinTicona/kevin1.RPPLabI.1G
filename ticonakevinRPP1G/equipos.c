#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "equipos.h"

void mostrarEquipo(eEquipo listEquipo)
{
    printf("  %d    %20s        \n", listEquipo.id, listEquipo.descripcion);
}

int mostrarEquipos(eEquipo listEquipo[], int len)
{
    int error = -1;
    if(listEquipo != NULL && len > 0)
    {
        printf("             Equipos         \n"     );
        printf("--------------------------------------n");
        printf("   Id               Descripcion        \n");
        printf("-------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            mostrarEquipo(listEquipo[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int findEquipoById(eEquipo list[], int len,int id)
{
    int indice = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                indice = list[i].id;
                break;
            }
        }
    }
    return indice;
}

int obtenerDescripcionEquipo(eEquipo lista[], int len, int ID, char descripcion[])
{
    int error = -1;

    if(lista != NULL && descripcion != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(descripcion,lista[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;
}
