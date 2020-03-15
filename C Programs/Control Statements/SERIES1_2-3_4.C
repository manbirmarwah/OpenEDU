/* Sum of series - Program to calculate sum of series 1/2 - 3/4 + 5/6 - 7/8 ....... upto n terms  -  June 2014 */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , n ;
  float  k , s=0 ;
 
  clrscr() ;
 
  printf("Enter n: ") ;
  scanf("%d" , &n) ;

  /* i keeps track of term count , whereas k is used for calculation purpose */

  for(i=1 , k=1 ; i<=n ; i++ , k=k+2)
  {
    if(i%2==1)
      s=s + k/(k+1) ;  
    else
      s=s - k/(k+1) ;
  }  

  /* k has to be float in the above expression. If k is int then s will remain zero  */

  printf("Sum of the required series is %f" , s) ;

  getch() ;
}

/*
Output :

Enter n: 4
Sum of the required series is -0.291667

*/

