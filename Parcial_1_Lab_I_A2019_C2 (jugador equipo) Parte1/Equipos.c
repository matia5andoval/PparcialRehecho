#include "Equipos.h"

eEquipo cargarEquipo()
{
    eEquipo unEquipo;

    getStr(unEquipo.nombre, "Ingrese el nombre:");
    validarStrEspacios(unEquipo.nombre, "Error. Reingrese el nombre maximo 51 caracteres:", 51);

    getStr(unEquipo.tipo,"El equipo es local o visitante? (escribir: local-visitante) :  ");
    validarStrEspacios(unEquipo.tipo, "Debe ingresar si el equipo es visitante o local:", 10);

    if(strcmp(unEquipo.tipo, "local")==0)
    {
        strcpy(unEquipo.localidad, "Avellaneda");
        printf("Informacion del equipo cargada correctamente.");
    }
    else
    {
        getStr(unEquipo.localidad, "Ingrese la localidad del equipo visitante:");
        validarStrEspacios(unEquipo.localidad, "Error. Reingrese la localidad maximo 33 caracteres:", 33);
        printf("Informacion del equipo cargada correctamente.");
    }

    unEquipo.codigo=0;
    unEquipo.estado=LIBRE;

    return unEquipo;
}

int inicializarEquipos(eEquipo* listaEquipos, int cant)
{
    int i;
    int retorno = -1;

    if(listaEquipos!=NULL && cant>0)
    {
        for(i=0; i<cant; i++)
        {
            listaEquipos[i].estado = LIBRE;
        }
        retorno = 0;
    }

    return retorno;
}

int buscarEqLibre(eEquipo listaEquipos[], int cant)
{

    int indice = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(listaEquipos[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarCodigo(eEquipo listaEquipos[], int cant)
{
    int elCod;
    int flag = 0;
    int indice = -1;
    int i;
    elCod = getInt("\nIngresar el codigo del equipo: ");

    while(flag != 1)
    {
        for(i=0; i<cant; i++)
        {
            if(listaEquipos[i].codigo==elCod&&listaEquipos[i].estado==OCUPADO)
            {
                indice=elCod;
                flag=1;
            }
        }
        if(flag == 0)
        {
            elCod = getInt("\nError, codigo no valido. Ingrese un codigo de equipo:");
        }
    }
    return indice;
}

int cargarListadoEquipos(eEquipo listaEquipos[], int cant, int lastCodigo)
{
    int indice;
    int respuesta = 0;

    indice = buscarEqLibre(listaEquipos, cant);

    if(indice!=-1)
    {
        listaEquipos[indice] = cargarEquipo();
        listaEquipos[indice].codigo = lastCodigo;
        listaEquipos[indice].estado=OCUPADO;
        respuesta = 1;
    }
    else
    {
        printf("No hay espacio.");
    }

    return respuesta;
}


void hardcodeoE(eEquipo listaEquipos[], int cant)
{
    int i;
    int codigo = 1;
    char equipos[][51] = {"Cambios FC","Camboya","Dep Muy Caliente","Hacha y Birra","Bidon de Branco","Real Coholicos","Suc. Congreso","Sucursal Flores","Los Isotopos","Ornad + 4"};
    char localidades[][33] = {"Avellaneda","Avellaneda","Avellaneda","CABA","Lanus","Banfield","Avellaneda","CABA","Lanus","Banfield","Avellaneda","CABA"};
    char tipo[][50]= {"local","visitante","local","visitante","local","visitante","local","visitante","local","visitante","local","visitante"};
    for(i=0; i<cant; i++)
    {
        strcpy(listaEquipos[i].nombre, equipos[i]);
        strcpy(listaEquipos[i].localidad, localidades[i]);
        strcpy(listaEquipos[i].tipo, tipo[i]);
        listaEquipos[i].codigo = codigo;
        listaEquipos[i].estado = OCUPADO;
        codigo++;
    }
}
void mostrarEquipo(eEquipo unEquipo)
{
    printf("%d %31s %33s %23s\n",unEquipo.codigo, unEquipo.nombre,unEquipo.localidad, unEquipo.tipo);
}

void mostrarListadoEquipos(eEquipo listaEquipos[], int cant)
{
    int i;
    printf("\n\n***************************LISTADO EQUIPOS***************************\n\n");
    printf("CODIGO\t\t      \t NOMBRE\t\t\t\t LOCALIDAD\t\tLOCAL/VISITANTE\n");
    for(i=0; i<cant; i++)
    {
        if(listaEquipos[i].estado==OCUPADO)
        {
            mostrarEquipo(listaEquipos[i]);
        }
    }
}

int modificarE(eEquipo listaEquipo[], int cant)///INGRESAR EL LAST ID POR UN GET INT DESDE EL MAIN
{
    int cod;
    int flag = -1;
    char respuesta;
    eEquipo aux;

    mostrarListadoEquipos(listaEquipo, cant);

    cod = buscarCodigo(listaEquipo,cant);
    if(cod!=-1)
    {
        aux = listaEquipo[cod];

        mostrarEquipo(aux);

        respuesta=getInt("Ingrese la opcion que desea modificar:\n1.Nombre\n2.Localidad\n");
        respuesta=validarIntMaxMin(respuesta, "Error, ingrese opcion 1 o 2:\n", 2, 1);

        switch(respuesta)
        {
        case 1:
            getStr(aux.nombre, "Ingrese el nuevo nombre:\n");
            validarString(aux.nombre, "Error. Ese no es un nombre. Ingresar de nuevo:\n");
            validarStrEspacios(aux.nombre, "Error.Debe ingresar un nombre de 30 letras maximo: ", 30);
            break;
        case 2:
            getStr(aux.localidad, "Ingrese una nueva localidad:\n");
            validarString(aux.localidad, "Error. Esa no es una localidad. Ingresar de nuevo:\n");
            validarStrEspacios(aux.localidad, "Error. Debe ingresar una localidad de 30 letras maximo: ", 30);
            if(strcmp(aux.localidad, "avellaneda")==0)
            {
                strcpy(aux.tipo, "local");
            }
            else
            {
                strcpy(aux.tipo, "visitante");
            }
            break;
        }

        respuesta=getChar("Esta seguro que desea modificar este Equipo? (s/n):\n");
        respuesta=validarConDosChar("Error. Debe ingresar las letras -s- o -n-:\n", respuesta, 's', 'n');

        if(respuesta=='s')
        {
            listaEquipo[cod] = aux;
            flag = 1;
        }
        else
        {
            flag = 0;
        }

    }
    return flag;
}
