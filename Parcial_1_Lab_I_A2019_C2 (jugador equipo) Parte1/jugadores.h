#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipos.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFechaJ;

typedef struct
{
    char nombre[50];
    char apellido[50];
    char sexo;
    eFechaJ fechaNacimiento;
    int codigoDeEquipo;
    int estado;
    int codigo;
} eJugadores;

void hardcodeoJ(eJugadores listaJugadores[], int cant);

eFechaJ cargarFechaJ(char mensaje[]);

eJugadores cargarJugador(eEquipo listaEquipos[], int cant);
int inicializarJugadores(eJugadores* listaJugadores, int cant);
int cargarListadoJugadores(eJugadores listaJugadores[],eEquipo listaEquipos[], int cant, int lastCodigo);
int buscarJugLibre(eJugadores listaPartidos[], int cant);
void mostrarJugadores(eJugadores unJugador);
void mostrarListadoJugadores(eJugadores listaJugadores[], int cant);
