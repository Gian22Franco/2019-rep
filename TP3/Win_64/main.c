#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "Employee.h"
#include "controller.h"


int main()
{
    int option=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL){
        do{
            system("cls");
            option=menu();
            switch(option)
            {
                case 1:
                    if(!(controller_loadFromText("data.csv",listaEmpleados))){
                        printf("\nNo se pudo cargar los datos del archivo...\n\n");
                        system("pause");
                    }else{
                        printf("\nDATOS CARGADOS\n\n");
                        system("pause");
                    }
                    break;
                case 2:
                    if(!(controller_loadFromBinary("data.bin",listaEmpleados)))
                    {
                        printf("\nNo se pudo cargar los datos del archivo\n\n");
                        system("pause");
                    }else{
                        printf("\nDATOS CARGADOS\n\n");
                        system("pause");
                    }
                    break;
                case 3:
                   // system("cls");
                    if(controller_addEmployee(listaEmpleados)){
                        printf("\nEmpleado cargado.\n");
                        system("pause");
                    }else{
                        printf("\nERROR. Vuelva a intentarlo.\n");
                        system("pause");
                    }
                    break;
                case 4:
                    system("cls");
                    if(controller_editEmployee(listaEmpleados))
                    {
                        printf("MODIFICACION COMPLETADA\n");
                        system("pause");
                    }else{
                        printf("ID INCORRECTO\n");
                        system("pause");
                    }
                    break;
                case 5:
                    system("cls");
                    if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("ELIMINACION EXITOSA\n");
                        system("pause");
                    }else{
                        printf("ID INCORRECTO\n");
                        system("pause");
                    }
                    break;
                case 6:
                    system("cls");
                    if(!(controller_ListEmployee(listaEmpleados))){
                        printf("NO SE ENCONTRARON DATOS\n\n");
                    }
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    if(controller_sortEmployee(listaEmpleados)){
                        printf("\nORDENADO:\n");
                        system("pause");
                    }
                    break;
                case 8:
                    if(controller_saveAsText("data1.csv",listaEmpleados)){
                        printf("\nARCHIVO GUARDADO.\n");
                        system("pause");
                    }else{
                        printf("\nERROR. VUELVA A INTENTARLO\n");
                        system("pause");
                    }
                    break;
                case 9:
                    if(controller_saveAsBinary("data.bin",listaEmpleados)){
                        printf("\nARCHIVO GUARDADO\n");
                        system("pause");
                    }else{
                        printf("\nERROR. VUELVA A INTENTARLO\n");
                        system("pause");
                    }
                    break;
                case 10:
                    ll_deleteLinkedList(listaEmpleados);
                    break;
                default:
                    system("cls");
                    printf("ERROR. VUELVA A INTENTARLO");
                    system("pause");
            }
        }while(option != 10);
    }else{
        printf("ERROR. VUELVA A INTENTARLO");
        system("pause");
    }
    return 0;
}
