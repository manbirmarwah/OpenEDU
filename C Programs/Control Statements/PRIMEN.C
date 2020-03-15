/* Prime number - Program to print first n prime numbers */

/* Assume 2 is a prime number but 0 and 1 are not */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , n , p , d , flag ;

  clrscr() ;

  printf("Enter n: ") ;
  scanf("%d",&n) ;

  printf("First %d prime numbers are as follows: \n",n) ;

  p=2 ;
  i=1 ; 
  while(i<=n)
  {
    flag=1 ;

    for(d=2 ; d<=p-1 ; d++)   /* d<=p/2 is also correct */
      if(p%d==0)     /* True if number is not prime */
      {
	    flag=0 ;
	    break ;    /* Loop terminates if p is not prime  */
      }  

    if(flag==1)
    {
       printf("%d ",p) ;
       i++ ;
    }

    p++ ;
  }

  getch() ;
}

/*
Output:

Enter n: 7
First 7 prime numbers are as follows: 
2 3 5 7 11 13 17 
*/
