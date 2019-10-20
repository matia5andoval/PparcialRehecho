#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Partido.h"
#define CANT 7

int main()
{
    eEquipo listaEquipos[CANT];
    eJugadores listaJugadores[CANT];
    eReferi listaReferies[CANT];
    ePartido listaPartidos[CANT];

    int respuesta, opcion;
    int lastCodigoE=0;
    int lastCodigoJ=0;
    int lastCodigoR=0;
    int lastCodigoP=0;

    if(inicializarPartido(listaPartidos, CANT)==0)
    {
        if(inicializarEquipos(listaEquipos, CANT)==0)
        {
            if(inicializarReferi(listaReferies, CANT)==0)
            {
                if(inicializarJugadores(listaJugadores, CANT)==0)
                {
                    do
                    {
                        printf("\t\t        PARCIAL LABORATORIO \n ***************************MENU DE ENTIDADES***************************\n\n\n");
                        printf("1.EQUIPOS\n2.JUGADORES\n3.REFEREI\n4.PARTIDOS\n5.SALIR\n\n");
                        opcion = getInt("\nSELECCIONE UN MENU:....");



                        hardcodeoP(listaPartidos, CANT);
                        //hardcodeoE(listaEquipos, CANT);
                        //hardcodeoJ(listaJugadores, CANT);
                        hardcodeoR(listaReferies, CANT);

                        switch(opcion)
                        {
                        case 1:
                            respuesta=getInt("-MENU EQUIPOS- \n 1.ALTAS\n 2.BAJAS\n 3.MODIFICAR\n 4.ORDENAR Y LISTAR\n 5.SALIR\n");
                            switch(respuesta)
                            {

                            case 1:
                                respuesta = cargarListadoEquipos(listaEquipos,CANT,lastCodigoE);
                                if(respuesta == 1)
                                {
                                    lastCodigoE++;
                                }
                                break;
                            case 2:
                                printf("todavia no disponible.\n");
                                break;
                            case 3:
                                printf("__________________________________\n\n  QUE EQUIPO DESEA MODIFICAR?\n__________________________________");
                                respuesta = modificarE(listaEquipos, CANT);
                                switch(respuesta)
                                {
                                case 0:
                                    printf("Accion cancelada por el usuario.\n");
                                    break;
                                case 1:
                                    printf("Equipo modificado.\n");
                                    break;
                                case -1:
                                    printf("Dato no encontrado.\n");
                                    break;
                                }
                                break;
                            case 4:
                                mostrarListadoEquipos(listaEquipos,CANT);
                                break;
                            case 5:
                                printf("\nSalio de este menu.\n");
                                break;
                            default:
                                printf("Opcion incorrecta. Disponible : 1, 2 , 3, 4,5.");
                                break;
                            }
                            break;

                        case 2:
                            respuesta = getInt("-MENU JUGADORES- \n 1.ALTAS\n 2.BAJAS\n 3.MODIFICAR\n 4.ORDENAR Y LISTAR\n 5.SALIR\n");
                            switch(respuesta)
                            {
                            case 1:
                                respuesta = cargarListadoJugadores(listaJugadores,listaEquipos,CANT,lastCodigoJ);
                                if(respuesta == 1)
                                {
                                    lastCodigoJ++;
                                }
                                break;
                            case 2:

                                printf("todavia no disponible.\n");
                                break;
                            case 3:
                                printf("__________________________________\n\n  QUE JUGADOR DESEA MODIFICAR?\n__________________________________");
                                mostrarListadoJugadores(listaJugadores, CANT);
                                printf("todavia no disponible.\n");
                                break;
                            case 4:
                                mostrarListadoJugadores(listaJugadores, CANT);
                                break;
                            case 5:
                                printf("\nSalio de este menu.\n");
                                break;
                            default:
                                printf("Opcion incorrecta. Disponible : 1, 2 , 3, 4,5.");
                                break;
                            }

                            break;
                        case 3:
                            respuesta = getInt("-MENU REFEREI- \n 1.ALTAS\n 2.BAJAS\n 3.MODIFICAR\n 4.ORDENAR Y LISTAR\n 5.SALIR\n");
                            switch(respuesta)
                            {
                            case 1:
                                respuesta = cargarListadoReferies(listaReferies,CANT,lastCodigoR);
                                if(respuesta == 1)
                                {
                                    lastCodigoR++;
                                }
                                break;
                            case 2:
                                printf("todavia no disponible.\n");
                                break;
                            case 3:
                                printf("__________________________________\n\n  QUE ARBITRO DESEA MODIFICAR?\n__________________________________");
                                mostrarListadoReferi(listaReferies, CANT);
                                respuesta = modificarR(listaReferies,CANT,getInt("\nIngrese el codigo del referi:"));
                                switch(respuesta)
                                {
                                case 0:
                                    printf("Accion cancelada por el usuario.\n");
                                    break;
                                case 1:
                                    printf("Referi modificado.\n");
                                    break;
                                case -1:
                                    printf("Dato no encontrado.\n");
                                    break;
                                }
                                break;
                            case 4:
                                mostrarListadoReferi(listaReferies, CANT);
                                break;
                            case 5:
                                printf("\nSalio de este menu.\n");
                                break;
                            default:
                                printf("Opcion incorrecta. Disponible : 1, 2 , 3, 4,5.");
                                break;
                            }
                            break;

                        case 4:
                            respuesta = getInt("-MENU PARTIDOS- \n 1.ALTAS\n 2.BAJAS\n 3.MODIFICAR\n 4.ORDENAR Y LISTAR\n 5.SALIR\n");
                            switch(respuesta)
                            {
                            case 1:
                                respuesta = cargarListadoPartido(listaPartidos, listaEquipos, listaReferies, CANT, lastCodigoP);
                                if(respuesta == 1)
                                {
                                    lastCodigoP++;
                                }
                                break;
                            case 2:
                                printf("todavia no disponible.\n");
                                break;
                            case 3:
                                printf("__________________________________\n\n  QUE PARTIDO DESEA MODIFICAR?\n__________________________________");
                                mostrarListadoPartidos(listaPartidos, CANT);
                                printf("todavia no disponible.\n");
                                break;
                            case 4:
                                mostrarListadoPartidos(listaPartidos, CANT);
                                break;
                            case 5:
                                printf("\nSalio de este menu.\n");
                                break;
                            default:
                                printf("Opcion incorrecta. Disponible : 1, 2, 3, 4,5.");
                                break;
                            }
                            break;
                        case 5:
                            printf("\n***Programa finalizado. Hasta luego.***\n\n");
                            break;
                        }
                        system("pause");
                        system("cls");
                    }
                    while(opcion!=5);
                }
            }
        }
    }
    else
    {
        printf("\n\n*OCURRIO UN ERROR AL CARGAR LAS LISTAS.*");
    }
    return 0;
}

