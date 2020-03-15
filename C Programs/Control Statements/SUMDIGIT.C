/* Sum of digits -  Program to find sum of digits of a given number */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  n , sum=0 , r , temp ;
 
  clrscr() ;

  printf("Enter a number: ") ;
  scanf("%d" , &n) ;   

  temp=n ;
  while(n!=0)
  {
    r=n%10 ;    /* Extract the last digit */
    sum=sum+r ;  /* Finding sum */
    n=n/10 ;    /* Reduce number by 1 digit */
  }
  
  printf("Sum of digits of %d is %d" , temp , sum) ;

  getch() ; 
}
/*
Output

Enter a number: 246
Sum of digits of 246 is 12
*/

