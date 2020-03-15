/* Perfect Square - Program to find four digit perfect squares, where the number represented by the first two digits and the number represented by the last two digits are also perfect squares. */

/* For eg 1681=41^2  16=4^2  81=9^2 */

#include  <stdio.h>
#include  <conio.h>
#include  <math.h>

void main()
{
  int  n , n1 , n2 , i , flag1 , flag2 , flag3 ;

  clrscr() ;

  printf("Four digit perfect squares with required property are as shown:\n");
  for(n=1000 ; n<=9999 ; n++)
  {
    n1=n%100 ;  /*Extracting last two digits*/
    n2=n/100 ;   /*Extracting first two digits*/

    /*Checking whether the first two digits are perfect squares*/
    flag1=0 ;
    i=sqrt(n2) ;  /* Remember i is integer whereas sqrt() returns double */
    if(n2==i*i)
      flag1=1 ;
		
    /*Checking whether the last two digits are perfect squares*/
    flag2=0 ;
    i=sqrt(n1) ;  
    if(n1==i*i)
      flag2=1 ;
		
    /*Checking whether the number itself is a perfect square*/
    flag3=0 ;
    i=sqrt(n) ;
    if(n==i*i)
	 flag3=1 ;

    if(flag1==1 && flag2 ==1 && flag3==1)
       printf("%d " , n) ;
  }

  getch() ;
}

/*
OutputFour digit perfect squares with required property are as shown:
1600 1681 2500 3600 4900 6400 8100 
*/
