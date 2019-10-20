#include "Referi.h"

eReferi cargarReferies()
{
    eReferi unReferi;

    getStr(unReferi.nombre, "Ingrese el nombre:");
    validarStrEspacios(unReferi.nombre, "Error. Reingrese nombre maximo 31 caracteres:", 31);

    getStr(unReferi.apellido, "Ingrese apellido:");
    validarStrEspacios(unReferi.apellido, "Error. Reingrese apellido maximo 31 caracteres:", 31);

    unReferi.sexo = getChar("Ingrese sexo: (f o m)\n");
    unReferi.sexo = validarConDosChar("Error. Ingrese solo f o m: ", unReferi.sexo, 'm', 'f');

    getStr(unReferi.email, "Ingrese email:");
    validarCorreo(unReferi.email, "Error. Debe ingresar un email(utilize un @ y ocupe un maximo  de 31 caracteres):  ");
    validarStrEspacios(unReferi.email, "Error. El email debe contener 31 caracteres como maximo. Reingresar email:", 31);

    unReferi.fechaNacimiento = cargarFechaR("\nA continuacion, introduzca la fecha de nacimiento:\n");

    unReferi.estado = LIBRE;
    unReferi.codigo = 0;

    return unReferi;
}


eFechaR cargarFechaR(char mensaje[])
{
    eFechaR unaFecha;

    printf(mensaje);

    unaFecha.dia= getInt("\nIngresar el dia(un numero del 1 - 31): ");
    unaFecha.dia= validarIntMaxMin(unaFecha.dia, "\nReingrese el dia(un numero del 1 - 31):", 31, 0);

    unaFecha.mes= getInt("\nIngresar el mes(un numero del 1 - 12): ");
    unaFecha.mes= validarIntMaxMin(unaFecha.mes, "\nReingrese el mes(un numero del 1 - 12):", 12, 0);

    unaFecha.anio= getInt("\nIngresar el anio(un numero del 1940 - 2019): ");
    unaFecha.anio= validarIntMaxMin(unaFecha.anio, "\nReingrese el anio(un numero del 1940 - 2019):", 2019, 1940);


    return unaFecha;
}


int buscarCodigoR(eReferi listaReferis[], int cant, int elCod)
{
    int flag = 0;
    int indice = -1;
    int i;

    while(flag != 1)
    {
        for(i=0; i<cant; i++)
        {
            if(listaReferis[i].codigo==elCod&&listaReferis[i].estado==OCUPADO)
            {
                indice=elCod;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            elCod = getInt("\nError, codigo no valido. Ingrese un codigo valido:");
        }
    }
    return indice;
}

int inicializarReferi(eReferi* listaReferis, int cant)
{
    int i;
    int retorno = -1;

    if(listaReferis!=NULL && cant>0)
    {
        for(i=0; i<cant; i++)
        {
            listaReferis[i].estado = LIBRE;
        }
        retorno = 0;
    }

    return retorno;
}

int buscarRefLibre(eReferi listaReferis[], int cant)
{

    int indice = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(listaReferis[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int cargarListadoReferies(eReferi listaReferies[], int cant, int lastCodigo)
{
    int indice;
    int respuesta = 0;

    indice = buscarRefLibre(listaReferies, cant);

    if(indice!=-1)
    {
        listaReferies[indice] = cargarReferies();
        listaReferies[indice].codigo = lastCodigo;
        listaReferies[indice].estado=OCUPADO;
        respuesta = 1;
    }
    else
    {
        printf("No hay espacio.");
    }
    return respuesta;
}

void hardcodeoR(eReferi listaReferies[], int cant)
{
    int i;
    char Nombres[][50]= {"Nicolas","Nazareno","Dario","Fernando","Gisella","Yael"};
    char Apellido[][50]= {"Lamolina","Arasa","Herrera","Espinoza","Trucco","Falcon Perez"};
    char Sexo[]= {'M','M','M','M','M','M','F'};
    int anio[]= {1980,1981,1975,1970,1986,1989};
    int mes[]= {8,10,5,6,6,2};
    int dia[]= {15,5,20,22,12,1};
    int codigo[]= {0,1,2,3,4,5};
    char mails[][50]= {"hola@1.com","hola@1.com","hola@1.com","hola@1.com","holasdasa@1.comasdasd"};

    for(i=0; i<cant; i++)
    {
        listaReferies[i].fechaNacimiento.dia = dia[i];
        listaReferies[i].fechaNacimiento.mes = mes[i];
        listaReferies[i].fechaNacimiento.anio = anio[i];
        listaReferies[i].sexo = Sexo[i];
        strcpy(listaReferies[i].nombre, Nombres[i]);
        strcpy(listaReferies[i].apellido, Apellido[i]);
        strcpy(listaReferies[i].email, mails[i]);
        listaReferies[i].codigo = codigo[i];
        listaReferies[i].estado = OCUPADO;
    }
}

void mostrarReferi(eReferi unRefe)
{
    printf("%2d\t  %15s   %15s\t          %1c%25s\t\t",unRefe.codigo, unRefe.nombre, unRefe.apellido,unRefe.sexo,unRefe.email);
    printf("%2d/%2d/%4d\n", unRefe.fechaNacimiento.dia, unRefe.fechaNacimiento.mes, unRefe.fechaNacimiento.anio);
}

void mostrarListadoReferi(eReferi listaReferies[], int cant)
{
    int i;
    printf("\n\n***************************LISTADO REFERIS***************************\n\n");
    printf("CODIGO\t\t    NOMBRE\t    APELLIDO\t\t SEXO\t           EMAIL\t\t FECHA\n");
    for(i=0; i<cant; i++)
    {
        if(listaReferies[i].estado==OCUPADO)
        {
            mostrarReferi(listaReferies[i]);
        }
    }
}

int modificarR(eReferi listaReferis[], int cant, int elCod)///INGRESAR EL LAST ID POR UN GET INT DESDE EL MAIN
{
    int cod;
    int flag = -1;
    char respuesta;
    eReferi auxr;

    cod = buscarCodigoR(listaReferis,cant, elCod);      ///EL CODIGO DEBE COINCIDIR CON EL ESPACIO DEL ARRAY DE OTRA FORMA
                                                        /// VA A MOSTRAR CUALQUIER ESPACIO.
    if(cod!=-1)
    {
        auxr = listaReferis[cod];
        printf("\n");
        mostrarReferi(auxr);
        printf("\n");
        respuesta=getInt("Ingrese la opcion que desea modificar:\n1.Nombre \n2.Apellido \n3.Sexo \n4.Email \n5.Fecha de nacimiento.\n");
        respuesta=validarIntMaxMin(respuesta, "Error, ingrese de 1 a 5:\n", 5, 1);

        switch(respuesta)
        {
        case 1:
            getStr(auxr.nombre, "Ingrese el nuevo nombre:\n");
            validarString(auxr.nombre, "Error. Ese no es un nombre. Ingresar de nuevo:\n");
            break;
        case 2:
            getStr(auxr.apellido, "Ingrese el nuevo apellido:\n");
            validarString(auxr.apellido, "Error. Ese no es un apellido. Ingresar de nuevo:\n");
            break;
        case 3:
            auxr.sexo=getChar("Ingrese el nuevo sexo(f/m):\n");
            auxr.sexo=validarConDosChar("Error. Debe ingresar f o m:\n",auxr.sexo,'f','m');
            break;
        case 4:
            getStr(auxr.email, "Ingrese el nuevo email:");
            validarCorreo(auxr.email, "Error. Debe ingresar un email: (utilize un @ y ocupe un maximo  de 31 caracteres)");
            validarStrEspacios(auxr.email, "Error. El email debe contener 31 caracteres como maximo. Reingresar email:", 31);
            break;
        case 5:
            auxr.fechaNacimiento=cargarFechaR("\nIngrese la nueva fecha de nacimiento:\n");
            break;
        }

        respuesta=getChar("Esta seguro que desea modificar este Referi? (s/n):\n");
        respuesta=validarConDosChar("Error. Debe ingresar las letras -s- o -n-:\n", respuesta, 's', 'n');

        if(respuesta=='s')
        {
            listaReferis[cod] = auxr;
            flag = 1;
        }
        else
        {
            flag = 0;
        }

    }
    return flag;
}
