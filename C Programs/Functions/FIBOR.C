/* Fibonacci - Write a recursive function to find the nth term of fibonacci series. Using this function print the first n terms of fibonacci series */

/* We assume that fibonacci series starts with 1 1 */

#include  <stdio.h>
#include  <conio.h>

long  fibo(int  n)
{
  if( (n==1) || (n==2) ) 
    return  1 ;  else  
    return( fibo(n-1) + fibo(n-2) ) ;
}

void main()
{
  int  i , n ;

  clrscr() ;

  printf("Enter n:") ;
  scanf("%d" , &n) ;

  printf("First %d terms of fibonacci series are: \n" , n) ;
  for(i=1 ; i<=n ; i++)
    printf("%ld " , fibo(i) ) ; 

  /* Dont write fibo(n) by mistake */

  getch() ;
}

/* If fibonacci series starts with 0 1 then the following function should be given

long  fibo (int n)
{
  if(n==1)
	return  0;
  else  if (n==2)
	return  1;
  else
	return (fibo(n-1) + fibo(n-2));
}
 */

/*
Output:

Enter n:4
First 4 terms of fibonacci series are: 
1 1 2 3 
*/

