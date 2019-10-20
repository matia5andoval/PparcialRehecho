#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFechaR;

typedef struct
{
    int codigo;
    char nombre[31];
    char apellido[31];
    char sexo;
    char email[31];
    eFechaR fechaNacimiento;
    int estado;
} eReferi;


void hardcodeoR(eReferi listaReferies[], int cant);

eFechaR cargarFechaR(char mensaje[]);

int inicializarReferi(eReferi* listaReferis, int cant);
int buscarRefLibre(eReferi listaReferis[], int cant);
int cargarListadoReferies(eReferi listaReferies[], int cant, int lastCodigo);
void mostrarReferi(eReferi unRefe);
void mostrarListadoReferi(eReferi listaReferies[], int cant);
int buscarCodigoR(eReferi listaReferis[], int cant, int elCod);
int modificarR(eReferi listaReferis[], int cant, int elCod);
