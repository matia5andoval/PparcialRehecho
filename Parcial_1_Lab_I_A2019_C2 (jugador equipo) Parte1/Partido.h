#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Referi.h"
#include "jugadores.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFechaP;

typedef struct
{
    eFechaP fechaPartido;
    int codReferi;
    int codEquipoLoc;
    int codEquipoVis;
    int codigo;
    int estado;
} ePartido;

void hardcodeoP(ePartido listaPartido[], int cant);

void mostrarFechaP(eFechaP unaFecha, char mensaje[]);
eFechaP cargarFechaP(char mensaje[]);
ePartido cargarPartido(eEquipo listaEquipos[], eReferi listaReferies[], int cant);
char buscarUnCodigo(eEquipo codEq[], eReferi codRef[], int codValido);
int inicializarPartido(ePartido* listaPartidos, int cant);
int cargarListadoPartido(ePartido listaPartidos[],eEquipo listaEquipos[], eReferi listaReferies[], int cant, int lastCodigo);
void mostrarPartido(ePartido unPart);
void mostrarListadoPartidos(ePartido listaPartidos[], int cant);
int buscarPartLibre(ePartido listaPartido[], int cant);
