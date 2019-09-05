#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>



int numeroEntero(char msj[]){

int unNumero;
printf("%s", msj);
scanf("%d", &unNumero);
return unNumero;

}

int sumar (int numeroUno, int numeroDos){
    int suma= numeroUno + numeroDos;
    return printf("El resultado de %d + %d es %d\n", numeroUno, numeroDos, suma);
}
int restar (int numeroUno, int numeroDos){
    int resta= numeroUno-numeroDos;
    return printf("El resultado de %d - %d es %d\n", numeroUno, numeroDos, resta);
}
int multiplicar (int numeroUno, int numeroDos){
    int multiplicacion= numeroUno*numeroDos;
    return printf("El resultado de %d * %d es %d\n", numeroUno, numeroDos, multiplicacion);
}

int dividir (int numeroUno, int numeroDos){

    while (numeroDos != 0){
    int  division= numeroUno/numeroDos;
    return printf("El resultado de %d / %d es %d\n" , numeroUno, numeroDos, division);
}
printf("No se puede dividir por 0\n");
}






/*while (numero1 < 0 || numero2 < 0){*/


int factorial1 (int numero1){



int resultado;


if(numero1 == 0){
    resultado=1;

}
else {
    resultado = numero1 * factorial1(numero1- 1);

}
 return resultado;
}


int factorial (int numero1,int numero2){
    int resultado1;
    int resultado2;



    if(numero1 == 0){
        resultado1=1;

}
else {

        resultado1 = numero1 * factorial1(numero1- 1);

}

if (numero2 == 0)
{
    resultado2=1;

}else {

    resultado2 = numero2*factorial1(numero2-1);

}


    return printf("El factorial de %d! es: %d  y El factorial de %d! es: %d\n", numero1, resultado1, numero2, resultado2);
}

/*printf("Error, no se puede sacar factorail de un numero negativo");

 }*/
