/* Cyclic rotation of array elements - Program to cyclically rotate elements in array. Program should accept a choice that in which direction to rotate - left or right. Suppose array A contains elements {1,2,3,4,5} and if choice is right then o/p should be {5,1,2,3,4} and if choice is left then o/p should be {2,3,4,5,1}  */

#include  <stdio.h>
#include  <conio.h>

void  main()
{
  int  i , n , t , x[50] ;
  char  choice;

  clrscr() ;

  printf("Enter the number of elements: ") ;
  scanf("%d" , &n) ;
  printf("Enter the elements: \n") ;
  for(i=0 ; i<n ; i++)
    scanf("%d" , &x[i]) ;

  printf("Do you want to rotate towards right or left ? \n") ;
  printf("Enter R for right and L for left: ") ;
  scanf(" %c" , &choice) ;

  printf("Original array is as shown: \n") ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
  printf("\n") ;

  if(choice=='R'||choice=='r')
  {
    /* Rotating elements to right */
    t=x[n-1] ;
    for(i=n-1 ; i>=1 ; i--)
      x[i]=x[i-1] ;
    x[0]=t ;
  }
  else if(choice=='L'||choice=='l')
  {
	/* Rotating elements to left */
    t=x[0] ;
    for(i=0 ; i<=n-2 ; i++)
      x[i]=x[i+1] ;
    x[n-1]=t ;
  }
  else
    printf("Wrong choice entered. \n") ;    printf("New array is as shown: \n") ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
  
  getch();
}

/*
Output1:

Enter the number of elements: 4
Enter the elements: 
5 6 7 8
Do you want to rotate towards right or left ? 
Enter R for right and L for left: R
Original array is as shown: 
5 6 7 8 
New array is as shown: 
8 5 6 7 

Output2:
Enter the number of elements: 4
Enter the elements: 
5 6 7 8
Do you want to rotate towards right or left ? 
Enter R for right and L for left: L
Original array is as shown: 
5 6 7 8 
New array is as shown: 
6 7 8 5 

Output3:
Enter the number of elements: 3
Enter the elements: 
1 2 4
Do you want to rotate towards right or left ? 
Enter R for right and L for left: K
Original array is as shown: 
1 2 4 
Wrong choice entered. 
New array is as shown: 
1 2 4 

*/
