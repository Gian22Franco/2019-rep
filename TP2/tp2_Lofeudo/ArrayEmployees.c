#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
    int i;
    int retorno= -1;

    //if (list != NULL && len>0)
    //{
    for (i=0; i< len; i++)
    {
        list[i].isEmpty=LIBRE;
        retorno = 0;
    }
    //}
    return retorno;
}
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len)
{
    int i;
    int retorno = 0;
    i = searchEmployeeFree(list,len);
    if(i != -1)//Hay lugar
    {
        list[i] = askEmployees();
        //list[i].isEmpty = OCUPADO;
        retorno = 1;
    }
    return retorno;
}
/** \brief Le pide al usuario que ingrese sus datos
 *
 * \return Employee datos
 *
 */
Employee askEmployees()
{
    Employee employeeAux;

        printf("Ingrese su nombre:");
        fflush(stdin);
        gets(employeeAux.name);
        printf("Ingrese su apellido:");
        fflush(stdin);
        gets(employeeAux.lastName);
        printf("Ingrese su salario:");
        scanf("%f", &employeeAux.salary);
        printf("Ingrese su Sector:");
        scanf("%d", &employeeAux.sector);
        printf("Ingrese su ID:");
        scanf("%d", &employeeAux.id);
        employeeAux.isEmpty = OCUPADO;
    return employeeAux;
    }
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id)
{
    int i;
    int retorno=-1;
    if(list!=NULL && len >0)
    {
        for (i=0; i<len; i++)
        {
            if (list[i].id==id)
            {
                return i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len)
{
    int retorno = -1;
    int id;
    int index;
    char respuesta;
    if( list != NULL && len > 0)
    {
        mostrarListadoDeAlumnos(list, len);
        printf("Ingrese un id: \n");
        scanf("%d", &id);
        index = findEmployeeById(list, len, id);
        if(index != -1)
        {
            //printEmployees(list[index], len);
            printf("Esta seguro que quiere eliminar el dato: \n");
            respuesta = getche();
            if(respuesta == 's')
            {
                list[index].isEmpty = LIBRE;
                retorno = 0;
            }
            else
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}
/** \brief Te muestra el listado de empleados y sus datos ordenados
 *
 * \param Employee*list
 * \param len int
 * \return void los datos ingresados
 *
 */
void mostrarListadoDeAlumnos(Employee*list, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            printEmployees(list, len);
        }
    }
}
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void modifyEmployees(Employee* list, int len)
{
    int id;
    int opcion;
    printf("\nIngrese ID:\n");
    printEmployees(list,len);
    scanf("%d", &id);
    printf("\nQue desea modificar?\n");
    printf("\n1. Nombre\n2. Apellido\n3. Sueldo\n4. Sector\n");
    scanf("%d", &opcion);
    char auxName[50];
    char auxLastName[50];
    float auxSalary;
    int auxSector;
    switch(opcion)
    {
    case 1:
        printf("\nIngrese nuevo Nombre:\n");
        fflush(stdin);
        gets(auxName);
        strcpy(list[id-1].name, auxName);
        break;
    case 2:
        printf("\nIngrese nuevo Apellido:\n");
        fflush(stdin);
        gets(auxLastName);
        strcpy(list[id-1].lastName, auxLastName);
        break;
    case 3:
        printf("\nIngrese nuevo Salario:\n");
        scanf("%f",&auxSalary);
        list[id-1].salary = auxSalary;
        break;
    case 4:
        printf("\nIngrese nuevo Sector:\n");
        scanf("%d",&auxSector);
        list[id-1].sector= auxSector;
        break;


    }


}
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            printf("ID:%d-----NOMBRE:%s-----APELLIDO:%s-----SALARIO:%f-----SECTOR:%d\n",list[i].id, list[i].name,list[i].lastName,list[i].salary, list[i].sector);
        }
    }
    return 0;
}
/** \brief Busca la posicion del empleado que no tenga nada asignado
 *
 * \param list Employee*
 * \param len int
 * \return int el indice
 *
 */
int searchEmployeeFree(Employee* list, int len)
{
    int i;
    int index = -1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int i;
    int j;
    Employee auxEmployee;

    for ( i=0; i<len-1; j++)
    {
        for (j=i+1;j<len;j++)
        {
            if (list[i].isEmpty != LIBRE && list[i].sector > list[j].sector)
            {
                auxEmployee=list[i];
                list[i]=list[j];
                list[j]= auxEmployee;
            }
        }
    }
    for (i=0;i< len-1 ; i++)
    {
        for (j=i+1; j< len; j++)
        {
            if (list[i].isEmpty != LIBRE &&list [i].sector == list[j].sector)
            {
                if (strcmp(list[i].lastName, list[j].lastName)>0)
                {
                    auxEmployee = list [i];
                    list [i]=list [j];
                    list[j]=auxEmployee;
                }
            }
        }
    }
printEmployees(list,len);
return 0;
}
//Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
/** \brief Calcula el total de los salarios
 *
 * \param list[] Employee
 * \param len int
 * \return float el total de los salarios
 *
 */
float salaryOperationTotal(Employee list[], int len)
{
    float acumulador;
    int i;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty != LIBRE)
        {
            acumulador = acumulador + list[i].salary;
        }
    }
    return acumulador;
}


/** \brief Calcula el promedio del total de los salarios
 *
 * \param list[] Employee
 * \param len int
 * \return float El promedio
 *
 */
float salaryOperationProm(Employee list[], int len)
{
    int contador = 0;
    float acumulador;
    float retorno;
    int i;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty != LIBRE)
        {
            acumulador = acumulador + list[i].salary;
            contador ++;
        }
        retorno=acumulador/contador;
    }
    return retorno;

}

/** \brief Calcula la cantidad de salarios que superan el promedios
 *
 * \param list[] Employee
 * \param len int
 * \return int la cantidad
 *
 */
int salaryUp(Employee list[], int len)
{
    int i;
    int contador = 0;
    float prom = salaryOperationProm(list, len);
    for(i = 0; i < len; i ++)
    {
        if(list[i].isEmpty != LIBRE && list[i].salary > prom)
        {
            contador++;
        }
    }
    return contador;
}



