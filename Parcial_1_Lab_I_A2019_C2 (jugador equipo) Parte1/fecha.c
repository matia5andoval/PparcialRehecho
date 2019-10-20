#include "fecha.h"

eFecha cargarFecha(char mensaje[])
{
    eFecha unaFecha;

    printf(mensaje);

    unaFecha.dia= getInt("Ingresar el dia, maximo 2 caracteres: ");
    unaFecha.dia= validarIntMaxMin(unaFecha.dia, "Reingrese el dia, maximo 2 caracteres:\n", 2, 0);

    unaFecha.mes= getInt("Ingresar el mes, maximo 2 caracteres: ");
    unaFecha.mes= validarIntMaxMin(unaFecha.mes, "Reingrese el mes, maximo 2 caracteres:\n", 2, 0);

    unaFecha.anio= getInt("Ingresar el anio, maximo 4 caracteres: ");
    unaFecha.anio= validarIntMaxMin(unaFecha.anio, "Reingrese el anio, maximo 4 caracteres:\n", 4, 0);


    return unaFecha;
}

void mostrarFecha(eFecha unaFecha, char mensaje[])
{
    printf(mensaje);
    printf("%2d/%2d/%4d\n", unaFecha.dia, unaFecha.mes, unaFecha.anio);
}

