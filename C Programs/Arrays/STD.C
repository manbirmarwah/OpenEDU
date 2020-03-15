/* Standard Deviation - Calculate standard deviation of n numbers */

#include  <stdio.h>
#include  <conio.h>
#include  <math.h>

void  main()
{
  int  i , n , x[50] ;
  float  avg , std , sum = 0 , s = 0 ;

  clrscr() ;

  printf("Enter the number of elements: ") ;
  scanf("%d" , &n) ;

  printf("Enter the elements: \n") ;
  for(i=0 ; i<n ; i++)
  {
    scanf("%d" , &x[i]) ;
    sum=sum+x[i] ;
  }
  avg=sum/n ;

  for(i=0 ; i<n ; i++)
    s = s + pow(x[i]-avg , 2) ;
  std = sqrt(s/n) ;

  printf("The standard deviation of given numbers is %f",std);

  getch();
}

/*
Output:

Enter the number of elements: 6
Enter the elements: 
2 9 1 5 7 4
The standard deviation of given numbers is 2.748737
*/

