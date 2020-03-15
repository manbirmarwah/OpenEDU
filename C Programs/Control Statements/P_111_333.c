/* Pattern Problem - Program to generate all combinations of 1 2 3 using for loop. (Eg Print 111(Row 1), (112)(Row 2), (113)(Row 3)...(333)(Last Row)) */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int i , j , k ;

  clrscr() ;

  printf("Required pattern is as follows:\n");

  for(i=1 ; i<=3 ; i++)
    for(j=1 ; j<=3 ; j++)
      for(k=1 ; k<=3 ; k++)
	   printf("%d %d %d \n" , i , j , k) ;
 
  getch();
}

/*
Output:

Required pattern is as follows:
1 1 1 
1 1 2 
1 1 3 
1 2 1 
1 2 2 
1 2 3 
1 3 1 
1 3 2 
1 3 3 
2 1 1 
2 1 2 
2 1 3 
2 2 1 
2 2 2 
2 2 3 
2 3 1 
2 3 2 
2 3 3 
3 1 1 
3 1 2 
3 1 3 
3 2 1 
3 2 2 
3 2 3 
3 3 1 
3 3 2 
3 3 3 
*/