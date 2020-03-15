/* Average  -  Calculate sum and average of a list of elements. Also count how many elements in the list are less than average and more than average */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , n , less=0 , more=0 ;
  float  x[50] , sum=0 , avg ;

  clrscr() ;
  printf("Enter the number of elements: ") ;
  scanf("%d" , &n) ;
  printf("Enter the elements: \n") ;
  for(i=0 ; i<n ; i++)
  {
    scanf("%f" , &x[i]) ;
    sum=sum+x[i] ;
  }
  avg=sum/n ;

  printf("Sum of elements in list is: %f \n" , sum) ;
  printf("Average of elements in list is: %f \n" , avg) ;

  for(i=0 ; i<n ; i++)
  {
     if(x[i]>avg)
       more++;        
     if(x[i]<avg)    /* writing else here would be incorrect */
       less++;
  }

  printf("No. of elements more than average is: %d \n" , more) ;
  printf("No. of elements less than average is: %d \n" , less) ;

  getch();
}

/*
Output:

Enter the number of elements: 4
Enter the elements: 
2.1
5.6
3
2.3
Sum of elements in list is: 13.000000 
Average of elements in list is: 3.250000 
No. of elements more than average is: 1 
No. of elements less than average is: 3 

*/

