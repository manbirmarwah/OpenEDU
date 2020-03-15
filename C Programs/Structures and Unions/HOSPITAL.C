/* Structure - Hospital - A hospital needs to maintain details of patients. Details to be maintained are first name, middle name, surname, date of birth and disease. Write a C program which will print list of all patients with given disease. */

#include  <stdio.h>
#include  <string.h>
#include  <conio.h>

void  main()
{
  struct  date
  {
    int  d , m , y ;
  } ;
  struct  hospital
  {
    char  firstname[20] , middlename[20] , surname[20] ;
    struct  date  dob ;
    char  disease[20];
  } ;
  struct  hospital  h[50] ;
  int  i , j , n ;
  char  d[20] ;

  clrscr();

  printf("Enter the number of patients: ") ;
  scanf("%d" , &n) ;

  printf("Enter first name, middle name, surname, date of birth and disease for all patients: \n") ;
  printf("Enter date of birth in d/m/y format. \n") ;
  for(i=0 ; i<n ; i++)
    scanf("%s %s %s %d %d %d %s" , h[i].firstname , h[i].middlename , h[i].surname , &h[i].dob.d , &h[i].dob.m , &h[i].dob.y , h[i].disease ) ;

  printf("\nEnter disease name for which patient details are required: ") ;
  scanf("%s" , d) ;

  printf("\nPatients suffering from %s are as shown:\n" , d) ;
  for(i=0 ; i<n ; i++)
    if( strcmpi(h[i].disease , d) == 0 )
      printf("%s %s %s %d %d %d %s \n" , h[i].firstname , h[i].middlename , h[i].surname , h[i].dob.d , h[i].dob.m , h[i].dob.y , h[i].disease ) ;

  getch();	
}

/*
Output:

Enter the number of patients: 3
Enter first name, middle name, surname, date of birth and disease for all patients: 
Enter date of birth in d/m/y format. 
Amit Kumar Mehta 12 11 92 Dengue
Rahul Anand Dixit 10 6 94 Typhoid
Pooja Rajesh Lalwani 8 2 91 Dengue

Enter disease name for which patient details are requierd: Dengue

Patients suffering from Dengue are as shown:
Amit Kumar Mehta 12 11 92 Dengue 
Pooja Rajesh Lalwani 8 2 91 Dengue 

*/


 
