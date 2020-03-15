/* Armstrong number 1 to 1000 - Write a function to check whether a given number is an armstrong number. Use this function to generate all armstrong numbers from 1 to 1000 */

#include  <stdio.h>
#include  <conio.h>

int check_armstrong(int  n) ;
 
void  main()
{
  int  n ;

  clrscr() ;

  printf("Armstrong numbers from 1 to 1000 are as shown: \n") ;
  for(n=1 ; n<=1000 ; n++)
    if(check_armstrong(n) == 1)
      printf("%d " , n) ;
  
  getch() ; 
}

int check_armstrong(int  n) 
{
  int  sum=0 , r , temp ;

  temp=n ;
  while(n!=0)
  {
    r=n%10 ;    /* Extract the last digit */
    sum=sum+r*r*r ;  /* Finding sum */
    n=n/10 ;    /* Reduce number by 1 digit */
  }
  
  if(sum==temp)
    return 1 ;
  else
    return 0 ;
}

/*
Output :

Armstrong numbers from 1 to 1000 are as shown: 
1 153 370 371 407 
*/



