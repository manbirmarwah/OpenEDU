/*  Reversing a number - Program to find reverse of a given number */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  n , rev=0 , r , temp ;
 
  clrscr() ;

  printf("Enter a number: ") ;
  scanf("%d" , &n) ;   

  temp=n ;
  while(n!=0)
  {
    r=n%10 ;    /* Extract the last digit */
    rev=rev*10+r ;  /* Find reverse */
    n=n/10 ;    /* Reduce number by 1 digit */
  }
  
  printf("Reverse of %d is %d" , temp , rev) ;

  getch() ; 
}

/*
Output 1:

Enter a number: 246
Reverse of 246 is 642

Output 2:

Enter a number: 0
Reverse of 0 is 0
*/


