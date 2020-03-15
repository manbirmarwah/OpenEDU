/* Nested if-else - Program to print 3 given numbers in ascending order using nested if-else. Usage of && is not allowed */

#include  <stdio.h>
#include  <conio.h>

void main()
{
 int  a , b , c ;

 clrscr() ;

 printf("Enter three numbers: ") ;
 scanf("%d %d %d" , &a , &b , &c) ;

 printf("Three values in ascending order are: ") ;
 if(a<b)
   if(a<c)
     if(b<c)
       printf("%d %d %d" , a , b , c) ;
     else
       printf("%d %d %d" , a , c , b) ;
   else
     printf("%d %d %d" , c , a , b) ;
 else
   if(b<c)
     if(a<c)
       printf("%d %d %d" , b , a , c) ;
     else
       printf("%d %d %d" , b , c , a) ;
   else
     printf("%d %d %d" , c , b , a) ;

 getch() ;
}

/*
Output:

Enter three numbers: 4 6 2
Three values in ascending order are: 2 4 6
*/

