#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define A 2

int main()
{
    system("color 7f");
    Employee myEmployee[A];

    int opcion;
    int opcion2;
    int retorno;
    int flag=0;

    if(initEmployees(myEmployee,A)==0)
    {
        do
        {
            printf("                                      :|~~~~~~~~~~~~~~~~~~~~|:\n");
            printf("                                      :|     1 ALTA         |:\n");
            printf("                                      :|     2 MODIFICAR    |:\n");
            printf("                                      :|     3 BAJA         |:\n");
            printf("                                      :|     4 INFORMAR     |:\n");
            printf("                                      :|     5 SALIR        |:\n");
            printf("                                      :|~~~~~~~~~~~~~~~~~~~~|:\n");
            printf("                                          Elija una opcion: ");
            scanf("%d", &opcion);

            while(opcion != 1 && opcion !=5 && flag!=1 )
            {
                printf("                                   Primero debe ingresar un numero.\n");
                opcion=1;

            }
            switch(opcion)
            {
            case 1:
                addEmployee(myEmployee, A);
                printEmployees(myEmployee,A);
                flag=1;
                break;
            case 2:
                modifyEmployees (myEmployee,A);
                printEmployees(myEmployee,A);

                break;
            case 3:
                //printEmployees(myEmployee,A);
                retorno = removeEmployee(myEmployee, A);
                switch(retorno)
                {
                case 0:
                    printf("Se elimino\n");
                    break;

                case 1:
                    printf("Accion Cancelada\n");
                    break;

                case -1:
                    printf("No se encontro el dato\n");

                    break;
                }

                break;
            case 4:
                printf("Que operacion desea realizar?\n");
                printf("1.Ordenar por Apellido y Sector:\n");
                printf("2.Calcular Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
                scanf("%d", &opcion2);
                switch(opcion2)
                {
                case 1 :
                    sortEmployees(myEmployee,A,0);
                    break;

                case 2 :
                    printf("Total: %f \nPromedio: %f \nSuperan al promedio: %d ",
                           salaryOperationTotal(myEmployee,A),salaryOperationProm(myEmployee,A),
                           salaryUp(myEmployee,A));

                    break;

                }

            }
            system("pause");
            system("cls");
        }
        while(opcion != 5);


    }
    else
    {
        printf("No hay mas lugar. \n");
    }

    return 0;
}




