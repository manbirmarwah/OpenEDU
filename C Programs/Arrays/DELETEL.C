/* Delete element from array - Program to delete all occurences of given number from an array */

#include  <stdio.h>
#include  <conio.h>

void  main()
{
  int  i , key , n , position , flag , x[50] ;

  clrscr() ;

  printf("Enter the number of elements: ") ;
  scanf("%d" , &n) ;
  printf("Enter the elements: \n") ;
  for(i=0 ; i<n ; i++)
    scanf("%d" , &x[i]) ;

  printf("Enter the element to be deleted: ") ;
  scanf("%d" , &key) ;

  position=0;
  do
  {
    flag=0;

    for(i=position ; i<n ; i++)     
      if(x[i]==key)   /* true if element found */
      {
	    position=i ;
	    flag=1 ; 
	    break ;   
      }

    /* Element found at 'position' */
    if(flag==1) 
    {
      for(i=position ; i<n-1 ; i++)
        x[i]=x[i+1];
      n--;
    }
  }
  while(flag==1);

  printf("New array is as shown: \n") ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
 
  getch();
}

/*
Output:

Enter the number of elements: 5
Enter the elements: 
2 4 4 6 4
Enter the element to be deleted: 4
New array is as shown: 
2 6 
*/


