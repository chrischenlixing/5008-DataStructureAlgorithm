/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/
typedef struct employee
{
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

}employee_t;
/* Read the employee details using scanf*/
void readData(int n, employee_t* s)
{
    // Add your code here
     int i;
     for ( i = 0; i<n; i++) {
        printf("Enter Employee Id:");
        scanf("%d", &s[i].empId);
        printf("Enter Employee Name:");
        scanf("%s", s[i].Name);
        printf("Enter Employee Designation:");
        scanf("%s", s[i].Designation);
        printf("Enter Employee Department:");
        scanf("%s", s[i].Dept);
    }
}
/* Function to print the employee details*/
void display(int n, employee_t * s)
{
    // Add your code here
    int i;
    for ( i = 0; i<n; i++) {
        printf("The details of the employee %d \n",i);
        printf("Employee Id is %d \n", s[i].empId);
        printf("Employee name is %s \n", s[i].Name);
        printf("Employee Designation is %s \n", s[i].Designation);
        printf("Employee Department is %s \n", s[i].Dept);
    }
    
}

/*----------Main Program--------*/
int main()

{
    // Main Function to print the employee details
    // Add your code here
    int num_employee;
    printf("Enter the number of employees: ");
    scanf("%d", &num_employee);
    employee_t *s = (employee_t*) malloc(num_employee * sizeof (employee_t));
    readData(num_employee, s);
    display(num_employee, s);

    return 0; 

}

