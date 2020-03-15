/* Sum of series - Program to calculate sum of series 1 - x^2/2! + x^4/4! - x^6/6! + x^8/8! - ... */

#include  <stdio.h>
#include  <math.h>
#include  <conio.h>

long  fact(int  n) ;

void  main()
{
  int  i , k , n ;
  float  x , sum=0 ;
 
  clrscr() ;
 
  printf("Enter the number of terms: ") ;
  scanf("%d" , &n) ;

  printf("Enter the value of x: ") ;
  scanf("%f" , &x) ;


  /* i keeps track of term count , whereas k is used for calculation purpose */
  for(i=1 , k=0 ; i<=n ; i++ , k=k+2)
  {
    if(i%2==1)
      sum = sum + pow(x,k)/fact(k) ;  
    else
      sum = sum - pow(x,k)/fact(k) ;
  }  

  printf("Sum of the required series is %f" , sum) ;

  getch() ;
}

long fact(int  n)
{
  int  i ;
  long f=1;

  for(i=1 ; i<=n ; i++)
    f=f*i ;

  return  f ;
}

/*
Output1 :

Enter the number of terms: 1
Enter the value of x: 8
Sum of the required series is 1.000000

Output2:

Enter the number of terms: 4
Enter the value of x: 2
Sum of the required series is -0.422222

Output3:

Enter the number of terms: 3
Enter the value of x: 5
Sum of the required series is 14.541667
*/




