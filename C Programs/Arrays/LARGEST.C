/* LARGEST SMALLEST - Program to find the largest , second largest and smallest element in an array of integers */

#include  <stdio.h>
#include  <conio.h>

void  sort(int  x[ ] , int  n);

void  main()
{
  int  i , n , x[50] ;

  clrscr() ;

  printf("Enter the number of elements: ") ;
  scanf("%d" , &n) ;
  printf("Enter the elements: \n") ;
  for(i=0 ; i<n ; i++)
    scanf("%d" , &x[i]) ;

  sort(x,n) ;  /* At this stage, array is sorted in descending order*/
  printf("Largest element is %d \n" , x[0]) ;
  printf("Second Largest element is %d \n" , x[1]) ;
  printf("Smallest element is %d \n" , x[n-1]) ;

  getch() ;
}

void sort(int  x[ ] , int  n)
{
  int  i , j , temp ;
  for(i=0 ; i<n-1 ; i++)
    for(j=0 ; j<n-1-i ; j++)
      if(x[j] < x[j+1])
      {
         temp=x[j] ;
         x[j]=x[j+1] ;
         x[j+1]=temp ;
      }
}


/*
Output:

Enter the number of elements: 7
Enter the elements: 
4 2 8 6 1 5 7
Largest element is 8 
Second Largest element is 7 
Smallest element is 1 
*/
