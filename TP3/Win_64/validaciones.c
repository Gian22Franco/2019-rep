#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"


int getInt(int* pBuffer)
{
    fflush(stdin);
    return scanf("%d",pBuffer);
}
int getFloat(float* pBuffer)
{
    fflush(stdin);
    return scanf("%f",pBuffer);
}
void getString(char msg[],char* pBuffer)
{
    printf("%s",msg);
    fflush(stdin);
    fgets(pBuffer, 51 , stdin);
    pBuffer[strcspn(pBuffer, "\n")] = 0;
}
void getString21(char msg[],char* pBuffer)
{
    printf("%s",msg);
    fflush(stdin);
    fgets(pBuffer, 21 , stdin);
    pBuffer[strcspn(pBuffer, "\n")] = 0;
}
int getCaracter(char* pBuffer)
{
    fflush(stdin);
    return scanf("%c",pBuffer);
}
int utn_getFloat(float *pFlotante, char* msg ,char* msgErr,int min)
{
    int retorno=-1;
    float bufferFloat;
    char bufferFloatString[256];
    if(pFlotante != NULL && msg != NULL && msgErr != NULL&& min >= 1)
    {
        do
        {
            getString(msg,bufferFloatString);
            if( esNumericoFlotante(bufferFloatString))
            {
                bufferFloat = atof (bufferFloatString);
                if(bufferFloat >= min){
                    *pFlotante = bufferFloat;
                    retorno = 0;
                    break;
                }
            }
            else
            {
                fflush(stdin);
                msg=msgErr;
            }
        }while(retorno!=0);
    }
    return retorno;
}
int esNumericoFlotante(char str[])
{
   int i=0,flagcoma=0;
   if(str[i] == '\0')
        return  0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9'){
            if(str[i]==','||str[i]=='.'){
                if(flagcoma==1){
                    return 0;
                }else
                    flagcoma=1;
            }else
                return 0;
        }

       i++;
   }
   return 1;
}
int esNumerico(char str[])
{
   int i=0;
   if(str[i] == '\0')
        return 0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
int utn_getEntero(  int* pEntero, char* msg,char* msgErr,int min, int max)
{
    int retorno=-1;
    int bufferInt;
    char bufferIntString[256];
    if(pEntero != NULL && msg != NULL && msgErr != NULL&& min <= max)
    {
        do
        {
            getString(msg,bufferIntString);
            if( esNumerico(bufferIntString))
            {
                bufferInt = atoi(bufferIntString);
                if((bufferInt >= min && bufferInt <= max)){
                    *pEntero = bufferInt;
                    retorno = 0;
                    break;
                }
            }
            fflush(stdin);
            msg=msgErr;
        }while(retorno!=0);

    }
    return retorno;
}
int utn_getEnteroEsc(  int* pEntero, char* msg,char* msgErr,int min, int max,int esc)
{
    int retorno=-1;
    int bufferInt;
    char bufferIntString[256];
    if(pEntero != NULL && msg != NULL && msgErr != NULL&& min <= max)
    {
        do
        {
            getString(msg,bufferIntString);
            if( esNumerico(bufferIntString))
            {
                bufferInt = atoi(bufferIntString);
                if((bufferInt >= min && bufferInt <= max)){
                    *pEntero = bufferInt;
                    retorno = 0;
                    break;
                }
                if(bufferInt==esc)
                    break;
            }
            else
            {
                fflush(stdin);//limpia en linux como fflush
                msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}
int esSoloLetras(char* str)
{
    int i=0;
    int retorno = 1;
    if(*(str+i) == '\0')
        retorno = 0;
    else{
        while(*(str+i) != '\0')
        {
            if((*(str+i) < 'a' || *(str+i) > 'z') && (*(str+i) < 'A' || *(str+i) > 'Z')){
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
int getStringLetras(char* msg,char* msgErr,char* pBuffer)
{
    char aux[128];
    int retorno=-1;
    do{
        getString(msg,aux);
        if(esSoloLetras(aux))
        {
            strcpy(pBuffer,aux);
            retorno=0;
            break;
        }
     msg=msgErr;
    }while(retorno!=0);
    return retorno;
}
int utn_getCaracter(  char* pCaracter, char* msg,char* msgErr,char letraUno,char letraDos)
{
    int retorno=-1,devuelve;
    char bufferChar;
    if( msg != NULL && msgErr != NULL&& (letraUno>=0||letraUno<=255)&& (letraDos>=0||letraDos<=255) )
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            devuelve=getCaracter(&bufferChar);
            bufferChar=toupper(bufferChar);
            if( ( devuelve == 1)&&(bufferChar == letraUno || bufferChar == letraDos))
            {
                *pCaracter = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}
int esTelefono(char str[])
{
   int i=0,retorno=1;
   if(str[i] == '\0'){
        retorno = 0;
   }else{
        while(str[i] != '\0')
        {
            if((str[0] != '+') && (str[i] != '-') && (str[i] < '0' || str[i] > '9')){
                retorno=0;
                break;
            }
            i++;
        }
   }
    return retorno;
}
int getStringTelefono(char* msg,char* msgErr,char* pBuffer)
{
    char aux[21];
    int retorno=-1;
    do{
        getString21(msg,aux);
        if(esTelefono(aux))
        {
            strcpy(pBuffer,aux);
            retorno=0;
            break;
        }
     msg=msgErr;
    }while(retorno!=0);
    return retorno;
}
int esAlfaNumerico(char str[])
{
   int i=0;
   if(str[i] == '\0'){
        return 0;
   }else{
        while(str[i] != '\0')
        {
            if((str[i]!=' ')&&(str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
                return 0;
            i++;
        }
   }
   return 1;
}
int getStringAlfaNumerico(char* msg,char* msgErr,char* pBuffer)
{

    char aux[51];
    int retorno=-1;
    do{
        getString(msg,aux);
        if(esAlfaNumerico(aux))
        {
            strcpy(pBuffer,aux);
            retorno=0;
            break;
        }
     msg=msgErr;
    }while(retorno!=0);
    return retorno;
}

