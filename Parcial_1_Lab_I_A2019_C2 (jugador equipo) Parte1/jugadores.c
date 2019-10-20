#include "jugadores.h"

eJugadores cargarJugador(eEquipo listaEquipos[],int cant)
{
    int codigoEncontrado;
    eJugadores unJugador;

    getStr(unJugador.nombre, "\nIngrese nombre:");
    validarStrEspacios(unJugador.nombre, "\nError. Reingrese nombre maximo 31 caracteres:", 31);

    getStr(unJugador.apellido, "\nIngrese apellido:");
    validarStrEspacios(unJugador.apellido, "\nError. Reingrese apellido maximo 31 caracteres:", 31);

    unJugador.sexo = getChar("\nIngrese sexo (f o m):");
    unJugador.sexo = validarConDosChar("\nError. Ingrese solo f o m:",unJugador.sexo, 'f','m');


    codigoEncontrado = buscarCodigo(listaEquipos, cant);
    unJugador.codigoDeEquipo=codigoEncontrado;
    printf("Codigo cargado con exito.");

    unJugador.fechaNacimiento = cargarFechaJ("\nA continuacion, introduzca la fecha de nacimiento:\n");

    unJugador.estado=LIBRE;
    unJugador.codigo = 0;

    return unJugador;
}

eFechaJ cargarFechaJ(char mensaje[])
{
    eFechaJ unaFecha;

    printf(mensaje);

    unaFecha.dia= getInt("\nIngresar el dia, maximo 2 caracteres: ");
    unaFecha.dia= validarIntMaxMin(unaFecha.dia, "\nReingrese el dia, maximo 2 caracteres:", 31, 0);

    unaFecha.mes= getInt("\nIngresar el mes, maximo 2 caracteres: ");
    unaFecha.mes= validarIntMaxMin(unaFecha.mes, "\nReingrese el mes, maximo 2 caracteres:", 12, 0);

    unaFecha.anio= getInt("\nIngresar el anio, maximo 4 caracteres: ");
    unaFecha.anio= validarIntMaxMin(unaFecha.anio, "\nReingrese el anio, maximo 4 caracteres:", 2019, 1940);

    return unaFecha;
}


int inicializarJugadores(eJugadores* listaJugadores, int cant)
{
    int i;
    int retorno = -1;

    if(listaJugadores!=NULL && cant>0)
    {
        for(i=0; i<cant; i++)
        {
            listaJugadores[i].estado = LIBRE;
        }
        retorno = 0;
    }

    return retorno;
}

int buscarJugLibre(eJugadores listaJugadores[], int cant)
{

    int indice = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(listaJugadores[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int cargarListadoJugadores(eJugadores listaJugadores[],eEquipo listaEquipos[], int cant, int lastCodigo)
{
    int indice;
    int respuesta = 0;

    indice = buscarJugLibre(listaJugadores, cant);

    if(indice!=-1)
    {
        listaJugadores[indice] = cargarJugador(listaEquipos, cant);
        listaJugadores[indice].codigo = lastCodigo;
        listaJugadores[indice].estado=OCUPADO;
        respuesta = 1;
    }
    else
    {
        printf("No hay espacio disponible.");
    }

    return respuesta;
}

void hardcodeoJ(eJugadores listaJugadores[], int cant)
{
    int i;
    char Nombres[][50]= {"JUAN","JOSE LUIS","JOSE LUIS","JOSE LUIS","JOSE LUIS","JOSE LUIS","JOSE LUIS"};
    char Sexo[]= {'M','M','M','F','F','F','F'};
    char Apellido[][50]= {"Gonzalez","Rodriguez","Gomez","Rodriguez","Rodriguez","Rodriguez","Rodriguez"};
    int codigoEquipos[] = { 111,111,111,1,2,3,4,5};
    int anio[]= { 2000, 2001,2000,2000,2000,2000,2000};
    int mes[]= { 1,3,5,2,22,23,24};
    int dia[]= { 25,30,11,22,11,23,24};
    int codigo=1;

    for(i=0; i<cant; i++)
    {
        listaJugadores[i].fechaNacimiento.dia = dia[i];
        listaJugadores[i].fechaNacimiento.mes = mes[i];
        listaJugadores[i].fechaNacimiento.anio = anio[i];
        strcpy(listaJugadores[i].nombre, Nombres[i]);
        strcpy(listaJugadores[i].apellido, Apellido[i]);
        listaJugadores[i].sexo=Sexo[i];
        listaJugadores[i].codigo = codigo;
        listaJugadores[i].codigoDeEquipo = codigoEquipos[i];
        listaJugadores[i].estado = OCUPADO;
        codigo++;
    }
}

void mostrarJugadores(eJugadores unJugador)
{
    printf("%2d%20s%20s\t",unJugador.codigo,unJugador.nombre, unJugador.apellido);
    printf("   %1c\t\t%2d\t\t\t%2d/%2d/%4d\n",unJugador.sexo,unJugador.codigoDeEquipo,unJugador.fechaNacimiento.dia, unJugador.fechaNacimiento.mes, unJugador.fechaNacimiento.anio);
}

void mostrarListadoJugadores(eJugadores listaJugadores[], int cant)
{
    int i;
    printf("\n\n***************************LISTADO JUGADORES***************************\n\n");
    printf("CODIGO\t\t NOMBRE\t\t  APELLIDO\t SEXO\t    COD.EQUIPO\t\t   FECHA DE NACIMIENTO\n");

    for(i=0; i<cant; i++)
    {
        if(listaJugadores[i].estado==OCUPADO)
        {
            mostrarJugadores(listaJugadores[i]);
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
