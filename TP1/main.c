#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


/**1.
Programa: Trabajo Practico 1.

Consignas:
1.Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir

Autor: Gianfranco Lofeudo.
Division: 1° B
Turno: Mañana
Fecha de Entrega: 06/09/2019.
<  */



int main()
{

    int numeroUno = numeroEntero("Ingrese el primer numero: ");
    int numeroDos = numeroEntero("Ingrese el segundo numero: ");
    sumar(numeroUno, numeroDos);
    restar (numeroUno,numeroDos);
    multiplicar (numeroUno,numeroDos);
    dividir (numeroUno,numeroDos);
    factorial (numeroUno, numeroDos);

}
