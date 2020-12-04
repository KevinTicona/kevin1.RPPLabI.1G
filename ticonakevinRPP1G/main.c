#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cliente.h"
#include "validaciones.h"
#include "cliente.h"
#include "menu.h"
#include "equipos.h"
#include "alquiler.h"

#define TAM_C 10
#define TAM_A 10
#define TAM_E 3
int main()
{
    int validNewCliente;
    int validModificacion;
    int validBaja;
    int validNewAlquiler;

    int idCliente = 20;
    int idAlquiler = 100;
    int menuPrincipal;
    int menuPrincipal_opcionSeleccionada;

    eCliente listClientes[TAM_C];
    eAlquiler listAlquiler[TAM_A];

    eEquipo listaEquipos[TAM_E] =
    {
        {1000, "Limpieza"},
        {1001, "Parche"},
        {1002, "Centrado"},
    };


    inicializar_Cliente(listClientes,TAM_C);
    inicializar_Alquiler(listAlquiler, TAM_A);
    do
    {
        menu_principal();
        menuPrincipal = validaciones_obtenerOpcion
                        (
                            &menuPrincipal_opcionSeleccionada,
                            "\nOpcion invalida, intente nuevamente\n",
                            1,
                            7
                        );
        if(!menuPrincipal)
        {
            switch(menuPrincipal_opcionSeleccionada)
            {

            case 1:
                validNewCliente = altaCliente(listClientes,TAM_C,idCliente);
                if(validNewCliente == 0)
                {
                    printf("\nOperacion exitosa\n");
                    idCliente++;
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                mostrarClientes(listClientes,TAM_C);
                break;
            case 2:
                validModificacion = modificarCliente(listClientes,TAM_C);
                if(!validModificacion)
                {
                    printf("\nModificacion exitosa.\n");
                }
                else if(validModificacion == 1)
                {
                    printf("\nModificacion cancelada por usuario.\n");
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                break;
            case 3:
                validBaja = bajaCliente(listClientes, TAM_C);
                if(!validBaja)
                {
                    printf("\nBaja exitosa.\n");
                }
                else if(validBaja == 1)
                {
                    printf("\nBaja cancelada por usuario.\n");
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                break;
            case 4:
                validNewAlquiler = altaAquiler(listAlquiler,TAM_A, idAlquiler, listClientes, TAM_C, listaEquipos, TAM_E);
                if(validNewAlquiler == 0)
                {
                    printf("\nOperacion exitosa\n");
                    idAlquiler++;
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                mostrarAlquileres(listAlquiler, TAM_A, listClientes, TAM_C, listaEquipos, TAM_E);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while( menuPrincipal_opcionSeleccionada != 12);

    return 0;
}
