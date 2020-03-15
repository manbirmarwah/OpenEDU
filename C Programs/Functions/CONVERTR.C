/* Decimal to Octal , Hexa , Binary - Using recursion write a program to find octal , binary and hexadecimal equivalent of the natural (decimal) number entered by the user */

#include  <stdio.h>
#include  <conio.h>

void  octal(int  n)
{
  if(n!=0)
  {
     octal(n/8) ;
     printf("%d" , n%8) ;  
  }
}

void  binary(int  n)
{
  if(n!=0)  
  {
     binary(n/2) ;
     printf("%d" , n%2) ;
  }
}

void  hexa(int  n)
{
  if(n!=0)  
  {
     hexa(n/16) ;

     if(n%16 < 10)
       printf("%d" , n%16) ;
     else
       printf("%c" , n%16 + 55) ;
  }
}

void main()
{
  int  n ;

  clrscr() ;

  printf("Enter a natural number: ") ;
  scanf("%d" , &n) ;

  printf("Equivalent octal, binary and hexadecimal numbers are as shown: \n") ;

  octal(n) ;
  printf("\n") ;

  binary(n) ;  printf("\n") ;
  hexa(n) ;
  printf("\n") ;

  getch() ;
}

/*
Output:

Enter a natural number: 43
Equivalent octal, binary and hexadecimal numbers are as shown: 
53
101011
2B
*/
