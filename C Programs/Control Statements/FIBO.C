/* Fibonacci (first n) - Program to print the first n terms of fibonacci series */

/* We assume that the fibonacci series starts with 1 1 */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  long  a=1 ,b=1 , c ; 
  int  i , n ;

  clrscr() ;

  printf("Enter n: ") ;
  scanf("%d" , &n) ;

  printf("Fibonacci series is as shown: \n") ;

  if(n==1)
    printf("%ld" , a) ;
  else if(n==2)
    printf("%ld %ld" , a , b) ;
  else if(n>2)
  {
	printf("%ld %ld" , a , b) ;
     for(i=1 ; i<=n-2 ; i++)
     {
       c=a+b ;
       printf(" %ld" , c) ;
       a=b ;
       b=c ;
     }
  }

  getch();
}

/*
Output 1:

Enter n: 1
Fibonacci series is as shown: 
1

Output 2:

Enter n: 2
Fibonacci series is as shown: 
1 1

Output 3:

Enter n: 6
Fibonacci series is as shown: 
1 1 2 3 5 8
*/

/* 
Note:
If the fibonacci series starts with 0 1 then all we need to do is initialize a=0 instead of a=1
*/



