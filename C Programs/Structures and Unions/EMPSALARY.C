/* Structure - Employee Salary - Program to create a record for an employee having name, code and salary. Read information for 30 employees and display details of all those employees having salary greater than 10000 */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  struct  employee
  {
    char  name[20] ;
    int  code ;
    float  salary ;
  } e[30] ;
    /* Some compilers do not allow float member in a structure. In that case make salary to be of data type int */
  int i ;

  clrscr() ;

  printf("Enter employee name , code and salary for 30 employees: \n") ;
  for(i=0 ; i<30 ; i++)
    scanf("%s %d %f" , e[i].name , &e[i].code , &e[i].salary) ;
  

  printf("\nThe following employees have salary greater than 10000:\n") ;
  for(i=0 ; i<30 ; i++)
    if(e[i].salary>10000)
      printf("%s  %d %f \n" , e[i].name , e[i].code , e[i].salary) ;

  getch() ;
}

/*
The following output is only for 3 employees:

Enter employee name , code and salary for 30 employees: 
Jack  123  12000.75
Jill  456  9850.5
Tim 789 17000.75

The following employees have salary greater than 10000:
Jack  123 12000.750000 
Tim  789 17000.750000 

*/

