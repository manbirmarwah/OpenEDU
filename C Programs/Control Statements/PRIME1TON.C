/* Prime number - Program to print prime numbers from 1 to n or between 1 and n or till n */

/* Assume 2 is a prime number but 0 and 1 are not */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  n , p , d , flag ;

  clrscr() ;

  printf("Enter n: ") ;
  scanf("%d" , &n) ;

  printf("Prime numbers till %d are as shown: \n" , n) ;

  for(p=2 ; p<=n ; p++)
  {
    flag=1 ;     /* Assuming p is prime */

    for(d=2 ; d<=p-1 ; d++)   /* d<=p/2 is also correct */
      if(p%d==0)     /* True if number is not prime */
      {
	   flag=0 ;
	   break ;    /* Inner Loop terminates if p is not prime  */
      }

    if(flag==1)
       printf("%d ", p) ;
  }

  getch() ;
}

/*
A Similar Program could be:
Program to read two natural numbers r1 and r2 where r2>r1 and generate all prime numbers between r1 and r2 both inclusive.
*/

/*
Output 1:

Enter n: 13
Prime numbers till 13 are as shown: 
2 3 5 7 11 13 

Output 2:

Enter n: 14
Prime numbers till 14 are as shown: 
2 3 5 7 11 13 
*/

