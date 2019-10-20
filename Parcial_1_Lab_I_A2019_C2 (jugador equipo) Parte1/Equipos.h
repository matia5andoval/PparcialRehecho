#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    char nombre[51];
    char localidad[50];
    char tipo[50];
    int codigo;
    int estado;
} eEquipo;

void hardcodeoE(eEquipo listaEquipos[], int cant);

eEquipo cargarEquipo();
int inicializarEquipos(eEquipo* listaEquipos, int cant);
int buscarEqLibre(eEquipo listaEquipos[], int cant);
int cargarListadoEquipos(eEquipo listaEquipos[], int cant, int lastCodigo);
void mostrarEquipo(eEquipo unEquipo);
void mostrarListadoEquipos(eEquipo listaEquipos[], int cant);
int buscarCodigo(eEquipo listaEquipos[], int cant);
int modificarE(eEquipo listaEquipo[], int cant);
