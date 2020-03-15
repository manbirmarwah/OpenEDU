/* Prime number - Program  to check whether a given number is prime or not */

/* Assume 2 is a prime number but 0 and 1 are not */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  p ,d , flag ;

  clrscr() ;

  printf("Enter a number: ") ;
  scanf("%d" , &p) ;

  flag=1 ;     /* Assuming p is prime */
  for(d=2 ; d<=p-1 ; d++)   /* d<=p/2 is also correct */
     if(p%d==0)     /* True if number is not prime */
     {
	  flag=0 ;
	  break ;    /* Loop terminates if p is not prime  */
     }

  if(flag==0 || p==1 || p==0 ) 
    printf("%d is not prime" , p) ;
  else
    printf("%d is prime" , p) ;

  getch() ;
}

/*
Output 1:

Enter a number: 1
1 is not prime

Output 2:

Enter a number: 7
7 is prime

Output 3:

Enter a number: 9
9 is not prime
*/
