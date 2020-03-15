/* Sorting (Bubble sort) - Program to sort a list (array) of elements in descending order - May 2013 */

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

  sort(x,n) ;  printf("Elements of list in descending order is as shown: \n") ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
 
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

/* If ascending or descending is not mentioned then sort in ascending order. The only change for ascending order will be x[j] > x[j+1] */

/*
Output:

Enter the number of elements: 5
Enter the elements: 
1 3 2 4 5
Elements of list in descending order is as shown: 
5 4 3 2 1 
*/
