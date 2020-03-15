/* Digit Count -  Program to count the number of digits in a given number */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  n , d=0 , r , temp ;
 
  clrscr() ;

  printf("Enter a number: ") ;
  scanf("%d" , &n) ;   
  
  if(n==0)  /* Special Case */
    printf("Number of digits in 0 is 1") ;
  else
  {
    temp=n ;
    while(n!=0)
    {
      ++d ;       /* Counting */
      n=n/10 ;  /* Reduce number by 1 digit */
    }
    printf("Number of digits in %d is %d" , temp , d) ;
  }

  getch() ; 
}
/*
Output 1:

Enter a number: 246
Number of digits in 246 is 3

Output 2:

Enter a number: 0
Number of digits in 0 is 1
*/

