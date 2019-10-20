#include "validaciones.h"


int getInt(char mensaje[])
{
    int numero;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}

float getFloat(char mensaje[])
{
    float flotante;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &flotante);
    return flotante;
}

void getStr(char str[], char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    gets(str);
}

int validarInt(char str[], char eMensaje[])
{
    int flag = 1;
    int i;
    int numero;
    int cant;
    do
    {
        cant = strlen(str);
        for (i=0; i<cant; i++)
        {
            if(str[i] < '0' || str[i] > '9')
            {
                printf("%s", eMensaje);
                fflush(stdin);
                gets(str);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
    }
    while(flag == 0);

    numero = atoi(str);
    return numero;
}

int validarIntMaxMin(int num, char eMensaje[], int maximo, int minimo)
{
    while(num < minimo || num > maximo)
    {
        printf("%s", eMensaje);
        fflush(stdin);
        scanf("%d", &num);
    }
    return num;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

char validarConDosChar(char eMensaje[],char letra, char letraUno, char letraDos)
{
    while(letra!=letraUno&&letra!=letraDos)
    {
        printf("%s", eMensaje);
        fflush(stdin);
        scanf("%c", &letra);
    }
    return letra;
}
char validarChar(char eMensaje[], char letra)
{
    while((letra != ' ') && (letra < 'a' || letra > 'z') && (letra < 'A' || letra > 'Z'))
    {
        printf("%s", eMensaje);
        fflush(stdin);
        scanf("%c", &letra);
    }
    return letra;
}

void validarStrEspacios(char str[], char eMensaje[], int maximo)
{
    int cant;
    cant = strlen(str);

    while(cant>maximo)
    {
        printf("%s", eMensaje);
        fflush(stdin);
        gets(str);
        cant = strlen(str);
    }
}

void validarString(char str[], char eMensaje[])
{
    int flag = 1;
    int i;
    int cant;
    do
    {
        cant = strlen(str);
        for (i=0; i<cant; i++)
        {
            if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            {
                printf("%s", eMensaje);
                fflush(stdin);
                gets(str);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
    }
    while(flag == 0);

}

void validarAlfaNumerico(char str[],char eMensaje[])
{
    int flag = 1;
    int i;
    int cant;
    do
    {
        cant = strlen(str);
        for (i=0; i<cant; i++)
        {
            if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            {
                printf("%s", eMensaje);
                fflush(stdin);
                gets(str);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
    }
    while(flag == 0);

}

void validarTelefono(char str[],char eMensaje[])
{
    int flag = 1;
    int i;
    int cant;
    do
    {
        cant = strlen(str);
        for (i=0; i<cant; i++)
        {
            if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))//si no hay espacios no hay guiones y hay letras
            {
                printf("%s", eMensaje);
                fflush(stdin);
                gets(str);
                flag = 0;
                break;
            }
            else
            {
                if(str[i] == '@')
                {
                    flag = 1;
                }
            }
        }
    }
    while(flag == 0);

}

void validarCorreo(char str[], char eMensaje[])
{
    int flag = 0;
    int i;
    int cant;
    do
    {
        cant = strlen(str);
        for (i=0; i<cant; i++)
        {
            if(str[i] == '@')
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("%s", eMensaje);
            fflush(stdin);
            gets(str);
        }
    }
    while(flag == 0);


}

void validarUnaFecha(char str[], char eMensaje[])
{
    int i;
    int cant;
    int contBarras=0;
    do
    {
        cant = strlen(str);
        for (i=0; i<cant; i++)
        {
            if(str[i] == '/')
            {
                contBarras++;
            }
        }
        if (contBarras != 3)
        {
            printf("%s", eMensaje);
            fflush(stdin);
            gets(str);
        }
    }
    while(contBarras != 3);

}
void validarUnaHora(char str[], char eMensaje[])
{
    int i;
    int cant;
    int contDosPuntos=0;
    do
    {
        cant = strlen(str);
        for (i=0; i<cant; i++)
        {
            if(str[i] == ':')
            {
                contDosPuntos++;
            }
        }
        if (contDosPuntos != 3)
        {
            printf("%s", eMensaje);
            fflush(stdin);
            gets(str);
        }
    }
    while(contDosPuntos != 3);

}
