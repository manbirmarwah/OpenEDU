/* Structure - Mobile customers -Program to read the names of mobile customers through keyboard and sort them alphabetically on last name. Display the sorted list on monitor. */

#include   <stdio.h>
#include   <conio.h>
#include   <string.h>

void main()
{
  struct name
  {
    char fname[20] ;
    char lname[20] ;
  } ;
  struct  name  x[50] , temp ;
  int  i , j , n ;

  clrscr() ;

  printf("Enter the number of mobile customers: ") ;
  scanf("%d" , &n) ;

  printf("Enter names of mobile customers in the format: \n") ;
  printf("FIRST NAME   LAST NAME \n") ;

  for(i=0 ; i<n ; i++)
    scanf("%s %s" , x[i].fname , x[i].lname) ;

  for(i=0 ; i<n-1 ; i++)
    for(j=0 ; j<n-1-i ; j++)
      if( strcmp(x[j].lname , x[j+1].lname) >0 )
      {
        temp=x[j] ;
        x[j]=x[j+1] ;
        x[j+1]=temp ;
      }

  printf("\nList sorted alphabetically as per last name is as shown:\n") ;
  for(i=0;i<n;i++)
    printf("%s %s \n" , x[i].fname , x[i].lname) ;

  getch() ;
}

/* In this program I have used strcmp() to compare two strings. strcmp() is case sensitive. A better option is to use strcmpi() which is not case sensitive. However, some compilers do not support strcmpi() */

/*
Output:

Enter the number of mobile customers: 3
Enter names of mobile customers in the format: 
FIRST NAME   LAST NAME 
Tarun  Kapoor
Sandeep  Gupta
Amit  Doshi

List sorted alphabetically as per last name is as shown:
Amit Doshi 
Sandeep Gupta 
Tarun Kapoor 
*/
