/* Factors of a number  -  Program to generate factors of a given number */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , n ;

  clrscr() ;
  printf("Enter the number: ") ;
  scanf("%d" , &n) ;

  printf("Factors of given number are shown below: \n") ;
  for(i=1 ; i<=n ; i++)
    if(n%i==0) 
      printf("%d " , i) ;

  getch();
}

/*
Output1:

Enter the number: 20
Factors of given number are shown below: 
1 2 4 5 10 20 

Output2:

Enter the number: 7
Factors of given number are shown below: 
1 7 
*/

