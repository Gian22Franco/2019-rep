#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "validaciones.h"


/** \brief Carga los empleados, modo texto.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    int retorno=1;
    pFile = fopen(path, "r");
    if(pFile!=NULL&&path!=NULL)
    {
        if(!(parser_EmployeeFromText(pFile,pArrayListEmployee)))
            retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los empleados, modo binario.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=1;
    pFile = fopen(path, "rb");
    if(pFile!=NULL&&path!=NULL)
    {
        if(!(parser_EmployeeFromBinary(pFile,pArrayListEmployee)))
            retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int idAux,sueldoAux,horasAux,retorno=0,i,idComprobacion;
    char nombre[128],buffer[3][20];
    if(pArrayListEmployee!=NULL){
        printf("---Carga de empleados---\n\n");
        do{
            utn_getEntero(&idAux,"ID Empleado: ","ERROR. EL ID DEBE SER UN N ENTRE 1 Y 10000: ",1,10000);
            for(i=0;i<ll_len(pArrayListEmployee);i++){
                auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(auxEmployee,&idComprobacion);
                if(idComprobacion==idAux){
                    utn_getEntero(&idAux,"ID REPETIDO: ","ERROR. EL ID DEBE SER UN N° ENTRE 1 Y 10000: ",1,10000);
                    i=0;
                }
            }
        }while(i!=ll_len(pArrayListEmployee));
        itoa(idAux,buffer[0],10);
        getStringLetras("INGRESE NOMBRE : ","ERROR. EL NOMBRE SOLO PUEDE CONTENER LETRAS ",nombre);
        utn_getEntero(&horasAux,"INGRESE HORAS TRABAJADAS: ","ERROR. LAS HORAS DEBEN ESTAR ENTRE 50 Y 600: ",50,600);
        itoa(horasAux,buffer[1],10);
        utn_getEntero(&sueldoAux,"INGRESE SUELDO: ","ERROR. EL SUELDO DEBE SER UN N° ENTRE 4000 Y 300.000:",4000,300000);
        itoa(sueldoAux,buffer[2],10);
        auxEmployee=employee_newParametros(buffer[0],nombre,buffer[1],buffer[2]);
        if(auxEmployee != NULL){
            ll_add(pArrayListEmployee,auxEmployee);
            retorno=1;
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[128];
    int idAux,idAuxRemove,i,retorno=0,sueldoAux,horasAux,index;
    Employee* auxEmployee=employee_new();
    if(pArrayListEmployee != NULL&&auxEmployee!=NULL)
    {
        mostrarEmployees(pArrayListEmployee);
        utn_getEntero(&idAuxRemove,"ID A MODIFICAR: ","ERROR. LOS ID CORRESPONDEN A UN N ENTRE 1 Y 10000: ",1,10000);
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            if(employee_getId(auxEmployee,&idAux))
            {
                if(idAux==idAuxRemove)
                {
                    index=ll_indexOf(pArrayListEmployee,auxEmployee);
                    printf("ID: %d\n",idAux);
                    getStringLetras("INGRESE NUEVO NOMBRE: ","ERROR.SOLO PUEDEN SER LETRAS",nombre);
                    employee_setNombre(auxEmployee,nombre);
                    utn_getEntero(&horasAux,"INGRESE NUEVAS HORAS TRABAJADAS: ","ERROR. LAS HORAS DEBEN SER ENTRE 50 Y 600",50,600);
                    employee_setHorasTrabajadas(auxEmployee,horasAux);
                    utn_getEntero(&sueldoAux,"iNGRESE NUEVO SUELDO: ","ERROR. EL SUELDO DEBE SER ENTRE 4000 Y 300.000",4000,300000);
                    employee_setSueldo(auxEmployee,sueldoAux);
                    ll_set(pArrayListEmployee,index,auxEmployee);
                    retorno=1;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief Da de baja un empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    int idAux,idAuxRemove,i,retorno=0;
    Employee* auxEmployee=employee_new();
    if(pArrayListEmployee != NULL&&auxEmployee!=NULL)
    {
        mostrarEmployees(pArrayListEmployee);
        utn_getEntero(&idAuxRemove,"ID A REMOVER:","ERROR. LOS ID VAN DE 1 A 10000: ",1,10000);
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            if(employee_getId(auxEmployee,&idAux))
            {
                if(idAux==idAuxRemove)
                {
                    retorno=1;
                    ll_remove(pArrayListEmployee,i);
                    break;
                }
            }
        }
    }
    else
    {
        printf("ERROR.VOLVER A INTENTAR \n");
    }
    return retorno;
}

/** \brief Mostrar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    if(ll_len(pArrayListEmployee)==0){
        retorno=0;
    }else{
        printf("%s %15s %s %s\n","id","nombre","horas","sueldo");
        mostrarEmployees(pArrayListEmployee);
        retorno=1;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion,retorno,orden;
    if(pArrayListEmployee == NULL){
        printf("ERROR. NO HAY DATOS EN LA LISTA. \n");
    }
    else
    {
        opcion=menu2(&orden);
        switch(opcion){
        case 1:
            ll_sort(pArrayListEmployee,employee_id,orden);
            retorno=1;
            break;
        case 2:
            ll_sort(pArrayListEmployee,employee_nombre,orden);
            retorno=1;
            break;
        case 3:
            ll_sort(pArrayListEmployee,employee_horasTrabajadas,orden);
            retorno=1;
            break;
        case 4:
            ll_sort(pArrayListEmployee,employee_sueldo,orden);
            retorno=1;
            break;
        }
    }
    return retorno;
}

/** \brief Guarda los empleados, modo texto.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path, "w");
    int retorno=0;
    Employee* p;
    int i;
    if(path!=NULL&&pFile!=NULL&&pArrayListEmployee!=NULL){
        fprintf(pFile,"%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");
        for(i=0; i<ll_len(pArrayListEmployee);i++){
            p = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(pFile,"%d,%s,%d,%d\n",p->id,p->nombre,p->horasTrabajadas,p->sueldo);
        }
        if(i==ll_len(pArrayListEmployee)){
            retorno=1;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Guarda los empleados, modo binario.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path, "wb");
    Employee* p;
    int i,retorno=0;
    if(path!=NULL&&pFile!=NULL&&pArrayListEmployee!=NULL){
        for(i=0; i<ll_len(pArrayListEmployee);i++){
            p = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(p, sizeof(Employee), 1, pFile);
        }
        if(i==ll_len(pArrayListEmployee)){
            retorno=1;
        }
    }
    fclose(pFile);
    return retorno;
}
