/* Median - Calculate median of an array of n numbers */

#include  <stdio.h>
#include  <conio.h>
#include  <math.h>

float  median(int  x[ ] , int  n) ;
void  sort(int  x[ ] , int  n) ;

void main()
{
  int  i , n , x[50] ;

  clrscr();

  printf("Enter the number of elements: ") ;
  scanf("%d" , &n) ;

  printf("Enter the elements: \n") ;
  for(i=0 ; i<n ; i++)
    scanf("%d" , &x[i]) ;

  printf("The median of given numbers is %f" , median(x,n)) ;

  getch();
}

float median(int  x[ ] , int  n)
{
  /* Median of an array is the middle element of sorted array */
  sort(x,n) ;

  /* Condition true if number of elements is odd. In that case return single middle element */
  /* Condition false if number of elements is even. In that case return average of two middle elements */
  if(n % 2 == 1) 
    return (x[n/2]) ;
  else 
    return ( (x[n/2]+x[n/2-1])/2.0 ); /* Dont divide by 2 */
}

void sort(int  x[ ] , int  n)
{
  int  i , j , temp ;
  for(i=0 ; i<n-1 ; i++)
    for(j=0 ; j<n-1-i ; j++)
      if(x[j] > x[j+1])
      {
         temp=x[j] ;
         x[j]=x[j+1] ;
         x[j+1]=temp ;
      }
}

/*
Output1:

Enter the number of elements: 5
Enter the elements: 
2 8 4 9 6
The median of given numbers is 6.000000

Output2:

Enter the number of elements: 6
Enter the elements: 
2 9 4 8 6 7
The median of given numbers is 6.500000
*/




