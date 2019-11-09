#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"
int menu(){
    int opcion=0;
    printf("****************************************************************************************************\n\n");
    printf("******* 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).  ***************\n");
    printf("******* 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).***************\n");
    printf("******* 3.                           Alta de empleadon.                               ***************\n");
    printf("******* 4.                       Modificar datos de empleado.                         ***************\n");
    printf("******* 5.                           Baja de empleado.                                ***************\n");
    printf("******* 6.                           Listar empleados.                                ***************\n");
    printf("******* 7.                           Ordenar empleados.                               ***************\n");
    printf("******* 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).    ***************\n");
    printf("******* 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).  ***************\n");
    printf("*******10.                                 Salir.                                     ***************\n\n");
    printf("*****************************************************************************************************");
    utn_getEntero(&opcion,"\n\nSeleccione una opcion: ","\n\nERROR.LAS OPCIONES DEBEN SER DEL 1 AL 10: ",1,10);
    return opcion;
}
Employee* employee_new()
{
    Employee* persona=(Employee*) calloc (1,sizeof(Employee));

    if(persona == NULL)
    {
        printf("ERROR. NO HAY ESPACIO. VOLVER A INTENTARLO");
        system("Pause");
    }
    return persona;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* persona=employee_new();
    int aux=0;
    if(employee_setId(persona,atoi(idStr))){
        if(employee_setNombre(persona,nombreStr)){
            if(employee_setHorasTrabajadas(persona,atoi(horasTrabajadasStr))){
                if(employee_setSueldo(persona,atoi(sueldoStr)))
                    aux=1;
            }
        }
    }
    if(aux==0)
    {
        persona = NULL;
    }
    return persona;
}
int employee_setId(Employee* this,int id){
    int aux=0;
    if(this!=NULL&&id>0){
        this->id=id;
        aux=1;
    }
    return aux;
}
int employee_getId(Employee* this,int* id)
{
    int aux=0;
    if(this!=NULL&&id!=NULL){
        *id=this->id;
        aux=1;
    }
    return aux;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int aux=0;
    if(this!=NULL&&nombre!=NULL){
        strcpy(this->nombre,nombre);
        aux=1;
    }
    return aux;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int aux=0;
    if(this!=NULL&&nombre!=NULL){
        strcpy(nombre,this->nombre);
        aux=1;
    }
    return aux;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int aux=0;
    if(this!=NULL&&horasTrabajadas>0){
        this->horasTrabajadas=horasTrabajadas;
        aux=1;
    }
    return aux;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int aux=0;
    if(this!=NULL&&horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        aux=1;
    }
    return aux;
}
int employee_setSueldo(Employee* this,int sueldo){
    int aux=0;
    if(this!=NULL&&sueldo>0){
        this->sueldo=sueldo;
        aux=1;
    }
    return aux;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int aux=0;
    if(this!=NULL&&sueldo!=NULL){
        *sueldo=this->sueldo;
        aux=1;
    }
    return aux;
}
void mostrarEmployee(Employee* emp){
    int id,sueldo,horasTrabajadas;
    char nombre[128];
    if(emp!=NULL){
        employee_getId(emp,&id);
        employee_getHorasTrabajadas(emp,&horasTrabajadas);
        employee_getSueldo(emp,&sueldo);
        employee_getNombre(emp,nombre);
        printf("%d %15s %d   %d\n",id,nombre,horasTrabajadas,sueldo);

    }
}
void mostrarEmployees(LinkedList* lista){
    int i;
    Employee* p;
    for(i=0; i < ll_len(lista); i++){
            p = (Employee*)ll_get(lista, i);
        mostrarEmployee(p);
    }
}
int menu2(int* orden){
    int opcion;
    printf("--------------ORDENAR EMPLEADOS--------------\n");
    printf("\n--- 1.       ORDENAR POR ID              ---");
    printf("\n--- 2.      ORDENAR POR NOMBRE           ---");
    printf("\n--- 3. ORDENAR POR HORAS TRABAJADAS      ---");
    printf("\n--- 4.      ORDENAR POR SUELDO           ---");
    printf("\n--------------------------------------------\n");
    utn_getEntero(&opcion,"\n\nDE QUE FORMA DESEA ORDENAR?: ","ERROR. LAS OPCIONES SON DE 1 A 4: ",1,4);
    printf("\n0 PARA ORDENAR EN ORDEN DESCENDENTE");
    printf("\n1 PARA ORDENAR EN ORDEN ASCENDENTE");
    utn_getEntero(orden,"\n\nDE QUE FORMA DESEA ORDENAR? ","ERROR. ENTRE 0 Y 1: ",0,1);
    return opcion;
}
int employee_id(void* employeeA, void* employeeB)
{
    int retorno,idAux1,idAux2;
    if(employeeA!=NULL&&employeeA!=NULL){
        employee_getId(((Employee*)employeeA),&idAux1);
        employee_getId(((Employee*)employeeB),&idAux2);
        if(idAux1>idAux2){
            retorno=1;
        }
        else if(idAux1<idAux2){
            retorno=-1;
        }
        else{
           retorno=0;
        }
    }
    return retorno;
}
int employee_nombre(void* employeeA, void* employeeB)
{
    char nombre[2][128];
    if(employeeA!=NULL&&employeeA!=NULL){
        employee_getNombre(((Employee*)employeeA),nombre[0]);
        employee_getNombre(((Employee*)employeeB),nombre[1]);
    }
    return strcmp(nombre[0],nombre[1]);
}
int employee_horasTrabajadas(void* employeeA, void* employeeB)
{
    int retorno=0,horasAux1,horasAux2;
    if(employeeA!=NULL&&employeeB!=NULL){
        employee_getHorasTrabajadas(((Employee*)employeeA),&horasAux1);
        employee_getHorasTrabajadas(((Employee*)employeeB),&horasAux2);
        if(horasAux1>horasAux2){
            retorno = 1;
        }
        else if(horasAux1<horasAux2){
            retorno = -1;
        }
        else{
           retorno = 0;
        }
    }
    return retorno;
}
int employee_sueldo(void* employeeA,void* employeeB)
{
    int retorno=0,sueldoAux1,sueldoAux2;
    if(employeeA!=NULL&&employeeB!=NULL){
        employee_getSueldo(((Employee*)employeeA),&sueldoAux1);
        employee_getSueldo(((Employee*)employeeB),&sueldoAux2);
        if(sueldoAux1>sueldoAux2){
            retorno = 1;
        }
        else if(sueldoAux1<sueldoAux2){
            retorno = -1;
        }
        else{
           retorno = 0;
        }
    }
    return retorno;
}



