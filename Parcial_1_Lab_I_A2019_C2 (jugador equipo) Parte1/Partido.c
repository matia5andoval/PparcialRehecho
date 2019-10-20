#include "Partido.h"
#define CANT 50

ePartido cargarPartido(eEquipo listaEquipos[], eReferi listaReferies[], int cant)
{
    ePartido unPartido;
    int codigoEncontrado;

    unPartido.fechaPartido = cargarFechaP("\nA continuacion, introduzca la fecha del partido:\n");

    printf("A continuacion ingresara codigos de equipos/referies:\n");

    codigoEncontrado = buscarCodigo(listaEquipos, cant);
    unPartido.codEquipoLoc=codigoEncontrado;
    printf("Codigo equipo local cargado con exito.");

    codigoEncontrado = buscarCodigoR(listaReferies, cant, getInt("\nIngrese el codigo del referi:"));
    unPartido.codReferi=codigoEncontrado;
    printf("Codigo referi cargado con exito.");

    codigoEncontrado = buscarCodigo(listaEquipos, cant);
    unPartido.codEquipoVis=codigoEncontrado;
    printf("Codigo e.Visitante cargado con exito.");

    unPartido.codigo=0;
    unPartido.estado = LIBRE;

    return unPartido;
}

eFechaP cargarFechaP(char mensaje[])
{
    eFechaP unaFecha;

    printf(mensaje);

    unaFecha.dia= getInt("\nIngresar el dia, maximo 2 caracteres: ");
    unaFecha.dia= validarIntMaxMin(unaFecha.dia, "\nReingrese el dia, maximo 2 caracteres:", 31, 0);

    unaFecha.mes= getInt("\nIngresar el mes, maximo 2 caracteres: ");
    unaFecha.mes= validarIntMaxMin(unaFecha.mes, "\nReingrese el mes, maximo 2 caracteres:", 12, 0);

    unaFecha.anio= getInt("\nIngresar el anio, maximo 4 caracteres: ");
    unaFecha.anio= validarIntMaxMin(unaFecha.anio, "\nReingrese el anio, maximo 4 caracteres:", 2019, 1940);

    return unaFecha;
}


void hardcodeoP(ePartido listaPartido[], int cant)
{
    int i;
    int dia = {26};
    int mes = {9};
    int anio = {2019};
    int codRefe[] = {15,16,17,18,19,20,21,22,23,24};
    int codELocal[] = {1,2,3,4,5,6,7};
    int codEVis[]= {8,9,10,11,12,13,14};
    int codPartido[]= {10, 20,30,40,50,60,70};

    for(i=0; i<cant; i++)
    {
        listaPartido[i].fechaPartido.dia = dia;
        listaPartido[i].fechaPartido.mes = mes;
        listaPartido[i].fechaPartido.anio = anio;
        listaPartido[i].codEquipoLoc = codELocal[i];
        listaPartido[i].codEquipoVis = codEVis[i];
        listaPartido[i].codReferi = codRefe[i];
        listaPartido[i].codigo = codPartido[i];
        listaPartido[i].estado = OCUPADO;
    }
}

int inicializarPartido(ePartido* listaPartidos, int cant)
{
    int i;
    int retorno = -1;

    if(listaPartidos!=NULL && cant>0)
    {
        for(i=0; i<cant; i++)
        {
            listaPartidos[i].estado = LIBRE;
        }
        retorno = 0;
    }

    return retorno;
}

int buscarPartLibre(ePartido listaPartidos[], int cant)
{

    int indice = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(listaPartidos[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int cargarListadoPartido(ePartido listaPartidos[],eEquipo listaEquipos[], eReferi listaReferies[], int cant, int lastCodigo)
{
    int indice;
    int respuesta = 0;

    indice = buscarPartLibre(listaPartidos, cant);

    if(indice!=-1)
    {
        listaPartidos[indice]=cargarPartido(listaEquipos, listaReferies,cant);
        listaPartidos[indice].codigo = lastCodigo;
        listaPartidos[indice].estado=OCUPADO;
        respuesta = 1;
    }
    else
    {
        printf("No hay espacio.");
    }

    return respuesta;
}

void mostrarPartido(ePartido unPart)
{
    printf("\t%2d\t\t%2d\t\t%2d\t\t  %2d\t      %2d/%2d/%2d\n",unPart.codigo,unPart.codEquipoLoc,unPart.codEquipoVis,unPart.codReferi, unPart.fechaPartido.dia, unPart.fechaPartido.mes, unPart.fechaPartido.anio);
}

void mostrarListadoPartidos(ePartido listaPartidos[], int cant)
{
    int i;
    printf("********************LISTA DE CODIGOS********************\n");
    printf("CODIGO PARTIDO\t EQUIPO LOCAL\tEQUIPO VISITANTE\tREFERI\t   FECHA DEL PARTIDO\n");
    for(i=0; i<cant; i++)
    {
        if(listaPartidos[i].estado==OCUPADO)
        {
            mostrarPartido(listaPartidos[i]);
        }
    }
}

/*int modificarR(eReferi listaReferis[], int cant)///INGRESAR EL LAST ID POR UN GET INT DESDE EL MAIN
{
    int cod;
    int flag = -1;
    char respuesta;
    eReferi aux;

    cod = buscarCodigoR(listaReferis,cant);
    if(cod!=-1)
    {
        aux = listaReferis[cod];

        mostrarReferi(aux);
        respuesta=getInt("Ingrese la opcion que desea modificar:\n1.Nombre \n2.Apellido \n3.Sexo \n4.Email \n5.Fecha de nacimiento.\n");
        respuesta=validarIntMaxMin(respuesta, "Error, ingrese de 1 a 5:\n", 5, 1);

        switch(respuesta)
        {
        case 1:
            getStr(aux.nombre, "Ingrese el nuevo nombre:\n");
            validarString(aux.nombre, "Error. Ese no es un nombre. Ingresar de nuevo:\n");
            break;
        case 2:
            getStr(aux.apellido, "Ingrese el nuevo apellido:\n");
            validarString(aux.apellido, "Error. Ese no es un apellido. Ingresar de nuevo:\n");
            break;
        case 3:
            aux.sexo=getChar("Ingrese el nuevo sexo:\n");
            aux.sexo=validarConDosChar("Error. Ese no es un nombre. Ingresar de nuevo:\n",aux.sexo,'f','m');
            break;
        case 4:
            getStr(aux.email, "Ingrese el nuevo email:\n");
            validarCorreo(aux.email, "Error. Ese no es un email. Ingresar de nuevo:\n");
            break;
        case 5:
            aux.fechaNacimiento=cargarFechaR("\nIngrese la nueva fecha de nacimiento:\n");
            break;
        }

        respuesta=getChar("Esta seguro que desea modificar este Referi? (s/n):\n");
        respuesta=validarConDosChar("Error. Debe ingresar las letras -s- o -n-:\n", respuesta, 's', 'n');

        if(respuesta=='s')
        {
            listaReferis[cod] = aux;
            flag = 1;
        }
        else
        {
            flag = 0;
        }

    }
    return flag;
}
*/
