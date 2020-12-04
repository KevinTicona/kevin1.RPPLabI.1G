#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

typedef struct{
    int id; //autoincremental apartir de 1000
    char descripcion [20];
}eEquipo;


#endif // EQUIPOS_H_INCLUDED

void mostrarEquipo(eEquipo listEquipo);
int mostrarEquipos(eEquipo listEquipo[], int len);
int findEquipoById(eEquipo list[], int len,int id);
int obtenerDescripcionEquipo(eEquipo lista[], int len, int ID, char descripcion[]);
