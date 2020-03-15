/* Armstrong number -  Program to check whether a given number is an armstrong number */

/* We consider an armstrong number to be a 3 digit number in which sum of cubes of digits is equal to number itself. An armstrong number can be defined in other ways too, but the above definition is the most popular one. */

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
    sum=sum+r*r*r ;  /* Finding sum */
    n=n/10 ;    /* Reduce number by 1 digit */
  }
  
  if(sum==temp)
    printf("%d is an armstrong number" , temp) ;
  else
    printf("%d is not an armstrong number" , temp) ;

  getch() ; 
}
/*
Output 1:

Enter a number: 153
153 is an armstrong number

Output 2:

Enter a number: 152
152 is not an armstrong number
*/


