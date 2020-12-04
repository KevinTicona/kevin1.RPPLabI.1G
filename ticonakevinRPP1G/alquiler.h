#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
#include "cliente.h"
#include "equipos.h"
typedef struct{
    int id;
    int idCliente;
    int idEquipo;
    int tiempo;
    char operador[51];
    int isEmpty;
}eAlquiler;


#endif // ALQUILER_H_INCLUDED
int altaAquiler(eAlquiler listAlquiler[], int tamA, int id, eCliente listCliente[], int tamC, eEquipo listEquipo[], int tamE);
int inicializar_Alquiler(eAlquiler list[], int len);
int mostrarAlquileres(eAlquiler listAlquiler[], int len, eCliente listCliente[], int tamC, eEquipo listEquipo[], int tamE);
void mostrarAlquiler(eAlquiler listAlquiler, eCliente listCliente[], int tamC, eEquipo listEquipo[], int tamE);
int obtenerDescripcionAlquiler(eAlquiler lista[], int len, int isEmpty, char descripcion[]);
int findAlquilerById(eAlquiler list[], int len,int id);
