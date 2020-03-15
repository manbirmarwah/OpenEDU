/* Delete duplicate array elements - Program to delete all the duplicate values from a given array */

#include  <stdio.h>
#include  <conio.h>

void  main()
{
  int  i , j , k , m , n , x[50] ;

  clrscr() ;

  printf("Enter the number of elements: ") ;
  scanf("%d" , &n) ;
  printf("Enter the elements: \n") ;
  for(i=0 ; i<n ; i++)
    scanf("%d" , &x[i]) ;

  printf("Original array is as shown: \n") ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
  printf("\n") ;

  /* Removing duplicates */
  m=n ;
  for(i=0 ; i<n-1 ; i++)     
    for(j=i+1 ; j<m ; j++)     
      if(x[i]==x[j]) /* true if duplicate found */
      {
	    for(k=j+1 ; k<m ; k++)    
          x[k-1]=x[k] ;
	    m-- ;
      }

  /* At this stage, array length is m not n */  printf("New array with no duplicates is as shown: \n") ;
  for(i=0 ; i<m ; i++)
    printf("%d " , x[i]) ;
 
  getch();
}

/*
Output1:

Enter the number of elements: 8
Enter the elements: 
2 1 4 2 9 6 4 5
Original array is as shown: 
2 1 4 2 9 6 4 5 
New array with no duplicates is as shown: 
2 1 4 9 6 5 

Output2:

Enter the number of elements: 4
Enter the elements: 
2 8 4 5
Original array is as shown: 
2 8 4 5 
New array with no duplicates is as shown: 
2 8 4 5 
*/
