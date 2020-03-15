/* Fibonacci (1 to n) - Program to print those terms of fibonacci series which are between 1 and n */

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
    printf("%ld %ld " , a , b) ;
  else if(n>1)
  {
	printf("%ld %ld " , a , b) ;
	c=a+b ;
     do
     {
       printf(" %ld " , c) ;
       a=b ;
       b=c ;
       c=a+b ;
     }
     while(c<=n) ;
  }

  getch() ;
}

/*
Output 1:

Enter n: 1
Fibonacci series is as shown: 
1 1 

Output 2:

Enter n: 3
Fibonacci series is as shown: 
1 1  2  3 

Output 3:

Enter n: 4
Fibonacci series is as shown: 
1 1  2  3 
*/

