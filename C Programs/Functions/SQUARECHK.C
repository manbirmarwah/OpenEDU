/* Square number - Write a function to check whether a given integer is a square number or not. Eg. 4 , 9 , 16 , 25 etc */

#include  <stdio.h>
#include  <conio.h>
#include  <math.h>

int  checksquare(int  n) ;

void main()
{
  int  n , flag ;

  clrscr();

  printf("Enter an integer: ") ;
  scanf("%d" , &n) ;

  flag=checksquare(n) ;

  if(flag==1)
	printf("%d is a square number" , n) ; 
  else
	printf("%d is not a square number" , n) ;
	
  getch();
}

int  checksquare(int  n)
{
  double  m;  		  
  int  a;

  m=sqrt(n);		  
  a=m;

  if(n==a*a)
	return  1;
  else
	return  0;
}

/*
Output1:

Enter an integer: 16
16 is a square number

Output2:

Enter an integer: 8
8 is not a square number
*/

