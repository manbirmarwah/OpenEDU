/* Structure - Employee ID Sort - Program to create an array of structure to store details of almost 100 employees and sort it according to employee ID. Employee details are as follows: 1) Employee Name , 2) Employee ID and 3) Employee Salary */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  struct  employee
  {
    char  name[20] ;
    int  id ;
    float  salary ;
  } ;
  /* Some compilers do not allow float member in a structure. In that case make salary to be of data type int */
  struct  employee  e[100] , temp ;
  int i , j , n ;

  clrscr() ;

  printf("Enter the number of employees: ") ;
  scanf("%d" , &n)  ;

  printf("Enter employee name , id and salary for all employees: \n") ;
  for(i=0 ; i<n ; i++)
    scanf("%s %d %f" , e[i].name , &e[i].id , &e[i].salary) ;
  
  for(i=0 ; i<n-1 ; i++)
    for(j=0 ; j<n-1-i ;j++)
       if(e[j].id > e[j+1].id)
       {      
		   	temp=e[j];
       		e[j]=e[j+1];
       		e[j+1]=temp;
       }

  printf("\nList in ascending order of employee id is as shown:\n") ;
  for(i=0 ; i<n ; i++)
      printf("%s  %d %f \n" , e[i].name , e[i].id , e[i].salary) ;

  getch() ;
}

/*
Output:

Enter the number of employees: 3
Enter employee name , id and salary for all employees: 
Jack  789  500.5
Jill  123  600.25
Tim  456  200.75

List in ascending order of employee id is as shown:
Jill  123 600.250000 
Tim  456 200.750000 
Jack  789 500.500000 

*/

