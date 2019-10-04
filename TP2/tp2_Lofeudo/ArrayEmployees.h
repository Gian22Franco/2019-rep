#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define OCUPADO 1
#define LIBRE 0



struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;

}typedef Employee;

int initEmployees(Employee* , int);
Employee askEmployees();
void mostrarListadoDeAlumnos(Employee*, int );
int addEmployee(Employee* , int);
int findEmployeeById(Employee* , int ,int );
int removeEmployee(Employee*, int);
int sortEmployees(Employee*,int,int);
int printEmployees(Employee*, int );
int searchEmployeeFree(Employee*, int );
void modifyEmployees(Employee* , int );
float salaryOperationTotal (Employee* , int );
float salaryOperationProm (Employee[] , int );
int salaryUp(Employee[] , int);

