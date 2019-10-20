#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float getFloat(char mensaje[]);
int getInt(char mensaje[]);
void getStr(char str[], char mensaje[]);
char getChar(char mensaje[]);
int validarInt(char str[], char eMensaje[]);
int validarIntMaxMin(int num, char eMensaje[], int maximo, int minimo);
char validarChar(char eMensaje[], char letra);
char validarConDosChar(char eMensaje[],char letra, char letraUno, char letraDos);
void validarString(char str[], char eMensaje[]);
void validarAlfaNumerico(char str[],char eMensaje[]);
void validarTelefono(char str[],char eMensaje[]);
void validarCorreo(char str[], char eMensaje[]);
void validarUnaFecha(char str[], char eMensaje[]);
void validarUnaHora(char str[], char eMensaje[]);
void validarStrEspacios(char str[], char eMensaje[], int maximo);
