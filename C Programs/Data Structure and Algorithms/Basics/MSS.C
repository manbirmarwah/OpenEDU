/* Program to solve maximum subsequence sum problem  */

#include  <stdio.h>
#include  <conio.h>

int  sum(int  x[] , int  n) ;

void  main()
{
  int  i , n , x[20] , s ;

  clrscr() ;

  printf("Enter the number of elements: ") ;
  scanf("%d",&n) ;
  printf("Enter the elements:\n") ;
  for(i=0;i<n;i++)
    scanf("%d",&x[i]) ;

  s=sum(x,n) ;

  printf("Sum is: %d",s) ;
 
  getch() ;
}

int  sum(int  x[] , int  n)
{
 int  sum , maxsum , k ;

 sum=maxsum=0 ;
 for(k=0 ; k<n ; k++)
 {
   sum = sum + x[k] ;

   if(sum>maxsum) 
     maxsum=sum ;
   else if(sum<0)
     sum=0 ;
  }

  return  maxsum ; 
}

