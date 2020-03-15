/* Cosine Series - Program to find cos(x) using the series: cos(x) = 1 - (x^2) / 2! + (x^4) / 4! - (x^6) / 6! + .... Do calculations till the value of the next term is not lesser than 10^-5  */

/* We assume that the angle entered by user is between 0 and 2 pi radians (0 and 360 degrees) */

#include  <stdio.h>
#include  <conio.h>
#define  pi  3.141593

void main()
{
  double  d , x , i=0 , s=0 , f=1 , num , nt;
  int  tc=1 ;
  /* s-sum , f-factorial , num - nemerator , nt - next term , tc - term count */

  clrscr() ;

  printf("Enter the angle in degrees: ") ;
  scanf("%lf" , &d) ;

  x=d*pi/180 ; /* converts angle to radians */
  num=1 ;

  while(1)
  {
     f=f*i*(i-1) ;  /* Calculates factorial */
     if(f==0)
       f=1 ;

     nt=num/f ;      /* calculates next term */

     if(nt<0.00001)
       break  ;  /* stops if next term is less than 10 raise to -5 */

     if(tc%2==1)  /* alternating + and - */
       s=s+nt ;        /* calculates sum*/
     else
       s=s-nt ;

     /* Preparation for next execution */
     i=i+2 ;
     tc++ ;
     num=num*x*x ;
  }
  printf("The cosine of angle %lf is %lf" , d , s) ;

  getch() ;
}

/*
Output

Enter the angle in degrees: 60
The cosine of angle 60.000000 is 0.500000
*/
